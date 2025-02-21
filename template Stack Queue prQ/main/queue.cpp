#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
using namespace std;
#include "queue.h"


template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<double>;

// constructor
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
Queue<T>::Queue() 
{
    this->head = NULL;        
    this->tail = NULL;
}

/*
khởi tạo node đầu tiên copy giá trị từ node đầu tiên của queue other
duyệt qua các node còn lại của queue other và khởi tạo các node tương ứng cho queue hiện tại
*/
// copy constructor
// độ phức tạp O(n) vì phải duyệt từng phần tử để gán
template <class T>
Queue<T>::Queue(const Queue<T>& other) 
{
    this->head = NULL;
    this->tail = NULL;

    Node<T>* current = other.head;

    // thêm từng phần với data tương ứng lấy từ other
    while (current != NULL)        
    {
        enqueue(current->data);
        current = current->next;
    }
    cout << "Queue copied!!" << endl;
}

// destructor
// độ phức tạp O(n) vì phải duyệt từng phần tử để xoá
template <class T>
Queue<T>::~Queue() 
{
    // duyệt queue và xoá từng phần tử
    while (this->head != NULL)
    {
        Node<T>* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

// thêm 1 phần tử vào cuối hàng đợi
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
void Queue<T>::enqueue(const T& data)
{
    // Khởi tạo 1 node mới với giá trị data
    Node<T>* node = new Node<T>;     
    node->data = data;
    node->next = NULL;

    // Nếu queue k rỗng 
    if (this->tail != NULL)
    {
        // gán ptu kế tiếp là node mới
        this->tail->next = node;
    }
    // gán tail tới vị trí mới
    this->tail = node;

    // nếu queue rỗng       
    if (this->head == NULL)
    {
        // gán front = node
        this->head = node;
    }
}

// lấy phần tử front ra khỏi hàng đợi
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
T Queue<T>::dequeue()
{
    if (this->head == NULL)
    {
        cout << "Cann't dequeue. Queue is empty!!" << endl;
        return T();
    }

    // xoá phần tử         
    Node<T>* temp = this->head;
    this->head = this->head->next;      // cập nhập danh sách các phần tử trong queue

    // gán 1 biến value = front->data để lưu giữ và truy xuất
    T value = temp;
    delete temp;
    temp = NULL;

    return value;
};

// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
bool Queue<T>::isEmpty() const
{
    return (this->head == NULL);
}

// lấy ra giá trị front của hàng đợi
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
T Queue<T>::peek() const
{
    if (this->head == NULL)
    {
        cout << "Cann't get min value. Queue is empty!!" << endl;
        return T();
    }
    else
    {
        // trả về giá trị front của hàng đợi
        return this->head->data;
    }
}

/*
kiểm tra xem đối tượng gán có phải chính nó hay không, nếu phải thì trả về luôn đối tượng hiện tại
xóa các node của queue hiện tại
copy từng node từ queue other sang queue hiện tại
trả về đối tượng hiện tại
*/
// toán tử gán của 2 queue
// độ phức tạp O(n) vì cần duyệt qua từng phần tử để gán        
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    // kiểm tra có tự gán hay k
    if (this != &other)
    {

        // xóa các phần tử cũ trong queue
        while (this->head != NULL)
        {
            dequeue();
        }

        // sao chép từng phần tử từ other sang this
        Node<T>* temp = other.head;
        while (temp != NULL)
        {
            enqueue(temp->data);
            temp = temp->next;
        }
        cout << "Queue copied by operator!!" << endl;
    }
    return *this;
}
#endif