#include <my_greedy_pms.h>

MyGreedyPms::MyGreedyPms() {}

MyGreedyPms::~MyGreedyPms() {}

std::vector<Machine> MyGreedyPms::Solve(
    size_t machines, std::vector<std::vector<int>>& setup_times,
    std::vector<int>& jobs_times) {
  // Vector de soluciones
  std::vector<Machine> result(machines, Machine(&jobs_times, &setup_times));
  // Vector de candidatos
  std::vector<bool> is_executed(jobs_times.size(), false);
  // Inicializamos nuestras maquinas
  for (auto& machine : result)
    machine.Insert(GetFirstJob(setup_times, jobs_times, is_executed));
  // Mientras no hayamos procesado todos los trabajos
  while (!AllVisited(is_executed)) {
    // Seleccionar el que tenga mejor proporcion tiempo_proceso / tiempo
    for (auto& machine : result)
      machine.Insert(Selection(setup_times, jobs_times, is_executed, machine));
  }
  return result;
}

size_t MyGreedyPms::GetFirstJob(std::vector<std::vector<int>>& setup_times,
                                std::vector<int>& jobs_times,
                                std::vector<bool>& is_executed) {
  size_t index;
  float proportion;
  // Cuan mayor sea la proporcion mejor
  float max_proportion = std::numeric_limits<float>::min();
  for (size_t i = 0; i < jobs_times.size(); ++i) {
    proportion = (float)jobs_times[i] / (float)setup_times[0][i + 1];
    if (proportion > max_proportion && !is_executed[i]) {
      max_proportion = proportion;
      index = i;
    }
  }
  is_executed[index] = true;
  return index;
}

size_t MyGreedyPms::Selection(std::vector<std::vector<int>>& setup_times,
                              std::vector<int>& jobs_times,
                              std::vector<bool>& is_executed,
                              Machine& machine) {
  size_t index;
  float proportion;
  float max_proportion = std::numeric_limits<float>::min();
  for (size_t i = 0; i < jobs_times.size(); ++i) {
    if (is_executed[i] || machine.LastInserted() + 1 == i + 1) continue;
    proportion = (float)jobs_times[i] / (float)setup_times[machine.LastInserted() + 1][i + 1];
    if (proportion > max_proportion) {
      max_proportion = proportion;
      index = i;
    }
  }
  is_executed[index] = true;
  return index;
}

bool MyGreedyPms::AllVisited(const std::vector<bool>& visited) const {
  for (const auto& element : visited)
    if (element == false) return false;
  return true;
}