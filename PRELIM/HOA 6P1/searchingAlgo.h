#include <iostream>
#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H


// reference

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    for(int i = 0; i < size; i++){
        if(dataFind == array[i]){
            std::cout << "Searching is successful\n";
            return;
        }
    }
    std::cout << "Searching is unsuccessful\n";
}


// reference

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    while(nodes != nullptr){
        if(nodes->data == dataFind){
            std::cout << "The data: " << nodes->data << " was found successfully.\n";
            return;
        }
        nodes = nodes->next;
    }
    std::cout << "Searching is unsuccessful.\n";
}

// PROBLEM 1

template <typename T>
int linearSearchARCount(T array[], int size, T dataFind, int &foundIndex){
    int comparisons = 0;
    for(int i = 0; i < size; i++){
        comparisons++;                      // one comparison happens here
        if(dataFind == array[i]){
            foundIndex = i;
            return comparisons;
        }
    }
    foundIndex = -1;
    return comparisons;
}

template <typename T>
int linearSearchLLCount(Node<T> *nodes, T dataFind, bool &found){
    int comparisons = 0;
    while(nodes != nullptr){
        comparisons++;                      // one comparison happens here
        if(nodes->data == dataFind){
            found = true;
            return comparisons;
        }
        nodes = nodes->next;
    }
    found = false;
    return comparisons;
}


// PROBLEM 2

template <typename T>
int countOccurrencesArr(T array[], int size, T dataFind){
    int occurrences = 0;
    for(int i = 0; i < size; i++){
        if(dataFind == array[i]){
            occurrences++;
        }
    }
    return occurrences;
}

template <typename T>
int countOccurrencesLL(Node<T> *nodes, T dataFind){
    int occurrences = 0;
    while(nodes != nullptr){
        if(nodes->data == dataFind){
            occurrences++;
        }
        nodes = nodes->next;
    }
    return occurrences;
}


// reference

template<typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = (int)((low + high) / 2);
        if(dataFind == data[middle]){
            std::cout << "The data was found\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    std::cout << "The data was not found\n";
}

// PROBLEM 3
template<typename T>
void binarySearchArrVerbose(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    int iteration = 1;

    while(low <= high){
        middle = (int)((low + high) / 2);
        std::cout << "Iteration " << iteration << ": low=" << low
                   << " high=" << high << " middle=" << middle
                   << " -> data[middle]=" << data[middle] << "\n";

        if(dataFind == data[middle]){
            std::cout << "  Match! " << dataFind << " found at index "
                      << middle << "\n";
            std::cout << "The data was found\n";
            return;
        }
        else if(dataFind < data[middle]){
            std::cout << "  " << dataFind << " < " << data[middle]
                      << " -> search LEFT half\n";
            high = middle - 1;
        }
        else{
            std::cout << "  " << dataFind << " > " << data[middle]
                      << " -> search RIGHT half\n";
            low = middle + 1;
        }
        iteration++;
    }
    std::cout << "The data was not found\n";
}
// PROBLEM 4

template<typename T>
bool binarySearchArrRecursive(T data[], int low, int high, T dataFind, int iteration = 1){
    if(low > high){
        std::cout << "The data was not found\n";
        return false;
    }

    int middle = (int)((low + high) / 2);
    std::cout << "Iteration " << iteration << ": low=" << low
               << " high=" << high << " middle=" << middle
               << " -> data[middle]=" << data[middle] << "\n";

    if(dataFind == data[middle]){
        std::cout << "  Match! " << dataFind << " found at index "
                  << middle << "\n";
        std::cout << "The data was found\n";
        return true;
    }
    else if(dataFind < data[middle]){
        std::cout << "  " << dataFind << " < " << data[middle]
                   << " -> search LEFT half\n";
        return binarySearchArrRecursive(data, low, middle - 1, dataFind, iteration + 1);
    }
    else{
        std::cout << "  " << dataFind << " > " << data[middle]
                   << " -> search RIGHT half\n";
        return binarySearchArrRecursive(data, middle + 1, high, dataFind, iteration + 1);
    }
}


// reference

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;
    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    Node<T>* last = nullptr;
    while(start != last){
        Node<T> *middle = getMiddle(start, last);
        if(middle->data == dataFind){
            std::cout << "searching is Successfull\n";
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }
    std::cout << "Searching is unsuccessful\n";
}

#endif
