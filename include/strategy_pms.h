#ifndef STRATEGY_PMS_H
#define STRATEGY_PMS_H

#include <iostream>
#include <vector>

/**
 * @brief Clase interfaz para poder realizar el patrón estrategia dentro
 * del problam PSM
 */
class StrategyPms {
 public:
  virtual ~StrategyPms();

  /**
   * @brief Interfaz de la función que podrá resolver el problema PMS
   * @param machines Número de máquinas
   * @param setup_times_ Tiempos de preparación
   * @param process_times Tiempo de ejecución de cada proceso
   * @return std::vector<std::vector<int>>  Vector resultante que indica que
   * procesos ejecutó cada máquina
   */
  virtual std::vector<std::vector<int>> Solve(
      size_t machines, const std::vector<std::vector<int>>& setup_times_,
      const std::vector<int>& process_times) = 0;
};

#endif