#include <bits/stdc++.h>
using namespace std;

int a[6] = {0};
int n = 5;

void hien_thi(){
	for(int i = 1 ; i <= n ; i++){
		cout<<a[i];
	}
	cout<<endl;
}

void Try(int i){
	for(int j = 0 ; j <= 1; j++){
		a[i] = j;
		if(i == n){
			hien_thi();
		} else {
			Try(i + 1);
		}
	}
}

int main(){
	Try(1);
}


