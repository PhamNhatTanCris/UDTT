#include<bits/stdc++.h>
using namespace std;
int array[9]={1,3,4,5,7,8,9,10,12};
int binarySearch(int array[], int L, int R, int c)
    { 
      	int kq ;
        if (L > R) return -1;
        int mid = (L + R) / 2;
        if (c == array[mid]) 
            return mid;
        if (c < array[mid].luong) 
            return binarySearch(array, L , mid-1, c);
        if (c > array[mid].luong) 
            return binarySearch(array, mid+1 , R, c);
    }
int main(){
	cout<<binarySearch(array, L, R, c);
 }
		

