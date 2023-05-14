#include <bits/stdc++.h>
using namespace std;

int count = 1;
int x[6] = {0};
int n = 3;
int mark[6] = {0};

void show(int x[]){
	//cout<<count++<<". ";
	for(int i = 1 ; i <= n ; i++){
		cout<<x[i];
	}
	cout<<endl;
}

// liet ke hoan vi
void quay_xe(int k){
	for(int i = 1 ; i <= n ; i++){
		if(mark[i] == 0){
			x[k] = i;
			if(k == n){
			show(x);
			} else {
				mark[i] = 1;
				quay_xe(k+1);
				mark[i] = 0;
			}
		}
	}
}

int main(){
	quay_xe(1);
}
