#ifndef stack_cpp
#define stack_cpp

#include "stack.h"
#include <iostream>
using namespace std;

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
template class Stack<double>;

// constructor
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
Stack<T>::Stack()
{
	this->top = NULL;
}

// destructor
// độ phức tạp O(n) vì phải duyệt từng phần tử để xoá
template <class T>
Stack<T>::~Stack()
{
	while (this->top != NULL)
	{
		Node<T>* temp = this->top;
		this->top = this->top->next;
		delete temp;
	}
}

/*
khởi tạo node đầu tiên copy giá trị từ node đầu tiên của stack other
duyệt qua các node còn lại của stack other và khởi tạo các node tương ứng cho stack hiện tại
đảo ngược lại stack vì sau khi push các phần tử của stack sẽ bị đảo thứ tự
*/
// copy constructor
// độ phức tạp O(n) vì phải duyệt từng phần tử để copy
template <class T>
Stack<T>::Stack(const Stack<T>& other) 
{
	this->top = NULL;

	Node<T>* current = other.top;

	// thêm từng phần với data tương ứng lấy từ other
	while (current != NULL)
	{
		push(current->data);
		current = current->next;
	}

	// dảo ngược thứ tự các node trong stack mới
	Node<T>* prev = NULL;
	Node<T>* curr = this->top;
	Node<T>* next1;

	while (curr != NULL) 
	{
		next1 = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next1;
	}
	this->top = prev;
	cout << "Stack copied constructor !!" << endl;
}

// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
bool Stack<T>::isEmpty() const
{
	return this->top == NULL;
}

// thêm phần tử vào top 
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
void Stack<T>::push(const T& data) 
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->next = this->top;
	this->top = newNode;
}

// lấy phần tử top ra khỏi stack
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
T Stack<T>::pop() 
{
	if (this->top == NULL)
	{
		cout << "Cann't pop. Stack is empty!!!" << endl;
		return T();
	}
	Node<T>* temp = this->top;
	this->top = this->top->next;				// cập nhập danh sách các phần tử trong stack

	// gán 1 biến value = top->data để lưu giữ và truy xuất
	T value = temp->data;
	delete temp;
	temp = NULL;

	return value;
}

// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
T Stack<T>::topValue() const
{
	if (this->top == NULL)
	{
		cout << "Cann't get top value. Stack is empty" << endl;
		return T();
	}
	else
	{
		return this->top->data;
	}
}


/*
kiểm tra xem đối tượng gán có phải chính nó hay không, nếu phải thì trả về luôn đối tượng hiện tại
xóa các node của stack hiện tại
copy từng node từ stack other sang stack hiện tại
đảo ngược lại stack vì sau khi push các phần tử của stack sẽ bị đảo thứ tự
trả về đối tượng hiện tại
*/
// toán tử gán = 2 stack
// độ phức tạp O(n) vì phải duyệt từng phần tử để gán
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		// xóa các node của stack hiện tại
		while (this->top != NULL)
		{
			Node<T>* temp = this->top;
			this->top = this->top->next;
			delete temp;
		}

		// copy các node từ other sang
		if (other.top == NULL)
		{
			this->top = NULL;
		}
		else 
		{
			Node<T>* current = other.top;
			while (current != NULL)
			{
				push(current->data);
				current = current->next;
			}
			// dảo ngược thứ tự các node trong stack mới
			Node<T>* prev = NULL;
			Node<T>* curr = this->top;
			Node<T>* next1;

			while (curr != NULL) {
				next1 = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next1;
			}

			this->top = prev;
		}

		cout << "Stack copied by operator !!" << endl;
	}
	return *this;
}

#endif