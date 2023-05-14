#include <bits/stdc++.h>
using namespace std;
 
int binarySearch(int A[], int key, int left, int right)
{
    if(left > right) 
        return -1; 
    else{

        int mid = (left + right) / 2;

        if(A[mid] == key) 
            return mid;
        if(A[mid] > key) 
            return binarySearch(A, key, left, mid - 1);
        if(A[mid] < key) 
            return binarySearch(A, key, mid + 1, right);
        }
}

int main() {
 	int arr[] = {1, 3, 4, 5, 7, 8, 9, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int c = 3;
     
    sort(arr, arr+n);
    int result = binarySearch(arr, c, 0, n-1);
 
    cout << result;
}
