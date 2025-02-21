#ifndef priorityqueue_cpp
#define priorityqueue_cpp

#include "priorityqueue.h"
#include <iostream>
using namespace std;

template class priorityQueue<int>;
template class priorityQueue<float>;
template class priorityQueue<char>;
template class priorityQueue<double>;

// constructor
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
priorityQueue<T>::priorityQueue()
{
	// tạo mảng động với kích thước đầu là 1
	this->prQ = new T[1];
	this->heapSize = 0;
}

// copy constructor
// độ phức tạp O(n) vì phải duyệt từng phần tử
template <class T>
priorityQueue<T>::priorityQueue(const priorityQueue& other)
{
	// copy độ dài của other
	this->heapSize = other.heapSize;

	// cấp phát mảng mới
	this->prQ = new T[this->heapSize];

	// duyệt và gán từng phần tử
	for (int i = 0; i < this->heapSize;i++)
	{
		this->prQ[i] = other.prQ[i];
	}
	cout << "Priority Queue copied!!" << endl;
}

// destructor
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
priorityQueue<T>::~priorityQueue()
{
	// thực hiện xoá con trỏ k cần duyệt qua từng phần tử
	delete[] this->prQ;
}

// check empty
// độ phức tạp O(1)
template <class T>
bool priorityQueue<T>::isEmpty() const
{
	return this->heapSize == 0;
}

// trả về giá trị nhỏ nhất trong heap
// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
T priorityQueue<T>::getMin() const
{
	if (this->heapSize ==0)
	{
		cout << "Cann't get min value. Queue is empty!!" << endl;
		return T();
	}
	else
	{
		// cây min heap nên trả về giá trị đâu tiên
		return this->prQ[0];
	}
}

// thêm 1 ptu vào và vẫn giữ tính chất của min heap
// độ phức tạp O(logn) do phải heapify lại heap
template <typename T>
void priorityQueue<T>::push(const T& data) {

	// tăng kích thước mảng lưu trữ heap
	T* newHeap = new T[this->heapSize + 1];

	// copy các phần tử cũ sang mảng mới
	for (int i = 0; i < this->heapSize; i++) {
		newHeap[i] = this->prQ[i];
	}

	// xóa mảng cũ tránh bị leak vùng nhớ
	delete[] this->prQ;

	// cập nhật lại con trỏ mảng
	this->prQ = newHeap;

	// thêm phần tử mới vào cuối mảng
	this->prQ[this->heapSize] = data;

	// tăng kích thước heap lên 1
	this->heapSize++;

	// heapify để duy trì tính chất min heap

	int current = this->heapSize - 1;

	// duyệt mảng ngược và so sánh với nút cha 
	while (current > 0 && this->prQ[current] < this->prQ[(current - 1) / 2])
	{
		// nếu nút con < nút cha thì swap
		swap(current, (current - 1) / 2);

		// duyệt lên nút cha
		current = (current - 1) / 2;
	}
}

// xoá ptu có độ ưu tiên cao nhất của heap
// độ phức tạp O(logn) do phải heapify lại heap
template <class T>
void priorityQueue<T>::pop() 
{
	if (this->heapSize != 0)
	{
		// xóa phần tử đầu 
		swap(0, this->heapSize - 1);

		// giảm số lượng phần tử
		this->heapSize--;

		// heapify để duy trì tính chất min heap
		heapify(0);
	}
	else
	{
		cout << "Cann't popped. Queue is empty!!" << endl;
	}
}

// độ phức tạp O(logn) do phải duyệt heap từ nút cha xuống
template <class T>
void priorityQueue<T>::heapify(int index) 
{
	// nút con trái
	int left = 2 * index + 1;
	
	// nút con phải
	int right = 2 * index + 2;

	// so sánh giá trị của node hiện tại với 2 node con, tìm ra index của node nhỏ nhất
	int minIndex = index;
	if (left < this->heapSize && this->prQ[left] < this->prQ[index])
	{
		minIndex = left;
	}
	if (right < this->heapSize && this->prQ[right] < this->prQ[minIndex])
	{
		minIndex = right;
	}

	// nếu node nhỏ nhất không phải là node hiện tại, hoán đổi giá trị 2 node đó
	if (minIndex != index) 
	{
		swap(index, minIndex);

		// đệ quy gọi heapify với node con vừa được hoán đổi cho đến khi đáp ứng tính chất min heap
		heapify(minIndex);
	}
}

// độ phức tạp O(1) vì chỉ truy cập 1 phần tử, k duyệt tiếp
template <class T>
void priorityQueue<T>::swap(int x, int y)
{
	T temp = this->prQ[x];
	this->prQ[x] = this->prQ[y];
	this->prQ[y] = temp;
}

// toán tử gán =
// độ phức tạp O(n) vì phải duyệt qua từng phần tử
template <class T>
priorityQueue<T>& priorityQueue<T>::operator=(const priorityQueue<T>& other)
{
	// kiểm tra nếu tự gán
	if (this != &other)
	{
		// xoá heap cũ tránh bị leak vùng nhớ
		delete[] this->prQ;

		// sao chép kích thước của other
		this->heapSize = other.heapSize;

		// cấp phát heap mới
		this->prQ = new T[this->heapSize];

		// gán từng phần tử
		for (int i = 0; i < this->heapSize; i++)
		{
			this->prQ[i] = other.prQ[i];
		}
		cout << "Priority Queue copied by operator!!" << endl;
	}
	// trả về heap đã gán
	return *this;
}
#endif 