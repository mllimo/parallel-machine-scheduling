#ifndef GRASP_PMS_H
#define GRASP_PMS_H

#include <greedy_pms.h>
#include <local_search.h>
#include <stop_condition.h>

#include <random>

class GraspPms : public GreedyPms {
 public:
  std::vector<Machine> actual_solution;
  std::vector<Machine> best_solution;

  GraspPms();
  GraspPms(size_t lrc_size, StopCondition* stop_condition_, LocalSearch* local_search_ = NULL);
  virtual ~GraspPms();

  virtual std::vector<Machine> Solve(size_t machines, std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times);

 protected:
  LocalSearch* local_search;
  class StopCondition* stop_condition;
  size_t lrc_size;

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

  /**
   * @brief Búsqueda local
   * @param solution Solución actual que será actializada en caso de encontrar
   * una mejor
   */
  void Local(std::vector<Machine>& solution);
};

#endif