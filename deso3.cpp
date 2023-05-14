#include<bits/stdc++.h>
using namespace std;
struct MayTinh{
	string local;
	double money;
	double giaban;
};
int n = 6;
MayTinh m[6]={
	{"HP", 50000, 60000},
	{"Dell", 40000, 50000},
	{"ASUS", 50000, 70000},
	{"Samsung", 50000, 80000},
	{"iphone", 50000, 90000},
	{"nokia", 50000, 100000},
};
void hienthi(int i){
	cout<<m[i].local<<"\t"<<m[i].money<<"\t"<<m[i].giaban<<endl;
	if(i < n - 1) {
		return hienthi(i + 1);
	}
}
int min(double q){
	int count = 0;int i = n-1;
	while(i>=0){
		if(m[i].giaban <= q){
			q = q - m[i].giaban;
			count = count + 1;
		}
		i = i - 1;
	}
	if(q > 0){
		cout<<"khong hop le!!!";
			return 0;
	}else return count;
	
}
int main(){
	cout<<"Danh sach may tinh la: "<<endl;
	hienthi(0);
	double q = 190000;
	int temp = min(q);
	cout<<"so may can ban la: "<<temp;
 }
		

