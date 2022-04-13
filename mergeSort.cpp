#include <iostream>
using namespace std;

const size_t N = 5; // Change the value of N with the size of the array you want to manipulate

void merge(int arr[], size_t l, size_t m, size_t r) {
    size_t i, j, temp_arr_size;
    i = l;
    j = m+1;
    temp_arr_size = r-l+1;

    int temp_arr[temp_arr_size];

    for (size_t k = 0; k < temp_arr_size; k++) {
        if (i <= m and j <= r) {
            if (arr[i] < arr[j]) {
                temp_arr[k] = arr[i];
                i++;
            }else {
                temp_arr[k] = arr[j];
                j++;
            }
        }else if (i > m and j <= r) {
            temp_arr[k] = arr[j];
            j++;
        }else {
            temp_arr[k] = arr[i];
            i++;
        }
    }
    for (i = l; i < temp_arr_size; i++) {
        arr[i] = temp_arr[i];
    }
}

void mergeSort(int arr[], size_t l, size_t r) {
    size_t m;
    if (l < r) {
        m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
