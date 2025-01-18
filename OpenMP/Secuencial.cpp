//Producto Escalar de un Vector 
////Ejemplo 1 OpenMP - Ejecución Sin Paralelismo (Secuencial)
//Autor: Heryd Xavier Morla Gordillo
//Curso: SOF-S-NO-9-2
//Materia: Aplicaciones Distribuidas
//Grupo: II Parcial - GRUPO E
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 1000000;
    std::vector<double> vecA(N, 1.5);
    std::vector<double> vecB(N, 2.0);
    double dot_product = 0.0;

    double start = omp_get_wtime();

    // Calcular el producto escalar secuencialmente
    for (int i = 0; i < N; i++) {
        dot_product += vecA[i] * vecB[i];
    }

    double end = omp_get_wtime();

    // Imprimir resultados
    std::cout << "Producto escalar (Secuencial): " << dot_product << std::endl;
    std::cout << "Tiempo de ejecuciÃ³n: " << (end - start) << " segundos" << std::endl;

    return 0;
}

