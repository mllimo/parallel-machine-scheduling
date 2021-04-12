#include <problem_pms.h>

ProblemPms::ProblemPms(const std::string& file_path, StrategyPms* strategy) {
  std::ifstream input_file(file_path, std::ios_base::in);
  if (!input_file.is_open()) std::cerr << "No se pudo abrir el archivo\n";
  input_file >> *this;
  algorithm_ = strategy;
}

ProblemPms::~ProblemPms() {
  if (algorithm_) delete algorithm_;
}

void ProblemPms::Solve() {

}

std::istream& operator>>(std::istream& is, ProblemPms& pms) {
  std::string aux;
  size_t process = 0;
  size_t time;

  // Reservar memoria en función del tamaño del problema
  is >> aux >> process;
  pms.process_times_.reserve(process);
  pms.setup_times_.reserve(process);
  is >> aux >> aux;
  pms.machines_ = stoi(aux);
  is >> aux;
  // Tiempos de los procesos
  for (size_t i = 0; i < process; ++i) {
    is >> time;
    pms.process_times_.push_back(time);
  }

  is >> aux;
  // [Proceso terminado][Nuevo proceso] -> Tiempo de setup
  for (size_t i = 0; i < process; ++i) {
    pms.setup_times_.emplace_back();
    pms.setup_times_[i].reserve(process);
    for (size_t j = 0; j < process; ++j) {
      is >> time;
      pms.setup_times_[i].push_back(time);
    }
  }
  return is;
}