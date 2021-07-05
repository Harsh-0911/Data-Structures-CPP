#include <iostream>

using namespace std;

class Queue
{
	private:
		int front;
		int rear;
		int arr[5];
	
	public:
	
		Queue()
		{
			front = -1;
			rear = -1;
			for(int i=0; i<5; i++)
			{
				arr[i] = 0;
			}
		}
		
		bool isEmpty()
		{
			if(front == -1 && rear == -1)
				return true;
			else
				return false;
		}
		
		bool isFull()
		{
			if(rear == 4)
				return true;
			else
				return false;
		}
		
		void enqueue(int val)
		{
			if(isFull())
			{
				cout<< "Queue is Full" << endl;
				return;
			}
			else if(isEmpty())
			{
				front = 0;
				rear = 0;
				arr[rear]=val;
			}
			else
			{
				rear++;
				arr[rear]=val;
			}
		}
		
		int dequeue()
		{
			int x;
			if(isEmpty())
			{
				cout << "Queue is Empty" << endl;
				return 0;
			}
			else if(front == rear)
			{
				x = arr[front];
				arr[front]=0;
				front = -1;
				rear = -1;
				return x;
			}
			else
			{
				x = arr[front];
				arr[front]=0;
				front++;
				return x;
			}
		}
		
		void display()
		{
			for(int i=0; i<5; i++)
			{
				cout<< arr[i]<< " " ;
			}
		}
		
		int count()
		{
			return (rear-front+1);
		}
};

int main()
{
	Queue q1;
	int val, option;
	
	do
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. isFull" << endl;
		cout << "4. isEmpty" << endl;
		cout << "5. Display" << endl;
		cout << "6. Count" << endl;
		
		cin>>option;
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				cout << "Enter value to be enqueued";
				cin >> val;
				q1.enqueue(val);
				break;
				
			case 2:
				cout << "value dequeued is | " << q1.dequeue()<< endl;
				break;
			
			case 3:
				if(q1.isFull())
				{
					cout << "queue is full";
				}
				else
				{
					cout << "queue is not full";
				}
				break;
				
			case 4:
				if(q1.isEmpty())
				{
					cout << "queue is empty";
				}
				else
				{
					cout << "queue is not empty";
				}
				break;
				
			case 5:
				q1.display();
				break;
		
			case 6:
				q1.count();
				break;
		}
	}
	while(option != 0);
	
	
	return 0;	
}              













