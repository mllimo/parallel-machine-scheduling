#ifndef GRASP_PMS_H
#define GRASP_PMS_H

#include <strategy_pms.h>

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

  size_t Selection(std::vector<std::vector<int>>& setup_times,
                   std::vector<int>& jobs_times, Machine& machine);
  /**
   * @brief Función que escoge los N mejores candidatos
   * @param setup_times
   * @param jobs_times
   * @return std::vector<int> Los N mejores candidatos
   */
  std::vector<int> MakeRcl(std::vector<std::vector<int>>& setup_times,
                           std::vector<int>& jobs_times,
                           Machine& machine);

  /**
   * @brief Fase constructiva de GRASP
   * @param machines
   * @param setup_times
   * @param jobs_times
   * @return std::vector<Machine>
   */
  std::vector<Machine> Construct(size_t machines,
                                 std::vector<std::vector<int>>& setup_times,
                                 std::vector<int>& jobs_times);
};

#endif