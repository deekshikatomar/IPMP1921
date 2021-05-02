#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i] == i)
			return i;
	}

	
	return -1;
}
int main()
{
	int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Fixed Point is " << linearSearch(arr, n);
	return 0;
}


