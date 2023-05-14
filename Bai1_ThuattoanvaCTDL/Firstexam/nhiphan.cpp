#include<bits/stdc++.h>
using namespace std;
int n;
int x[100];
void show(int a[]){
	for (int i=1; i<=n; i++){
		cout<<a[i];
	}
	cout<<endl;
}
void Try(int k){
	for (int i=0; i<=1; i++){
		x[k] = i;
		if (k==n){
			show(x);
		}
		else{
			Try(k+1);
		}
	}
}
main(){
	cout<<"Nhap n: "; 
	cin>>n;
	Try(1);
}

