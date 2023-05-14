#include <iostream>
#include <math.h>
#define max 100
using namespace std;

int arr[max] = {0};

int fibonacci(int n){
	if(n == 0 || n == 1){
		arr[n] = 1;
		return 1;
	} else {
		if(arr[n] == 0){
			arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
		}
		return arr[n]; 
	}
}

int main(){
	fibonacci(7);
	int sum = 0;
	for(int i = 0 ; i < 7 ; i++){
		cout<<arr[i]<<" ";
		sum += arr[i];
	}
	cout<<"\n";
	cout<<sum;
	
}

