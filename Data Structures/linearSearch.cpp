#include<iostream>
using namespace std;

void linearSearch(int a[], int n)
{
	int temp = -1;
	for(int i=0;i<5;i++)
	{
		if(a[i] == n)
		{
			cout << "Number Found At Location " << i << endl;
			temp = 0;
			break;
		}
	}
	if(temp != 0)
	{
		cout << "Element Is Not There In The List" << endl;
	}
}

int main()
{
	int arr[5];
	cout << "Enter 5 Numbers" << endl;
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	cout << "Enter Number To Be Searched" << endl;
	int num;
	cin >> num;
	
	linearSearch(arr,num);
	
	return 0;
}
