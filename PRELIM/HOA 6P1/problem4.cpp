#include <iostream>
#include "searchingAlgo.h"

int main(){
    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    std::cout << "Finding key " << key << "\n\n";
    std::cout << "List (indices 0-9): 3 5 6 8 11 12 14 15 17 18\n\n";

    binarySearchArrRecursive(sortedList, 0, size - 1, key);

    return 0;
}
