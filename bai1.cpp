#include<bits/stdc++.h>
using namespace std;
const int n = 10;

float a[n] = {120000, 200000, 300000, 400000, 500000,
 			550000, 600000, 650000, 700000, 800000};

int HienThi(float a[], int n){
	if(n == -1){
		return 0;
	}
	cout<<a[n]<<setw(8);
	HienThi(a,n-1);
	
}
int TinhTong(float a[],int i){
	if(i == -1)
		return 0;
	if(a[i] > 0)
		return a[i] + TinhTong(a,i-1);
	return TinhTong(a,i-1);
}
int main(){
	HienThi(a,n - 1);
	cout<<"\nTrung binh cong cua cac so duong trong mang a la: "<<TinhTong(a,n-1)<<endl;
}

