// main magic behind this program is line index=(index+1)%(size of array)

#include <iostream>

using namespace std;

class CirculerQueue
{
	private:
		int front;
		int rear;
		int arr[5];
		int itemcount;	// to count the items in the queue
	
	public:
	
		CirculerQueue()
		{
			itemcount = 0;
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
			if((rear+1)%5 == front)		// this line will just loop through the array like from index 4 to direct index 0
				return true;			// eg; if we are at index posotion 4 then (rear+1)%5 will return 0
			else						// so, we are directly at the index position 0.
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
				//rear++;
				rear = (rear+1)%5;		// the exact function is (rear+1)%(size of array)
				arr[rear]=val;			// this will keeps inserting the values on the empty slots of the queue 
			}
			itemcount++;
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
				itemcount--;
				return x;
			}
			else
			{
				x = arr[front];
				arr[front]=0;
			//	front++;
				front = (front+1)%5;
				itemcount--;		//this will increments the front pointer in the circuler fashion
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
			return (itemcount);
		}
};

int main()
{
	CirculerQueue q1;
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
				cout << "number of items " << q1.count();
				break;
		}
	}
	while(option != 0);
	
	
	return 0;	
}              













