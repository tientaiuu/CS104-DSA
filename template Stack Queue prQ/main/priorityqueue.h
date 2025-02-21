#ifndef priorityqueue_h
#define priorityqueue_h

template <class T>
class priorityQueue
{
private:
	T* prQ;
	int heapSize = 0;

	void heapify(int index);
	void swap(int x, int y);
public:
	priorityQueue();									// constructor
	priorityQueue(const priorityQueue&);				// copy constructor
	~priorityQueue();									// destructor

	bool isEmpty() const;								// check empty
	T getMin() const;									// lấy ra ptu min
	void push(const T&);								// thêm vào heap
	void pop();											// xoá ptu có độ ưu tiên cao nhất 

	priorityQueue<T>& operator=(const priorityQueue<T>&);  // toán tử gán 2 queue
};

#include "priorityqueue.cpp"
#endif 
