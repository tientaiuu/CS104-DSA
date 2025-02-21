#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	Queue();							// constructor
	Queue(const Queue&);                // sao chép constructor
	~Queue();							// destructor

	void enqueue(const T&);				// thêm ptu vào cuối hàng đợi
	T dequeue();						// lấy phần tử front ra khỏi hàng đợi
	T peek() const;						// lấy giá trị của front
	bool isEmpty() const;				// check empty
	 
	// assign operator
	Queue<T>& operator=(const Queue<T>&);  // toán tử gán 2 Queue
};

#include "queue.cpp" 
#endif