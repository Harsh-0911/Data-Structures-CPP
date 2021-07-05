#include <iostream>
using namespace std;

class Node
{
	public:
		int key;
		int data;
		Node* next;
		Node* previous;
		
	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
		previous = NULL;	
	}	
	
	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};

class DoublyLinkedList
{
	public:
		Node* head;
		
		DoublyLinkedList()
		{
			head = NULL;
		}
		DoublyLinkedList(Node* n)
		{
			head = n;
		}
		
		// 1. this method checks if the node exists with the key provided or not. and if the node found in the list then it returns the address of that node.
		Node* checkIfNodeExists(int k)
		{
			Node* temp = NULL;
			Node* ptr = head;
			
			while(ptr != NULL)
			{
				if(ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next; 
			}	
			return temp;
		} 
		
		// 2. this method append a node to the list.
		void appendNode(Node* n)
		{
			if(checkIfNodeExists(n->key) != NULL)
			{
				cout << "Node already exists in the list with the same key you have provided, please try again with another key value" << endl;
				
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout << "Node appended successfully" << endl;
				}
				else
				{
					Node* ptr = head;
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}
					//n->previous = ptr;
					ptr->next = n;
					n->previous = ptr;
					cout << "Node appended successfully" << endl;
				}
			}
			
		}
				
		// 3. this method attach a node at the front of the linked list.
		void prependNode(Node* n)
		{
			if(checkIfNodeExists(n->key) != NULL)
			{
				cout << "Node already exists in the list with the same key you have provided, please try again with another key value" << endl;
				
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout << "Node prepended successfully" << endl;
				}
				else
				{
					n->next = head;
					head->previous = n;
					head = n;
					cout << "Node prepended successfully" << endl;
				}
				
			}	
		}
		
		// 4. this method inserts a node after a perticular node.
		void insertNodeAfter(int k, Node* n)
		{
			Node* ptr = checkIfNodeExists(k);
			if(ptr == NULL)
			{
				cout << "the key you have provided after which you want to insert a node is not exists in the list, try again with another key value" << endl;
			}
			else
			{
				if(checkIfNodeExists(n->key) != NULL)
				{
					cout << "Node already exists in the list with the same key you have provided, please try again with another key value" << endl;
				
				}
				else
				{
					Node* nextnode = ptr->next;
					// inserting at the end
					if(nextnode == NULL)
					{
						ptr->next = n;
						n->previous = ptr;
						cout << "Node Inserted At the End" << endl;
					}
					// inserting in between
					else 
					{
						n->next = ptr->next;
						n->previous = nextnode->previous;
						ptr->next = n;
						nextnode->previous = n;
						cout << "node inserted" << endl;	
					}
					
										
				}
			}
		}
		
		// 5. this method deletes (means unlinking) a node from the list
		void deleteByKey(int k)
		{
			if(head == NULL)
			{
				cout << "can not delete anything bcz linked list is empty" << endl;
			}
			else
			{
				Node* ptr = checkIfNodeExists(k);
				if(ptr == NULL)
				{
					cout << "the kry you have provided is not exist in the linked list." << endl;
				}
				else
				{
					if(ptr == head)
					{
						head = head->next;
						head->previous = NULL;
						cout << " Head Node Unlinked From The Linked List" << endl;
					}
					else if(ptr->next == NULL)
					{
						ptr->previous->next = NULL;
						ptr->previous = NULL;
						cout << "Last Node Is Unlinked From The Linked List." << endl;
					}
					else
					{
						ptr->previous->next = ptr->next;
						ptr->next->previous = ptr->previous;
						ptr->next = NULL;
						ptr->previous = NULL;
						cout << "Node Is Deleted" << endl;
					}
				}
			}
		}
		
		// 6. this method updates a node by key.
		void updateNodeByKey(int k, int d)
		{
			Node* ptr = checkIfNodeExists(k);
			if(ptr == NULL)
			{
				cout << "Node is not exists in the linked list" << endl;
			}
			else
			{
				ptr->data = d;
				cout << "Node Updated Successfully" << endl;
			}
		}
		
		// 7. this method displays the entire linked list
		void display()
		{
			Node* ptr = head;
			if(ptr == NULL)
			{
				cout << "linked list is empty" << endl;
			}
			else
			{
				while(ptr != NULL)
				{
					cout << "(" << ptr->key << " ," << ptr->data << ") -->";
					ptr = ptr->next;
				}
			}
		}
};

int main()
{
	DoublyLinkedList s;
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
				s.insertNodeAfter(k1, n1);
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
