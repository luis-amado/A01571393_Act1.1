/* =======================================
Actividad 1.1
Algoritmo de ordenamiento merge sort

Autor: Luis Adrian Amado Alvarez A01571393
Fecha de creacion: 11/08/2024
Ultima modificacion: 15/08/2024
========================================*/

#include <iostream>
#include <vector>

#include <algorithm>

// Funcion recursiva para el algoritmo divide y venceras
// Divide el arreglo en 2 subarreglos y luego los junta en orden
// Entradas: El vector de numeros, indice de inicio del subarreglo, 
//   indice final del subarreglo y un espacio de memoria temporal para juntar los subarreglos
// Salidas: Ninguna
// Complejidad 
//   temporal: O(n log n) *todos los casos
//   espacial: O(n)
void mergeSortRecursive(std::vector<double>& nums, int start, int end, std::vector<double>& buffer) {

  // Un subarreglo de un elemento ya esta en orden
  if (start == end) {
    return;
  }

  // Dividir el subarreglo en otros 2 subarreglos por la mitad
  int midpoint = (start + end) / 2;
  mergeSortRecursive(nums, start, midpoint, buffer);
  mergeSortRecursive(nums, midpoint + 1, end, buffer);

  // Copiar el subarreglo al espacio temporal
  for (int i = start, bufIndex = 0; i <= end; i++, bufIndex++) {
    buffer[bufIndex] = nums[i];
  }

  // Combinar los 2 subarreglos utilizando dos indices
  int left = 0;
  int right = (end - start) / 2 + 1;
  int maxLeft = right - 1;
  int maxRight = end - start;
  for (int i = start; i <= end; i++) {
    // Elije el siguiente valor mas grande
    if ((left <= maxLeft && buffer[left] > buffer[right]) || right > maxRight) {
      nums[i] = buffer[left];
      left++;
    } else {
      nums[i] = buffer[right];
      right++;
    }
  }
}

// Funcion que ordena un vector de numeros flotantes (double)
// Utiliza el metodo de merge sort
// Entrada: El vector a ordenar (se ordena en este mismo vector)
// Salidas: Ninguna
// Complejidad 
//   temporal: O(n log n) *todos los casos
//   espacial: O(n)
void mergeSort(std::vector<double>& nums) {

  // Un arreglo de 1 elemento o menos ya esta en orden
  if (nums.size() <= 1) {
    return;
  }

  // Crear un espacio de memoria con el mismo tamano que el vector original
  std::vector<double> buffer(nums.size());

  // Llamar la funcion recursiva, tomando todo el vector como el primer subarreglo
  mergeSortRecursive(nums, 0, nums.size() - 1, buffer);
}

int main() {
  // Obtener un arreglo de numeros del usuario
  int N;
  std::cout << "Ingresa la cantidad de numeros: ";
  std::cin >> N;

  std::vector<double> nums(N);

  std::cout << "Ingresa los numeros:\n";
  for (int i = 0; i < N; i++) {
    std::cin >> nums[i];
  }

  // Ordenar los numeros
  mergeSort(nums);

  // Mostrar los numeros ordenados
  std::cout << "\nNumeros ordenados: ";
  for (int i = 0; i < N; i++) {
    std::cout << nums[i] << ' ';
  }
  std::cout << '\n';
}