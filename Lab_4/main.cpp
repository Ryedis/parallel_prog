#include "matrix.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {


    int blockSize = std::atoi(argv[1]);
    std::string inputFile = (argc >= 3) ? argv[2] : "test.txt";

    std::cout << blockSize << "\n";

    Matrix A;
    auto start = std::chrono::high_resolution_clock::now();

    if (!A.loadFromFile(inputFile)) {
        return 1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Read time: "
        << std::chrono::duration<double>(end - start).count()
        << " s\n";
    std::cout << "Init matrix size: " <<A.N <<" \n" ;

    start = std::chrono::high_resolution_clock::now();
    Matrix C_gpu = A.gpu_dot(A, blockSize, blockSize);
    end = std::chrono::high_resolution_clock::now();

    std::cout << "GPU time: "
        << std::chrono::duration<double>(end - start).count()
        << " s\n";
    return 0;
}
