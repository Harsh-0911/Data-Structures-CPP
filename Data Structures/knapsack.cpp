# include<iostream>
using namespace std;

int knapsack (int w[], int v[], int c, int n)
{
	if (c == 0 || n == 0)
	{
		return 0;
	}
	
	if (w[n-1] <= c)
	{
		return max(v[n-1] + knapsack(w, v, c-w[n-1], n-1), knapsack(w, v, c, n-1));
	}
	else if (w[n-1] > c)
	{
		return knapsack(w, v, c, n-1);
	}
}


int main() 
{
	int weight[] = {1, 3, 4, 5};
	int value[] = {1, 4, 5, 7};
	int W = 7;
	int n = 4;
		
	int profit = knapsack(weight, value, W, n);
	cout << "Total Profit : " << profit <<"$";
	
	return 0;
}
