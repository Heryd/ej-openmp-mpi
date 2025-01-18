//Producto Escalar de un Vector 
////Ejemplo 2 - Ejecución con Paralelismo
//Autor: Heryd Xavier Morla Gordillo
//Curso: SOF-S-NO-9-2
//Materia: Aplicaciones Distribuidas
//Grupo: II Parcial - GRUPO E
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <mpi.h>

int main(int argc, char** argv) {
    const int N = 1000000;
    double local_dot_product = 0.0, global_dot_product = 0.0;
    double start, end;

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk_size = N / size;
    std::vector<double> sub_vecA(chunk_size, 1.5);
    std::vector<double> sub_vecB(chunk_size, 2.0);

    start = MPI_Wtime();

    // Cada proceso calcula su parte del producto escalar
    for (int i = 0; i < chunk_size; i++) {
        local_dot_product += sub_vecA[i] * sub_vecB[i];
    }

    // Reducir los resultados locales al proceso 0
    MPI_Reduce(&local_dot_product, &global_dot_product, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    end = MPI_Wtime();

    // Imprimir resultados (solo el proceso 0)
    if (rank == 0) {
        std::cout << "Producto escalar (Paralelo): " << global_dot_product << std::endl;
        std::cout << "Tiempo de ejecuciÃ³n: " << (end - start) << " segundos" << std::endl;
    }

    MPI_Finalize();
    return 0;
}