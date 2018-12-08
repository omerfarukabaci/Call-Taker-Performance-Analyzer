enum Type {
	MAX_HEAP,
	MIN_HEAP
};

template <class Data>
class Heap {
	static const int MAX_HEAPSIZE = 1000;
	int heapSize;
	Type heapType;
	Data* nodes;
	void maxHeapify(int index);
	void minHeapify(int index);

public:
	Heap();
	Heap(Type type);
	~Heap();
	void insert(Data input);
	void increaseKey(int index, Data add);
	void buildMaxHeap();
	void buildMinHeap();
	Data extractMax();
	Data extractMin();
	void heapSort();
	void swap(int index1, int index2);
	int nodeIsPresent(Data d);
	int parentIndexOf(int index);
	int leftIndexOf(int index);
	int rightIndexOf(int index);
	void printMax3();
	void printMin3();

};