#ifndef GRASP_PMS_H
#define GRASP_PMS_H

#include <strategy_pms.h>

#include <random>

class GraspPms : public StrategyPms {
 public:
  GraspPms();
  GraspPms(size_t lrc_size);
  virtual ~GraspPms();

  virtual std::vector<Machine> Solve(size_t machines,
                                     std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times);

 protected:
  std::vector<bool> is_executed;
  size_t lrc_size;

  bool AllVisited(const std::vector<bool>& visited) const;

  int GetMinNotExecuted(const std::vector<int>& jobs_times,
                        const std::vector<std::vector<int>>& setup_times);

  /**
   * @brief Selecciona el mejor candidato hasta el momento. id de proceso
   * @param jobs_times
   * @param machine
   * @return size_t
   */
  size_t Selection(std::vector<int>& jobs_times, Machine& machine);

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
};

#endif