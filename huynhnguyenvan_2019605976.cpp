
#include<bits/stdc++.h>
using namespace std;
struct Chuyenbay{
	string soHieu;
	double giaVe;
	int soGheNgoi;
};
Chuyenbay b[6]={
	{"VN001", 400000, 30},
	{"VN002", 500000, 31},
	{"VN003", 600000, 32},
	{"VN004", 700000, 33},
	{"VN005", 800000, 34},
	{"VN006", 900000, 35},
};
int n = 6;
int k = 4;
int a[6] = {0};
double TongGiaVe(int n){
    if (n==0){
        return b[n].giaVe;
    }else{
        return b[n].giaVe + TongGiaVe(n-1);
    }
}
//Khoi tao so thuc duong p
int SoChuyenBay(double p){
	int count = 0;
	int i = n-1;
	while(i >= 0){
		if(b[i].soGheNgoi <= p){
			p = p - b[i].soGheNgoi;
			count = count + 1;
		}
		i = i - 1;
	}
	if(p > 0){
		cout<<"Khong hop le!!!";
		return 0;
	}else return count;
}
void show(){
    for(int i = 1; i <= 4 ; i++){
        cout<<b[a[i] - 1].soHieu<<" ";
    }
    cout<<endl;
} 
void ChonChuyenBay(int i){
    for(int j = a[i - 1] + 1 ; j <= n - k + i; j++){
        a[i] = j;
        if(i == k){
            show();
        } else {
            ChonChuyenBay(i + 1);
        }
    }
}
int main(){
	cout<<"Tong gia ve: "<<TongGiaVe(5);
	double p = 101;
	int temp = SoChuyenBay(p);
	cout<<"Can it nhat "<<temp<<" chuyen bay de cho duoc dung "<<p<<" khach"<<endl;
	cout<<"Cac cach chon ra 4 chuyen bay tu danh sach b: "<<endl;
	ChonChuyenBay(1);
 }
		

