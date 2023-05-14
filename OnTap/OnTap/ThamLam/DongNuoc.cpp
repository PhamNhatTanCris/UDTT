#include <iostream>
using namespace std;

int S[5] = {2, 3, 4, 5, 8};
int n = 5;

int maximum_bottle(int water){
	int count = 0;
	int i = 0;
	
	while(water >= S[i] && i < n){
		water -= S[i];
		count++;
		i++;
	}
	
	return count;
}

int main(){
	int x = maximum_bottle(5);
	if(x != 0){
		cout<<"So chai toi da co the do day: "<< x;	
	} else {
		cout<<"Khong the rot day chai nao";
	}
	
}


