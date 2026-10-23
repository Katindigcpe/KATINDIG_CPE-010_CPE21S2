#include <iostream>
#include "searchingAlgo.h"

int main(){
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;

    //  ARRAY APPROACH 
    std::cout << "-- Array approach --\n";
    int arrCount18 = countOccurrencesArr(list, size, 18);
    std::cout << "Key 18 appears " << arrCount18 << " time(s) in the array\n";

    // A couple more keys from the same list, to show the function generalizes
    std::cout << "Key 19 appears " << countOccurrencesArr(list, size, 19) << " time(s) in the array\n";
    std::cout << "Key 14 appears " << countOccurrencesArr(list, size, 14) << " time(s) in the array\n";
    std::cout << "Key 15 appears " << countOccurrencesArr(list, size, 15) << " time(s) in the array\n\n";

    //  LINKED LIST APPROACH 
    std::cout << "-- Linked list approach --\n";
    Node<int>* head = new_node(list[0]);
    Node<int>* current = head;
    for(int i = 1; i < size; i++){
        current->next = new_node(list[i]);
        current = current->next;
    }

    int llCount18 = countOccurrencesLL(head, 18);
    std::cout << "Key 18 appears " << llCount18 << " time(s) in the linked list\n";
    std::cout << "Key 19 appears " << countOccurrencesLL(head, 19) << " time(s) in the linked list\n";
    std::cout << "Key 14 appears " << countOccurrencesLL(head, 14) << " time(s) in the linked list\n";

    return 0;
}
