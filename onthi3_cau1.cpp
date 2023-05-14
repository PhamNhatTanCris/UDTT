#include<bits/stdc++.h>
using namespace std;
#define n 6
#define m 20 
int tinh(int *a,int n, int m){
	int i=0, thung_hang=0;
	while(m>0 && i<n){
		if(m>=a[i]){
			m=m-a[i];
			thung_hang++;
		}
		i++;
	}
	return thung_hang;
}
int main(){
	int n = 5;
	int a[n] = {1,2,3,4,5};
	int m = 7;
	if(tinh(a,n,m) == 0){
		cout<<"Khong co phuong an thoa man!!!"<<endl;
	}else{
		cout<<"Can xep len oto tai "<<tinh(a,n,m)<<" thung hang"<<endl;
	}
}

