#include <program_pms.h>

ProgramPms::~ProgramPms() {}

int ProgramPms::Run() {
  if (arg_.size() <= 2) {
    ShowUsage();
    return 1;
  }

  if (arg_[2] == "GRASP") {
    local_seach = GetLocalSearch(arg_[4]);
    stop_condition = GetStopCondition(arg_[5], (size_t)stoi(arg_[6]));
    algorithm = new GraspPms((size_t)stoi(arg_[3]), stop_condition, local_seach);
  } else {
    algorithm = GetStrategy(arg_[2]);
  }

  ProblemPms problem(arg_[1], algorithm);
  timer.Play();
  problem.Solve();
  timer.Stop();
  std::cout << problem << std::endl;
  std::cout << "Tiempo: " << timer.Get() << "s" << std::endl;

  return 0;
}

StrategyPms* ProgramPms::GetStrategy(const std::string& algorithm) {
  static std::map<std::string, std::function<StrategyPms*(void)>> algorithm_map = {
      {"GREEDY", []() -> StrategyPms* { return new GreedyPms(); }},
      {"MY-GREEDY", []() -> StrategyPms* { return new MyGreedyPms(); }},
  };
  auto it = algorithm_map.find(algorithm);
  if (it == algorithm_map.end()) return NULL;
  return it->second();
}

LocalSearch* ProgramPms::GetLocalSearch(const std::string& local_search) {
  static std::map<std::string, std::function<LocalSearch*(void)>> local_map = {
      {"intercambio-entre", []() -> LocalSearch* { return new SwapEntre(); }},
      {"intercambio-intra", []() -> LocalSearch* { return new SwapIntra(); }},
      {"reinsertar-entre", []() -> LocalSearch* { return new ReinsertEntre(); }},
      {"reinsertar-intra", []() -> LocalSearch* { return new ReinsertIntra(); }},
      {"ninguno", []() -> LocalSearch* { return NULL; }},
  };
  auto it = local_map.find(local_search);
  if (it == local_map.end()) std::cerr << "Mala entrada para la busqueda local\n";
  return it->second();
}

StopCondition* ProgramPms::GetStopCondition(const std::string& stop_condition, size_t iterations) {
  static std::map<std::string, std::function<StopCondition*(void)>> stop_map = {
      {"max-iteraciones", [=]() -> StopCondition* { return new StopMaxIteration(iterations); }},
      {"max-no-mejora", [=]() -> StopCondition* { return new StopNoImprovement(iterations); }},
  };
  auto it = stop_map.find(stop_condition);
  if (it == stop_map.end()) std::cerr << "Mala entrada de condición de parada\n";
  return it->second();
}

void ProgramPms::ShowUsage() const {
  std::cout << "Forma de uso: ./pms <fichero-datos> <GREEDY|MY-GREEDY|GRASP> <grasp argumentos>"
            << std::endl;
  std::cout
      << "  - <fichero-datos>: Fichero que contiene los datos del problema\n"
      << "  - <GREEDY|MY-GREEDY|GRASP>: Algoritmo a utlizar\n"
      << "    * GRASP: En caso de que elija el algoritmo de GRAPS tendrá que declarar los "
         "siguientes argumentos\n"
      << "      - Tamaño RCL: número entero positivo\n"
      << "      - Busquedas locales: "
         "<intercambio-entre|intercambio-intra|reinsertar-entre|reinsertar-intra|ninguno>\n"
      << "      - Condición de parada: <max-iteraciones|max-no-mejora> <número de iteraciones>\n\n";
}