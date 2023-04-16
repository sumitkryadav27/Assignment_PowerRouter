#include<bits/stdc++.h>
using namespace std;

int findCurrentIndex(vector<char> oldQueue, vector<char> newQueue, int currIndex) {

    // If newQueue is empty, there is no current index member in the updated queue, so return -1
    if (newQueue.size() == 0) {
        return -1;
    }

    // If the current index is greater than or equal to the size of the old queue, it is an invalid index, so return -1
    if (currIndex >= oldQueue.size()) {
        return -1;
    }

    int oldIndex = 0;
    int newIndex = 0;

    // When oldIndex and currIndex are equal, it means we have reached the current index member of the old queue.
    // Hence, the corresponding element in the new queue will be the next element, because if the current member is not removed,
    // then they will be the next person, and if they are removed, then the next person or any other person who will come next
    // will be at that position.
    while (oldIndex != currIndex) {
        if (oldQueue[oldIndex] == newQueue[newIndex]) { // If both elements are equal, it means this person isn't removed
            oldIndex++;
            newIndex++;
        }
        else { // If they are not equal, it means this person is removed, and we want to move to the next element in the old queue but not in the new queue
            oldIndex++;
        }
    }
    // Return the index of the next person in the updated queue by adding 1 to the newIndex
    return newIndex + 1;
}


int main(){
    vector<char> oldQueue = {'A', 'B', 'C', 'D', 'E', 'F', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'A', 'B', 'A'};
    vector<char> newQueue = {'B', 'C', 'E', 'F', 'B', 'C',  'B', 'C',  'B'};
    int currIndex = 7;
    cout<<findCurrentIndex(oldQueue, newQueue, currIndex - 1);

    // vector<char> oldQueue = {'A', 'B', 'D', 'C', 'A', 'C', 'E'};
    // vector<char> newQueue = {'A', 'B', 'A', 'E'};
    // int currIndex = 5;
    // cout<<findCurrentIndex(oldQueue, newQueue, currIndex - 1);

}