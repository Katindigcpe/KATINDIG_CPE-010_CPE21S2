#include <iostream>
#include "searchingAlgo.h"

int main(){
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int key = 18;

    //  ARRAY APPROACH 
    std::cout << "-- Array approach --\n";
    int foundIndex;
    int arrComparisons = linearSearchARCount(list, size, key, foundIndex);
    if(foundIndex != -1){
        std::cout << "Key " << key << " found at index " << foundIndex << "\n";
    } else {
        std::cout << "Key " << key << " not found\n";
    }
    std::cout << "Comparisons needed (array): " << arrComparisons << "\n\n";

    //  LINKED LIST APPROACH
    std::cout << "-- Linked list approach --\n";
    Node<int>* head = new_node(list[0]);
    Node<int>* current = head;
    for(int i = 1; i < size; i++){
        current->next = new_node(list[i]);
        current = current->next;
    }

    bool found;
    int llComparisons = linearSearchLLCount(head, key, found);
    std::cout << "Key " << key << (found ? " found in linked list\n" : " not found in linked list\n");
    std::cout << "Comparisons needed (linked list): " << llComparisons << "\n";

    return 0;
}
