//#include "queue.h" 
//
//int main() 
//{
//	cout << "----------------------------TEST 1----------------------------" << endl;
//	// Test 1 với kiểu dữ liệu của Queue là char
//	Queue<char> q;
//	q.enqueue('a');
//	if (!q.isEmpty())
//	{
//		cout << "Queue isn't empty" << endl;
//	}
//	else cout << "Queue is empty" << endl;
//	cout << "Front Value of q: " << q.peek() << endl;
//
//	// copy constructor
//	Queue<char> other(q);
//	other.dequeue();
//	other.enqueue('f');
//	other.enqueue('b');
//	cout << "Front Value of other: " << other.peek() << endl;
//
//	// copy operator
//	Queue<char> other1;
//	other1 = q;
//	other1.dequeue();
//	cout << "Front Value of other1: " << other1.peek() << endl;
//	
//	cout << "----------------------------TEST 2----------------------------" << endl;
//	// Test 2 với kiểu dữ liệu của Queue là int
//	Queue<int> q1;
//	if (!q1.isEmpty())
//	{
//		cout << "Queue isn't empty" << endl;
//	}
//	else cout << "Queue is empty" << endl;
//	q1.enqueue(1);
//	q1.enqueue(2);
//	q1.enqueue(10);
//	cout << "Front Value of q1: " << q1.peek() << endl;
//
//	// copy constructor
//	Queue<int> temp(q1);
//	temp.dequeue();
//	cout << "Front Value of temp: " << temp.peek() << endl;
//
//	// copy operator
//	Queue<int> temp1;
//	temp1 = temp;
//	temp1.dequeue();
//	temp1.dequeue();
//	cout << "Front Value of temp1: " << temp1.peek() << endl;
//	return 0;
//}

#include "stack.h"

int main()
{
	cout << "----------------------------TEST 1----------------------------" << endl;
	//Test 1 với kiểu dữ liệu của Stack là char
	Stack<char> stack;
	stack.push('f');
	stack.push('s');
	cout << "Top Value of stack: " << stack.topValue() << endl;

	// copy constructor
	Stack<char> temp(stack);
	temp.pop();
	cout << "Top Value of temp: " << temp.topValue() << endl;

	// copy operator
	Stack<char> temp1;
	temp1 = stack;
	temp1.push('t');
	temp1.pop();
	temp1.pop();
	temp1.pop();
	cout << "Top Value of temp1: " << temp1.topValue() << endl;

	cout << "----------------------------TEST 2----------------------------" << endl;
	//Test 2 với kiểu dữ liệu của Stack là int
	Stack<int> s;
	s.push(1);
	s.push(100);
	cout << "Top Value of s: " << s.topValue() << endl;

	// copy constructor
	Stack<int> other(s);
	other.pop();
	cout << "Top Value of other: " << other.topValue() << endl;

	// copy operator
	Stack<int> other1;
	other1 = s;
	other1.push(13);
	
	cout << "Top Value of other1: " << other1.topValue() << endl;
	return 0;
}

//#include "priorityqueue.h"
//
//int main()
//{
//	cout << "----------------------------TEST 1----------------------------" << endl;
//	// Test 1 với kiểu dữ liệu của Queue là char
//	priorityQueue<char> prq;
//	prq.push('a');
//	prq.push('b');
//	cout << "Min value of prq: " << prq.getMin() << endl;
//
//	// copy constructor
//	priorityQueue<char> temp(prq);
//	temp.pop();
//	cout << "Min value of temp: " << temp.getMin() << endl;
//
//	// copy operator
//	priorityQueue<char> temp1;
//	temp1 = temp;
//	temp1.pop();
//	cout << "Min value of temp1: " << temp1.getMin() << endl;
//	
//	cout << "----------------------------TEST 2----------------------------" << endl;
//	// Test 2 với kiểu dữ liệu của Queue là int
//	priorityQueue<int> prQ;
//	prQ.push(10);
//	prQ.push(2);
//	if (prQ.isEmpty())
//	{
//		cout << "Queue is empty!!" << endl;
//	}
//	else cout << "Queue isn't empty!!" << endl;
//	cout << "Min Value: " << prQ.getMin() << endl;
//
//	// copy constructor
//	priorityQueue<int> other(prQ);
//	other.pop();
//	cout << "Min Value of other: " << other.getMin() << endl;
//	
//	// copy operator
//	priorityQueue<int> other1;
//	other1 = other;
//	other1.pop();
//	cout << "Min Value of other1: " << other1.getMin() << endl;
//	return 0;
//}