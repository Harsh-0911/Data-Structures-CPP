# include<iostream>
using namespace std;

int t[10][10];

int knapsack (int w[], int v[], int c, int n)
{
	if (c == 0 || n == 0)
	{
		return 0;
	}
	
	if (t[n][c] != -1)
	{
		return t[n][c];
	}
	
	if (w[n-1] <= c)
	{
		return t[n][c] = max(v[n-1] + knapsack(w, v, c-w[n-1], n-1), knapsack(w, v, c, n-1));
	}
	else if (w[n-1] > c)
	{
		return t[n][c] = knapsack(w, v, c, n-1);
	}
}

int main() 
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			t[i][j] = -1;
		}
	}
	
	int weight[] = {1, 3, 4, 5};
	int value[] = {1, 4, 5, 7};
	int W = 7;
	int n = 4;
		
	cout << "Matrix initialized with (-1)" << endl;
	int profit = knapsack(weight, value, W, n);
	
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			printf("%4d", t[i][j]);
		}
		cout << "\n";
	}
	cout << endl << "Total Profit : " << profit <<"$\n";
	
	return 0;
}
