# include<iostream>

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
		
	}
};

class SinglyLinkedList
{
	public:
		Node* head;
		
		SinglyLinkedList()
		{
			head = NULL;	
		}	
		
		SinglyLinkedList(Node *n)
		{
			head = n;
		}
		
		// 1. Checks if the Node having the Key value K exists in the linked list or not.
		Node* nodeExists(int k)
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
					cout << "Node Appended At The End" << endl;
				}
				else
				{
					Node* ptr = head;
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}
					ptr->next = n;
//					n->next = NULL;
					cout << "Node Appended At The End" << endl;
				}
			}
		}
//		3. Prepending the node.
		
		void prependNode(Node* n)
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
					cout << "Node Prepended" << endl;
				}
				else
				{
					n->next = head;
					head = n;
					cout << "Node Prepended" << endl;
				}
			}
		}
//		4. Insert a node after a perticular node
		
		void insertNodeAfter(int k, Node* n)
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
					n->next = ptr->next;
					ptr->next = n;
					cout << "Node Inserted" << endl;
				}
			}
		}
		
//		5. Delete a node from the linked list

		void deleteNodeByKey(int k)
		{
			if(head == NULL)
			{
				cout << "Singly Linked List Is Empty. Can Not Delete Anything From The List" << endl;
			}
			else if(head != NULL)
			{
				if(head->key == k)
				{
					head = head->next;
					cout << "Node is unlinked" << endl;
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
					if(temp != NULL)
					{
						prevptr->next = temp->next;
						cout << "Node Unlinked" << endl;
					}
					else
					{
						cout << "Node Does Not Exists With the key value " <<k << endl;
					}
				}
			}
		}

//	6. update Node
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
		
//		7. printing the linked list
		void printlist()
		{
			Node* temp = head;
			if(temp == NULL)
			{
				cout << "linked list is empty" << endl;
			}
			else
			{
				while (temp != NULL)
				{
					cout << temp->key << ", " << temp->data << " --> ";
					temp = temp->next;
				}
			}
		}
};



int main()
{
	SinglyLinkedList s;
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
				s.deleteNodeByKey(k1);
				break;
				
			case 5:
				cout << "enter key and  new data to update" << endl;
				cin >> key1;
				cin >> data1;
				s.updateNodeByKey(key1,data1);
				break;
				
			case 6:
				s.printlist();
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


















