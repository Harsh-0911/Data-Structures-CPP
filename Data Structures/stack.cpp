#include<iostream>
#include<string>

using namespace std;

class Stack
{
	private:
		int top;
		int arr[5];
		
	public:
		
		Stack()
		{
			top = -1;
			for(int i=0; i<5; i++)
			{
				arr[i] = 0;
			}
		}
		
		bool isFull()
		{
			if(top == 4)
				return true;
			else
				return false;
		}
		
		bool isEmpty()
		{
			if(top == -1)
				return true;
			else
				return false;
		}
		
		void push(int val)
		{
			if(isFull())
			{
				cout << "Stack Overflow";
				cout << endl;
			}
			else
			{
				top += 1;
				arr[top] = val;
				cout << "Value Inserted";
			}
		}
		
		int pop()
		{
			if(isEmpty())
			{
				cout << "Stack Underflow";
			}
			else
			{
				int temp = arr[top];
				top -= 1;
				arr[top] = 0;
				return temp;
			}
		}
		
		int count()
		{
			return (top + 1);
		}
		
		int peek(int index)
		{
			return (arr[index]); 
		}
		
		void change(int index, int newVal)
		{
			arr[index] = newVal;
			cout << "Value Changed";
		}
		
		void display()
		{
			for (i=4 ; i>= 0; i--)
			{
				cout << arr[i] << endl;
			}
		}
	
};

int main()
{
	int index, newVal;
	int option;
//	do						copied from queue.cpp
//	{
//		cout << endl;
//		cout << "0. Exit" << endl;
//		cout << "1. Enqueue" << endl;
//		cout << "2. Dequeue" << endl;
//		cout << "3. isFull" << endl;
//		cout << "4. isEmpty" << endl;
//		cout << "5. Display" << endl;
//		cout << "6. Count" << endl;
//		
//		cin>>option;
//		
//		switch(option)
//		{
//			case 0:
//				break;
//				
//			case 1:
//				cout << "Enter value to be enqueued";
//				cin >> val;
//				q1.enqueue(val);
//				break;
//				
//			case 2:
//				cout << "value dequeued is | " << q1.dequeue()<< endl;
//				break;
//			
//			case 3:
//				if(q1.isFull())
//				{
//					cout << "queue is full";
//				}
//				else
//				{
//					cout << "queue is not full";
//				}
//				break;
//				
//			case 4:
//				if(q1.isEmpty())
//				{
//					cout << "queue is empty";
//				}
//				else
//				{
//					cout << "queue is not empty";
//				}
//				break;
//				
//			case 5:
//				q1.display();
//				break;
//		
//			case 6:
//				q1.count();
//				break;
//		}
//	}
//	while(option != 0);

	
	return 0;
}
