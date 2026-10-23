#ifndef SUPPALGO_H
#define SUPPALGO_H
#include <cstddef>

template <typename T>
int routineSmallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallestElem = arr[K];

    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize) {
    int pos;
    T temp;

    for (size_t i = 0; i < arrSize; i++) {
        pos = routineSmallest(arr, i, arrSize);
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

#endif
