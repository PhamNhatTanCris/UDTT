#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int n, int c)
{
	int L=0, R = n-1, M;
	do
	{
		M = (L+R)/2;
		if(a[M] > c) 
			R = M-1;
		if(a[M] < c)
			L = M+1;
	}while(a[M] != c && L<R);
	if(a[M] == c)
		return M;
	else
		return -1;
}
int main(){
	int arr[] = {1, 3, 4, 5, 7, 8, 9, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int c = 3;
    int result = binarySearch(arr, n, c);
 	if (result != -1) {
    printf("%d xuat hien tai chi so %d", c, result);
  	} else {
    printf("%d khong co trong mang ", c);
  	}
 }
		

