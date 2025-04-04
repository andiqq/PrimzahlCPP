//
//  main.cpp
//  Primzahl7
//
//  Created by Dr. Andreas Plagens on 04.04.25.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

#define MAX_NUMBER_OF_PRIMES 10000000

int main() {
    std::vector<int> primes;
    primes.push_back(2);
    int candidate = 3;

    auto start = std::chrono::high_resolution_clock::now();

    while (primes.size() < MAX_NUMBER_OF_PRIMES) {
        int maxDivisor = static_cast<int>(std::round(std::sqrt(candidate)));
        bool isPrime = true;

        for (int i = 0; i < primes.size(); ++i) {
            if (primes[i] > maxDivisor) break;
            if (candidate % primes[i] == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(candidate);
        }

        candidate += 2;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " seconds\n";

    // Print the primes
//    for (int prime : primes) {
//        std::cout << prime << " ";
//    }
//    std::cout << std::endl;

    return 0;
}
