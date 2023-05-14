#include <iostream>
using namespace std;

int S[5] = {2, 3, 4, 5, 8};
int n = 5;

int maximum_bottle(int water){
	int count = 0;
	int i = 0;
	
	while(water > 0 && i < n){
		if(water > S[i]){
			water -= S[i];
			count++;
		}
		i++;
	}
	
	return count;
}

int main(){
	cout<<maximum_bottle(10);
}
