#ifndef GRASP_PMS_H
#define GRASP_PMS_H

#include <greedy_pms.h>

#include <random>

class GraspPms : public GreedyPms {
 public:
  GraspPms();
  GraspPms(size_t lrc_size, size_t max_iteration_no_improvement);
  virtual ~GraspPms();

  virtual std::vector<Machine> Solve(size_t machines,
                                     std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times);

 protected:
  bool is_first_run;
  size_t lrc_size;
  size_t max_iteration_no_improvement;
  size_t iterations_no_improvement;

  /**
   * @brief Selecciona aleatoriamente un candidato entre los mejores
   * @param rcl Mejores N candidatos hasta el momento
   * @return size_t
   */
  size_t SelectionRandom(std::vector<int>& rcl);

  /**
   * @brief Función que escoge los N mejores candidatos
   * @param jobs_times
   * @return std::vector<int> Los N mejores candidatos
   */
  std::vector<int> MakeRcl(std::vector<int>& jobs_times, Machine& machine);

  /**
   * @brief Fase constructiva de GRASP
   * @param machines
   * @param jobs_times
   */
  void Construct(std::vector<Machine>& machines, std::vector<int>& jobs_times);

  void UpdateSolution(std::vector<Machine>& actua_solution,
                      std::vector<Machine>& best_solution);
};

#endif