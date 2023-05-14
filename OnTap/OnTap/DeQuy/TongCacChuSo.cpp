#include<bits/stdc++.h>
using namespace std;

int TongCacChuSo(int n){
	if(n < 10) {
		return 1;
	}
	else {
		return n % 10 + TongCacChuSo(n / 10);
	}
}

int main(){
	int n;
	cout<<"Nhap N: "; cin>>n;
	cout<<"Tong cac chu so cua n la: "<<TongCacChuSo(n);
}
