# include<iostream>
using namespace std;

int main()
{
	int w[] = {1, 3, 4, 5};
	int v[] = {1, 4, 5, 7};
	int W = 7;
	int n = 4;
	
	int t[n+1][W+1];
	
	// Initialization of Matrix..
	for (int i=0; i<n+1; i++)
	{
		for (int j=0; j<W+1; j++)
		{
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}
	
	// n=i, w=j
	for (int i=1; i<n+1; i++)
	{
		for (int j=1; j<W+1; j++)
		{
			if (w[i-1] <= j)
			{
				t[i][j] = max(v[i-1] + t[i-1][j-w[i-1]], t[i-1][j]);
			}
			else if (w[i-1] > j)
			{
				t[i][j] = t[i-1][j];
			}
		}
	}
	cout << "Table is : " << endl;
	for (int i=0; i<n+1; i++)
	{
		for (int j=0; j<W+1; j++)
		{
			printf("%3d", t[i][j]);
		}
		cout << endl;
	}
	cout << endl << "Answer is : " << t[4][7];
	return 0;
}
