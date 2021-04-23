#include <program_benchmark.h>

ProgramBenchmark::~ProgramBenchmark() {}

int ProgramBenchmark::Run() {
  if (arg_.size() == 1 || arg_.size() == 2) {
    ShowUsage();
    return -1;
  }

  size_t max_rcl, max_iterations;
  if (arg_[3] == "GRASP" && arg_.size() < 10) {
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
  } else {
    // Caso GVNS
    header = {"k", "iteraciones", "tct", "tiempo / segundos"};
    max_rcl = (size_t)stoi(arg_[4]);
    size_t max_k = (size_t)stoi(arg_[9]);
    max_iterations = (size_t)stoi(arg_[7]);
    for (size_t k = 2; k < max_k; ++k) {
      for (size_t iterations = 10; iterations <= max_iterations; iterations *= 10) {
        local_seach = GetLocalSearch(arg_[5]);
        stop_condition = GetStopCondition(arg_[6], iterations);
        InitLocalSearches();
        vnd = new Vnd(local_searches);
        gvns = new Gvns(k, local_seach, vnd);
        algorithm = new GraspPms(max_rcl, stop_condition, local_seach, gvns);
  
        ProblemPms problem(arg_[2], algorithm);
        timer.Play();
        problem.Solve();
        timer.Stop();
        data.push_back({std::to_string(k), std::to_string(iterations),
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
               "iteraciones máximas> irá en potencias de 10 hasta el tamañado dado\n"
            << "      - GVNS: <GNVS> <tamaño-k>\n\n";
}