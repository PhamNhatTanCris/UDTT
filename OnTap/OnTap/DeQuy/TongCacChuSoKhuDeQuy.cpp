#include<bits/stdc++.h>
using namespace std;

int TongCacChuSo(int n){
	int sum = 0;
	
	while(n > 10){
		sum += n % 10;
		n = n / 10;
	}
	sum += n;
	
	return sum;
}

int main(){
	int n;
	cout<<"Nhap N: "; cin>>n;
	cout<<"Tong cac chu so cua n la: "<<TongCacChuSo(n);
}
