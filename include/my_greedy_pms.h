#ifndef MY_GREEDY_PMS_H
#define MY_GREEDY_PMS_H

#include <greedy_pms.h>

class MyGreedyPms : public GreedyPms {
 public:
  MyGreedyPms();
  ~MyGreedyPms();
  std::vector<Machine> Solve(size_t machines,
                             std::vector<std::vector<int>>& setup_times,
                             std::vector<int>& jobs_times);

 protected:
  /**
   * @brief Busca el mejor primer candidato
   * @param setup_times 
   * @param jobs_times 
   * @return size_t 
   */
  size_t GetFirstJob(std::vector<std::vector<int>>& setup_times,
                     std::vector<int>& jobs_times);
  /**
   * @brief Selecciona el candidato con mayor tiempo_proceso / tiempo_preparación
   * @param setup_times 
   * @param jobs_times 
   * @param machine 
   * @return size_t 
   */
  size_t Selection(std::vector<std::vector<int>>& setup_times,
                   std::vector<int>& jobs_times, Machine& machine);
};

#endif