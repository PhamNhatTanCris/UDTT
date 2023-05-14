#include<bits/stdc++.h>
using namespace std;
struct ChuyenBay{
	string soHieu;
	double giaVe;
	int soGhe;
};
ChuyenBay b[6]={
	{"VN005",70000,24},
	{"VN006",60000,23},
	{"VN007",50000,25},
	{"VN008",40000,26},
	{"VN009",30000,27},
	{"VN001",20000,28},
};
int n=6;
double Tong(int n){
	if(n==0){
		return b[n].giaVe;
	}
	else{
		return b[n].giaVe + Tong(n-1);
	}
}
int SoChuyenBay(double p){
	int dem = 0;
	for(int i = n-1;i>=0;i--){
		if(p>=b[i].soGhe){
			p = p - b[i].soGhe;
			dem++;
		}
	}
	return dem;
}
int a[6] = {0};
int k = 4;
void HienThi(){
	for(int i=1;i<=4;i++){
		cout<<b[a[i]-1].soHieu<<" ";
	}
	cout<<endl;
}
void quaylui(int i){
	for(int j = a[i - 1] + 1;j <= n - k + i;j++){
		a[i] = j;
		if(i == k){
			HienThi();
		}else{
			quaylui(i + 1);
		}
	}
}
int main(){
	cout<<"Tong gia ve: "<<Tong(5);
	double p = 81;
	int temp = SoChuyenBay(p);
	cout<<"\nCan it nhat "<<temp<<" chuyen bay de cho duoc dung "<<p<<" Khach"<<endl;
	quaylui(1);
 }
		

