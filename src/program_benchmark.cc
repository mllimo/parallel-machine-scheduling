#include <program_benchmark.h>

ProgramBenchmark::~ProgramBenchmark() {}

int ProgramBenchmark::Run() {
  if (arg_.size() == 1 || arg_.size() == 2) {
    ShowUsage();
    return -1;
  }

  size_t max_rcl, max_iterations;
  if (arg_[3] == "GRASP") {
    header = {"RCL", "iteraciones", "tct", "tiempo / segundos"};
    max_rcl = (size_t)stoi(arg_[4]);
    max_iterations = (size_t)stoi(arg_[7]);

    for (size_t rcl = 2; rcl < max_rcl; ++rcl) {
      for (size_t iterations = 10; iterations <= max_iterations; iterations *= 10) {
        local_seach = GetLocalSearch(arg_[5]);
        stop_condition = GetStopCondition(arg_[6], iterations);
        algorithm = new GraspPms(rcl, stop_condition, local_seach);
        ProblemPms problem(arg_[2], algorithm);
        timer.Play();
        problem.Solve();
        timer.Stop();
        data.push_back({std::to_string(rcl), std::to_string(iterations),
                        std::to_string(problem.Tct()), std::to_string(timer.Get())});
      }
    }
  }
  Export();
  return 0;
}

void ProgramBenchmark::Export() {
  std::string file_name =
      std::string(arg_[2].begin(), arg_[2].begin() + arg_[2].size() - 3) + "csv";
  std::fstream file(file_name, std::ios_base::out);
  std::cout << "Exportando en: " << file_name << std::endl;

  // Imprimir cabeceras
  for (auto& element : header) file << element << ",";
  file << '\n';

  // Imprimir info
  for (auto& row : data) {
    for (auto& value : row) file << value << ",";
    file << '\n';
  }

  file.close();
}

void ProgramBenchmark::ShowUsage() const {
  std::cout << "Forma de uso: ./pms -t <fichero-datos> <GRASP> <grasp argumentos>" << std::endl;
  std::cout << "  - -t: Indica que se activará el modo benchmark\n"
            << "  - <fichero-datos>: Fichero que contiene los datos del problema\n"
            << "  - <GRASP>: Algoritmo a utlizar\n"
            << "    * GRASP: En caso de que elija el algoritmo de GRAPS tendrá que declarar los "
               "siguientes argumentos\n"
            << "      - Tamaño RCL: Máximo tamaño RCL. Partirá de 2-RCL\n"
            << "      - Busquedas locales: "
               "<intercambio-entre|intercambio-intra|reinsertar-entre|reinsertar-intra|ninguno>\n"
            << "      - Condición de parada: <max-iteraciones|max-no-mejora> <número de "
               "iteraciones máximas> irá en potencias de 10 hasta el tamañado dado\n";
}

// Código redundante -> refactorizar
LocalSearch* ProgramBenchmark::GetLocalSearch(const std::string& local_search) {
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

StopCondition* ProgramBenchmark::GetStopCondition(const std::string& stop_condition,
                                                  size_t iterations) {
  static std::map<std::string, std::function<StopCondition*(void)>> stop_map = {
      {"max-iteraciones", [=]() -> StopCondition* { return new StopMaxIteration(iterations); }},
      {"max-no-mejora", [=]() -> StopCondition* { return new StopNoImprovement(iterations); }},
  };
  auto it = stop_map.find(stop_condition);
  if (it == stop_map.end()) std::cerr << "Mala entrada de condición de parada\n";
  return it->second();
}
