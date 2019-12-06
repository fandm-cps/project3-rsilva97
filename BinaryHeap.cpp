#include "BinaryHeap.hpp"
#include <limits>
#include <iostream>

using namespace std;

BinaryHeap::BinaryHeap(const double* prio, int numItems) {
    size = numItems;
    priorities = new double[size];
    itemPriorities = new double[size];
    indices = new int[size];
    isInHeap = new bool[size];
    
    for(int i = 0; i < size; i++){
        priorities[i] = prio[i];
        indices[i] = i;
        isInHeap[i] = true;
    }

    for(int j = size / 2; j > -1; j--){
        minHeapify(priorities, size, j);
    }
    /*
    cout << "size: " << size << endl;
    for(int i = 0; i < size; i++){
        cout << priorities[i] << " ";
    }
    cout << endl;
    */
}

void BinaryHeap::minHeapify(double* priorities, int size, int index){
    int leftChild = (2 * index) + 1, rightChild = (2 * index) + 2, smallest;
    double doubleTmp;
    int idxTmp;
    
    if(leftChild < size && priorities[leftChild] < priorities[index]){
        smallest = leftChild;
    }
    else{
        smallest = index;
    }

    if(rightChild < size && priorities[rightChild] < priorities[smallest]){
        smallest = rightChild;
    }

    if(smallest != index){
        doubleTmp = priorities[index];
        priorities[index] = priorities[smallest];
        priorities[smallest] = doubleTmp;

        idxTmp = indices[index];
        indices[index] = indices[smallest];
        indices[smallest] = idxTmp;

        minHeapify(priorities, size, smallest);
    }
}

BinaryHeap::~BinaryHeap() {
    delete[] priorities; 
    delete[] itemPriorities;
    delete[] indices;
    delete[] isInHeap;
}

//Returns the item with the minimum priority, but does not alter the heap.
//Must run in O(1) time.
int BinaryHeap::getMin() const {
    return indices[0];
}

//Removes the minimum element from the heap. Must run in O(log n) time.
void BinaryHeap::popMin() {
    isInHeap[indices[0]] = false;
    priorities[0] = priorities[size-1];
    indices[0] = indices[size-1];
    size--;
    minHeapify(priorities, size, 0);
}

//Returns true if item is in the heap. Must be O(1).
bool BinaryHeap::contains(int item) const {
    return isInHeap[item];
}

//Returns the priority of the given item. Note that this priority
//might have changed since the heap was created (see below). 
//Must execute in O(1) time.
double BinaryHeap::getPriority(int item) const {
    return itemPriorities[item];
}

//If the item is not in the heap, or the new priority is greater 
//than or equal to the priority associated with item, do nothing.
//Otherwise, change the priority of the item and fix the heap 
//accordingly. Must execute in O(log n) time.
void BinaryHeap::decreasePriority(int item, double newPriority) {
    int idx = getPos(item);
    double tmp;
    if(contains(item) && newPriority < priorities[idx]){
        priorities[idx] = newPriority;
        itemPriorities[item] = newPriority;
        minHeapify(priorities, size, 0);
    }
}

//Returns the number of items currently in the heap. Must be O(1).
int BinaryHeap::getSize() const {
    return size;
}

//Mainly for testing/debugging. Returns the item at the given
//position in the heap (so, h.getItem(0) should be equivalent 
//to h.getMin()). Must be O(1).
int BinaryHeap::getItem(int pos) const {
    return indices[pos];
}

//Mainly for testing/debugging. Returns the position of the
//given item in the heap (so, for instance 
//h.getPos(h.getMin()) should return 0). Must be O(1).
int BinaryHeap::getPos(int item) const {
    return indices[item];
}
