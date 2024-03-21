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

void print_arr(int arr[], int n){
    for (int x = 0; x<n; x++){
        cout << arr[x] << " ";
    }
    cout << "\n";
}

int main(){
    int n = 3000; // Size to use for testing the algorithms 
    int fib_n = 40; // Fibonacci total iterations
    int64_t durations[5] = {0};

    // -------------------------------------------{Selection sort}------------------------------------------- //
    int* arr = generate_array(n);
    print_arr(arr, n);

    auto start_time = chrono::high_resolution_clock::now();
    // ------------------------
    selectionSort(arr,n);
    // ------------------------
    auto finish_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(finish_time-start_time);
    durations[1] = duration.count();
    print_arr(arr, n);

    // -------------------------------------------{Linear Search}------------------------------------------- //
    start_time = chrono::high_resolution_clock::now();
    // ------------------------
    if (linear_search(arr, n, 167) == -1){
        cout << "Value not found" << endl;
    }else {
        cout << "Value found" << endl;
    }
    // ------------------------
    finish_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(finish_time-start_time);
    durations[0] = duration.count();
    delete[] arr;

    // -------------------------------------------{Merge sort}------------------------------------------- //

    arr = generate_array(n);
    print_arr(arr, n);
    start_time = chrono::high_resolution_clock::now();
    // ------------------------
    mergeSort(arr, 0, n-1);
    // ------------------------
    finish_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(finish_time-start_time);
    durations[2] = duration.count();
    print_arr(arr, n);

    // -------------------------------------------{Binary search}------------------------------------------- //
    start_time = chrono::high_resolution_clock::now();
    // ------------------------
    if (binarySearch(arr, arr[0] , arr[n-1], 341) == -1){
        cout << "Value not found" << endl;
    }else {
        cout << "Value found" << endl;
    }
    // ------------------------
    finish_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(finish_time-start_time);
    durations[3] = duration.count();
    delete[] arr;

    // -------------------------------------------{Fibonacci recursion}------------------------------------------- //
    start_time = chrono::high_resolution_clock::now();
    // ------------------------
    fib(fib_n);
    // ------------------------
    finish_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(finish_time-start_time);
    durations[4] = duration.count();

    cout << "\nLinear search lasted: " << durations[0] << " microseconds" << endl;
    cout << "\nSelection sort lasted: " << durations[1] << " microseconds" << endl;
    cout << "\nMerge sort lasted: " << durations[2] << " microseconds" << endl;
    cout << "\nBinary search lasted: " << durations[3] << " microseconds" << endl;
    cout << "\nFibonacci recursion lasted: " << durations[4] << " microseconds" << endl;

    return 0;
}