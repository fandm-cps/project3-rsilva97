#ifndef BINARY_HEAP
#define BINARY_HEAP

#include <iostream>
using namespace std;

class BinaryHeap {
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