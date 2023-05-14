#include<bits/stdc++.h>
using namespace std;
int Tong(int n,int *a,int i){
	if(i == n) return 0;
	return a[i] + Tong(n,a,i+1);
}
int tinh(int *a,int n, int m){
	int i=0, so_xe=0;
	while(m>0 && i<n){
		if(m>=a[i]){
			m=m-a[i];
			so_xe++;
		}
		i++;
	}
	return so_xe;
}
int main(){
	int n = 5;
	int a[n]={1,2,3,4,5}; 
	int m = 4;
	int check[n] = {0};
	cout<<"Tong trong tai cua tat ca cac oto: "<<Tong(n,a,0)<<endl;
	if(tinh(a,n,m)==0) cout<<"Khong co phuong phap thoa man!"<<endl;
	else if(tinh(a,n,m)==n) cout<<"Can dung tat ca cac xe"<<endl;
	else cout<<"can dung "<<tinh(a,n,m)<<" xe de van chuyen"<<endl;
	return 0;
}

