#include <problem_pms.h>

ProblemPms::ProblemPms(const std::string& file_path, StrategyPms* strategy) {
  std::ifstream input_file(file_path, std::ios_base::in);
  if (!input_file.is_open()) std::cerr << "No se pudo abrir el archivo\n";
  input_file >> *this;
  algorithm_ = strategy;
  tct_ = 0;
}

ProblemPms::~ProblemPms() {
  if (algorithm_) delete algorithm_;
}

void ProblemPms::Solve() {
  result_ = algorithm_->Solve(machines_, setup_times_, jobs_times_);
  for (auto& machine : result_)
    tct_ += machine.TCT();
}

size_t ProblemPms::Tct() const {
  return tct_;
}

std::istream& operator>>(std::istream& is, ProblemPms& pms) {
  std::string aux;
  size_t jobs = 0;
  size_t time;

  // Reservar memoria en función del tamaño del problema
  is >> aux >> jobs;
  pms.jobs_times_.reserve(jobs);
  pms.setup_times_.reserve(jobs + 1);
  is >> aux >> aux;
  pms.machines_ = stoi(aux);
  is >> aux;
  // Tiempos de los procesos
  for (size_t i = 0; i < jobs; ++i) {
    is >> time;
    pms.jobs_times_.push_back(time);
  }

  is >> aux;
  // [origen][destino] -> Tiempo de setup
  for (size_t i = 0; i < jobs + 1; ++i) {
    pms.setup_times_.emplace_back();
    pms.setup_times_[i].reserve(jobs + 1);
    for (size_t j = 0; j < jobs + 1; ++j) {
      is >> time;
      pms.setup_times_[i].push_back(time);
    }
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, ProblemPms& pms) {
  size_t counter = 1;
  for (auto& machine : pms.result_)
    os << "Maquina " << counter++ << ": " << machine << std::endl;
  os << "TCP: " << pms.tct_;
  return os;
}