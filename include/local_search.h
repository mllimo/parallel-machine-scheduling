#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include <machine.h>

class LocalSearch {
 public:
  virtual ~LocalSearch();
  /**
   * @brief Encuentra de forma Greedy la mejor solución en base a una busqueda local
   * @param solution Solución partcial que se irá mejorando tras la búsqueda
   */
  virtual void operator()(std::vector<Machine>& solution) = 0;

  /**
   * @brief Dado un valor K genera N pasos dentro de la busqueda y lo 
   * iguala al parámetro solución
   * @param solution solución parcial
   * @param k Número de pasos
   */
  virtual void operator()(std::vector<Machine>& solution, size_t k) = 0;

 protected:
  /**
   * @brief Actualiza el parámetro best_solution si solución es menor
   * @param best_solution Mejor solución de la búsqueda
   * @param solution Solución parcial
   */
  void UpdateSolution(std::vector<Machine>& best_solution, std::vector<Machine>& solution);
};

#endif