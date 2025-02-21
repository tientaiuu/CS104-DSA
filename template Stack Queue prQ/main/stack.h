#ifndef stack_h
#define stack_h

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class Stack {
private:
	Node<T>* top;

public:
	Stack();				    // constructor
	Stack(const Stack&);		// copy constructor
	~Stack();				    // destructor

	// operations
	bool isEmpty() const;		// check empty
	void push(const T&);		// thêm phần tử vào 
	T pop();					// lấy phần tử top ra khỏi stack
	T topValue() const;			// lấy ra giá trị phần tử top

	// assign operator
	Stack<T>& operator=(const Stack<T>&);  // định nghĩa toán tử = cho 2 stack
};	
#include "stack.cpp"

#endif

