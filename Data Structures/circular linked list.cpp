#include<iostream>
using namespace std;

class Node
{
	public:
		int key;
		int data;
		Node* next;
		
		Node()
		{
			key = 0;
			data = 0;
			next = NULL;
		}
		Node(int k, int d)
		{
			key = k;
			data = d;
			next = NULL;
		}
};

class CircularLinkedList
{
	public:
		Node* head;
		
		CircularLinkedList()
		{
			head = NULL;
		}
		
//		CircularLinkedList(Node *n)
//		{
//			head = n;
//		}
		
		// 1. Checks if the Node having the Key value K exists in the linked list or not.
		Node* nodeExists(int k)
		{
			Node* ptr = head;
			Node* temp = NULL;
			
			if(ptr == NULL)
			{
				return temp;
			}
			else
			{
				do
				{
					if(ptr->key == k)
					{
						temp = ptr;
					}
					ptr = ptr->next;
				}while(ptr != head);
				
				return temp;
			}
		}
		
		// 2. Append the Node in the Linked List
		void appendNode(Node* n)
		{
			if(nodeExists(n->key) != NULL)
			{
				cout << "The Node Having The Same Key Already Exists In The Linked List" << endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					n->next = head;
					cout << "Node Appended At The End" << endl;
				}
				else
				{
					Node* ptr = head;
					do
					{
						ptr = ptr->next;
					}while(ptr->next != head);
				
					ptr->next = n;
					n->next = head;
					cout << "Node Appended At The End" << endl;
				}
				
			}
		}
		
//		3. this method prepend node at the starting of the linked list
		void prependNode(Node* n)
		{
			if(nodeExists(n->key) != NULL)
			{
				cout << "Node exists with the same key." << endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					n->next = head;
					cout << "Node Prepended" << endl;
				}
				else
				{
					Node* temp = head;
					Node* ptr = head;
					do
					{
						ptr = ptr->next;
					}while(ptr->next != head);
					
					ptr->next = n;
					n->next = temp;
					head =  n;
					cout << "Node Prepened" << endl;
				}
			}
		}
		
//		4. this method inserts a node after a perticular node.
 		void insertAfter(int k, Node* n)
 		{
 			Node* ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout << "Node Having the key value " << k <<" does not exists" << endl;
			}
			else
			{
				if(nodeExists(n->key) != NULL)
				{
					cout << "The Node Having The Same Key Already Exists In The Linked List" << endl;
				}
				else
				{
//					n->next = ptr->next;
//					ptr->next = n;
//					cout << "Node Inserted" << endl;
					if(ptr->next == head)
					{
						ptr->next = n;
						n->next = head;
						cout << "Node inserted At The End" << endl;
					}
					else
					{
						n->next = ptr->next;
						ptr->next = n;
						cout << "Node inserted in between" << endl;
					}
				}
			}	
		}
		
//		5. Delete a node from the linked list

		void deleteByKey(int k)
		{
			Node* ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout << "There is no node exists with the key you have provided" << endl;
			}
			else
			{
				if(ptr == head)
				{
					if(head->next == head)
					{
						head = NULL;
						cout << "node is unlinked and linked list is empty" << endl;
					}
					else
					{
						Node* ptr1 = head;
						while(ptr1->next != head)
						{
							ptr1 = ptr1->next;
						}
						ptr1->next = head->next;
						head = head->next;
						cout << "node is unlinked" << endl;
					}
				}
				else
				{
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					while(currentptr != NULL)
					{
						if(currentptr->key == k)
						{
							temp = currentptr;
							currentptr = NULL;
						}
						else
						{
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					
					prevptr->next = temp->next;
					cout << "node unlinked" << endl;
				}
			}
		}
//		6. this method updates a node  with the key provided
		void updateNodeByKey(int k, int d)
		{
			Node* ptr = nodeExists(k);
			if(ptr != NULL)
			{
				ptr->data=d;
				cout << "Data Updated" << endl ;
			}	
			else
			{
				cout << "Node not exists" << endl;
			}
		}
		
//		7. this method displays the linked list
		void display()
		{
			Node* ptr = head;
			if(ptr == NULL)
			{
				cout << "linked list is empty" << endl;
			}
			else
			{
				do
				{
					cout << ptr->key << ", " << ptr->data << " --> ";
					ptr = ptr->next;
				}while(ptr != head);
			}
		}


};



int main()
{
	CircularLinkedList s;
	int option;
	int k1, key1, data1;
	
	do
	{
		cout << endl;
		cout << "1. append node" << endl;
		cout << "2. prepend node" << endl;
		cout << "3. insert node" << endl;
		cout << "4. delete node" << endl;
		cout << "5. update node" << endl;
		cout << "6. display node" << endl;
		cout << "7. clear screen" << endl;
		cout << "0. exit" << endl;
		cout << endl;
		
		cin >> option;
		Node* n1 = new Node();
		
		switch(option)
		{
			case 0:
				break;
			
			case 1:
				cout << "enter key and data "<< endl;
				cin >> key1;
				cin >> data1;
				n1->data = data1;
				n1->key = key1;
				s.appendNode(n1);
				break;
				
			case 2:
				cout << "enter key and data "<< endl;
				cin >> key1;
				cin >> data1;
				n1->data = data1;
				n1->key = key1;
				s.prependNode(n1);
				break;
				
			case 3:
				cout << "enter the key after which you want to add node" << endl;
				cin >> k1;
				cout << "enter key and data "<< endl;
				cin >> key1;
				cin >> data1;
				n1->data = data1;
				n1->key = key1;
				s.insertAfter(k1, n1);
				break;
				
			case 4:
				cout << "enter key to be deleted" << endl;
				cin >> k1;
				s.deleteByKey(k1);
				break;
				
			case 5:
				cout << "enter key and  new data to update" << endl;
				cin >> key1;
				cin >> data1;
				s.updateNodeByKey(key1,data1);
				break;
				
			case 6:
				s.display();
				break;
			
			case 7:
				system("cls");
				break;
				
			default:
				cout << "enter proper option" << endl;
				break;
		}
	}while(option != 0);
	
	return 0;
}
