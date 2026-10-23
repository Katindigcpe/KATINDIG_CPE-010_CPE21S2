#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "suppAlgo.h"

const int maxSize = 100;

void displayArray(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string candidates[5] = {
        "John Michael Dela Cruz",
        "Jane Marie Santos",
        "Mark Anthony Reyes",
        "Luis Miguel Ramos",
        "Anna Patricia Villanueva"
    };
    int votes[maxSize];
    srand(time(0));

    //generate random votes
    for (int i = 0; i < maxSize; i++) {
        votes[i] = (rand() % 5) + 1;
    }

    std::cout << "Unsorted votes: \n";
    displayArray(votes);

    //sort votes
    selectionSort(votes, maxSize);
    std::cout << "\nSorted votes: \n";
    displayArray(votes);

    //count and tally
    int voteCounts[5] = {0};
    int winnerIndex = 0;

    for (int i = 0; i < maxSize; i++) {
        voteCounts[votes[i] - 1]++;
    }

    std::cout << "\nVote total: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << " (" << candidates[i]
                  << "): " << voteCounts[i] << " votes\n";

        if (voteCounts[i] > voteCounts[winnerIndex]) {
            winnerIndex = i;
        }
    }
    std::cout << "\nWinning Candidate: " << candidates[winnerIndex]
              << " with " << voteCounts[winnerIndex] << " votes\n";

    return 0;
}

