#include "modules/LinearSearch.h" // O(n)
#include "modules/SelectionSort.h" // O(n^2)
#include "modules/MergeSort.h" // O(nlog(n))
#include "modules/BinarySearch.h" // O(log(n))
#include "modules/Fibonacci.h" // recursive O(2^n)


#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int* generate_array(int max_size){
    int* arr = new int[max_size];
    // Random number generation
    random_device rd;  // Seed for the random number engine
    mt19937 gen(rd()); // Mersenne Twister random number engine seeded with rd
    std::uniform_int_distribution<int> distribution(1, 500); // Distribution from 1 to 100
    for (int i=0; i<max_size; i++){
        arr[i] = distribution(gen);
    }
    return arr;
}

int main(){
    int size = 5; // Size to use for testing the algorithms

    int* arr = generate_array(size);

    auto start_time = chrono::high_resolution_clock::now();
    // ------------------------

    // ------------------------
    auto finish_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(finish_time-start_time);

    cout << "\nElapsed time: " << duration.count() << endl;

    return 0;
}