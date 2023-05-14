#include<bits/stdc++.h>
using namespace std;
struct LopHoc{
	string tenGV;
	double soHS;
	double soHSNu;
	double phuCap;
};
LopHoc d[]={
	{"Nguyen Van A", 29, 20, 300000},
	{"Nguyen Van B", 30, 24, 400000},
	{"Nguyen Van C", 31, 28, 500000},
	{"Nguyen Van D", 32, 32, 600000},
	{"Nguyen Van E", 36, 33, 350000},
	{"Nguyen Van F", 38, 34, 700000},
	{"Nguyen Van G", 40, 36, 800000},
};
int n=6;
int TenGV(LopHoc d[],int x, int left, int right)
{
	if(left > right) return -1;
	int mid = (left + right)/2;
	if(x == d[mid].soHS){
		return mid;
	}else{
		if(x < d[mid].soHS){
			return TenGV(d, x, left, mid - 1);
		}else{
			return TenGV(d, x, mid + 1, right);
		}
	}
}
int main(){
	for(int i=0; i <= 6; i++){
		int key = TenGV(d, x, 0, 6);
	}
	if(key != -1){
		cout<<"Ten giao vien phu trach cua lop khong co hoc sinh nam: "<<d[key].tenGV<<endl;
	} else {
		cout<<"Khong co lop nao khong co hoc sinh nam!!!"<<endl;
	}
	
	
}
	

