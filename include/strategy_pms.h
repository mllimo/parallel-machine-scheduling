#ifndef STRATEGY_PMS_H
#define STRATEGY_PMS_H

#include <machine.h>
#include <iostream>
#include <limits>
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
   * @param jobs_times Tiempo de ejecución de cada proceso
   * @return std::vector<std::vector<int>>  Vector resultante que indica que
   * procesos ejecutó cada máquina
   */
  virtual std::vector<Machine> Solve(
      size_t machines, std::vector<std::vector<int>>& setup_times_,
      std::vector<int>& jobs_times) = 0;
};

#endif