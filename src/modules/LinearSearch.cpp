#include "LinearSearch.h"


int linear_search(int arr[], int size, int search_value){
    for (int i = 0; i < size; i++){
        if (arr[i] == search_value){
            return i;
        }
    }
    return -1;
}