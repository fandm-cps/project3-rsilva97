#ifndef BINARY_HEAP
#define BINARY_HEAP

#include <iostream>
using namespace std;

class BinaryHeap {
	protected:
		double* items;
		int* indices;
		bool* removed;
		double* pCopies;
		int size;
		void minHeapify(double* items, int numItems, int index);

	public:
		BinaryHeap(const double* priorities, int numItems);
		~BinaryHeap();
		int getMin() const;
		void popMin();
		bool contains(int item) const;
		double getPriority(int item) const;
		void decreasePriority(int item, double newPriority);
		int getSize() const;
		int getItem(int pos) const;
		int getPos(int item) const;
};

#endif