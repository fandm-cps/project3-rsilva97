#include "BinaryHeap.hpp"
#include <limits>
#include <iostream>

using namespace std;

BinaryHeap::BinaryHeap(const double* priorities, int numItems) {
    items = new double[numItems+1];
    indices = new int[numItems+1];
    pCopies = new double[numItems+1];
    removed = new bool[numItems+1];
    size = numItems;

    for(int i = 0; i < numItems; i++){
        items[i+1] = priorities[i];
        indices[i+1] = i;
        removed[i+1] = false;
        pCopies[i+1] = priorities[i];
    }

    for(int j = numItems / 2; j > 0; j--){
        minHeapify(items, numItems, j);
    }

    /*
    cout<<"size: "<<size<<endl;
    for(int i=0; i<numItems; i++){
        cout<<items[i+1]<<" ";
    }*/
    
}

void BinaryHeap::minHeapify(double* items, int numItems, int index){
    int leftChild, rightChild, smallest;
    double doubleTmp;
    int idxTmp;
    int posTmp;

    leftChild = 2 * index;
    rightChild = (2 * index) + 1;
    
    if(leftChild <= numItems && items[leftChild] < items[index]){
        smallest = leftChild;
    }
    else{
        smallest = index;
    }

    if(rightChild <= numItems && items[rightChild] < items[smallest]){
        smallest = rightChild;
    }

    if(smallest != index){
        doubleTmp = items[index];
        items[index] = items[smallest];
        items[smallest] = doubleTmp;

        idxTmp = indices[index];
        indices[index] = indices[smallest];
        indices[smallest] = idxTmp;

        minHeapify(items, numItems, smallest);
    }
}

BinaryHeap::~BinaryHeap() {
    delete[] items; 
    delete[] indices;
    delete[] removed;
    delete[] pCopies;
}

int BinaryHeap::getMin() const {
    return indices[1];
}

void BinaryHeap::popMin() {
    double min = items[1];
    removed[indices[1]] = true;
    items[1] = items[size];
    size--;
    minHeapify(items, size, 1);
}

bool BinaryHeap::contains(int item) const {
    return (removed[item])? false : true;
}

double BinaryHeap::getPriority(int item) const {
    return pCopies[item+1];
}

void BinaryHeap::decreasePriority(int item, double newPriority) {


}

int BinaryHeap::getSize() const {
    return size;
}

int BinaryHeap::getItem(int pos) const {
    return indices[pos+1];
}

int BinaryHeap::getPos(int item) const {
    return indices[item+1];
}
