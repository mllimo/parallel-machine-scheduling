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
  Machine(const Machine& machine);

  /**
   * @brief Inserta el ínidice del proceso
   * @param jobs_index El proceso
   */
  void Insert(size_t jobs_index);

  /**
   * @brief Inserta un elemento en la posición dada
   * @param index Posición a indexar el nuevo proceso
   * @param job_index Proceso a indexar
   */
  void Insert(size_t index, size_t job_index);

  /**
   * @brief Intercambia dos indices del vector de procesos
   * @param i Indice
   * @param j Indice
   */
  void SwapIndexex(size_t i, size_t j);

  /**
   * @brief Intenta encontrar el proceso dentro del conjunto de procesos de la
   * máquina
   * @param job_index Proceso a buscar
   * @return true Si lo encontró
   * @return false Si no lo encontró
   */
  bool Find(size_t job_index) const;

  /**
   * @brief Devuelve cual fue el último indice insertado
   * @return size_t
   */
  size_t LastInserted() const;

  /**
   * @brief Devuelve el conjunto de procesos que han sido ejecutados en la
   * máquina
   * @return const std::vector<int>&
   */
  const std::vector<int>& Jobs() const;

  std::vector<int>& Jobs();

  /**
   * @brief Devuelve el TCT actual de los procesos que han sido ejecutados en
   * ella
   */
  size_t TCT() const;

  /**
   * @brief Devuelve el TCT suponiendo que se agrega el proceso dado
   */
  size_t TctWithJob(size_t job) const;

  friend std::ostream& operator<<(std::ostream& os, const Machine& machine);
  friend bool operator<(const Machine& machine1, const Machine& machine2);
  Machine& operator=(const Machine& machine);

 private:
  size_t last_inserted_;
  std::vector<int> jobs_;
  std::vector<int>* jobs_times_;
  std::vector<std::vector<int>>* setup_times_;
};

#endif