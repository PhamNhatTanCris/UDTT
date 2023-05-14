#include <iostream>
using namespace std;

int x[6] = {0};
int n = 5;
int mark[5] = {0};
int count = 1;

void show(int x[]){
	cout<<count++<<". ";
	for(int i = 1 ; i <= n ; i++){
		cout<<x[i];
	}
	cout<<endl;
}

void quay_lui(int k){
	for(int i = 1 ; i <= n ; i++){
		if(mark[i] == 0){
			x[k] = i;
			if(k == n){
				show(x);
			} else {
				mark[i] = 1;
				quay_lui(k+1);
				mark[i] = 0;
			}
		}
	}
}

void quay_lui_1(int k){
	for(int i = 0 ; i <= 1 ; i++){
		x[k] = i;
		if(k == n){
			show(x);
		} else {
			quay_lui_1(k+1);
		}
	}
}

int main(){
	quay_lui_1(1);
}

