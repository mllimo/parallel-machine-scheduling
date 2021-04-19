#ifndef STOP_CONDITION_H
#define STOP_CONDITION_H

#include <iostream>
class GraspPms;

class StopCondition {
 public:
  virtual ~StopCondition();
  /**
   * @brief Dada una implementación intenta marcar una condición de parada
   * para el algoritmo de GRASP
   * @param context Algoritmo de Graps en el cual se está utilizando la condición
   * @return true Se para el algoritmo
   * @return false No se para el algoritmo
   */
  virtual bool operator()(GraspPms* context) = 0;
};

#endif