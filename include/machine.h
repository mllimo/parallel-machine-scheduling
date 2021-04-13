#ifndef MACHINE_H
#define MACHINE_H

#include <algorithm>
#include <iostream>
#include <vector>

class Machine {
 public:
  Machine();
  Machine(std::vector<int>* jobs_times,
          std::vector<std::vector<int>>* setup_times);

  /**
   * @brief Inserta el ínidice del proceso
   * @param jobs_index El proceso
   * @return true Si se pudo insertar
   * @return false Si no se pudo insertar
   */
  bool Insert(int jobs_index);

  /**
   * @brief Intenta encontrar el proceso dentro del conjunto de procesos de la
   * máquina
   * @param jobs_index Proceso a buscar
   * @return true Si lo encontró
   * @return false Si no lo encontró
   */
  bool Find(int jobs_index) const;

  /**
   * @brief Devuelve el TCT de la máquina
   * @return size_t TCT de la máquina
   */
  size_t TotalTime() const;

  /**
   * @brief Devuelve cual fue el último indice insertado
   * @return int
   */
  int LastInserted() const;

  /**
   * @brief Devuelve el conjunto de procesos que han sido ejecutados en la
   * máquina
   * @return const std::vector<int>&
   */
  const std::vector<int>& Jobs() const;

  friend std::ostream& operator<<(std::ostream& os, const Machine& machine);

 private:
  int last_inserted_;
  std::vector<int> jobs_;
  size_t total_time_;
  std::vector<int>* jobs_times_;
  std::vector<std::vector<int>>* setup_times_;
};

#endif