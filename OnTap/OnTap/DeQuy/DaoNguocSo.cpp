#include<bits/stdc++.h>
using namespace std;

int DaoNguocSo(int n, int revN){
	if(n == 0) {
		return revN;
	} else {
		revN = revN * 10 + n % 10;
		return DaoNguocSo(n / 10, revN);
	}
}

int main(){
	int n;
	cout<<"Nhap N: "; cin>>n;
	cout<<"So n sau khi dao nguoc: "<<DaoNguocSo(n, 0);
}
