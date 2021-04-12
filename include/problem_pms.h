#ifndef PROBLEM_PMS_H
#define PROBLEM_PMS_H

#include <strategy_pms.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

/**
 * @brief Clase que encapsulará el comportamiento para poder importar y resolver
 * el problema PSM
 */
class ProblemPms {
 public:
  /**
   * @brief Constructor por parámetros
   * @param file_path Ruta del archivo que contendrá la información del problema
   * @param strategy Estrategia que se utilizará para resolver el problema
   */
  ProblemPms(const std::string& file_path, StrategyPms* strategy);
  ~ProblemPms();

  /**
   * @brief Función que resulve el problema y lo almacena dentro de la clase
   * miembro
   */
  void Solve();

  friend std::istream& operator>>(std::istream& is, ProblemPms& pms);

 protected:
  size_t machines_;
  std::vector<std::vector<int>> setup_times_;
  std::vector<int> processes_times_;
  StrategyPms* algorithm_;
};

#endif