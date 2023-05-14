#include<bits/stdc++.h>
using namespace std;
struct TaiSan{
	string tenTS;
	double giaTri;
	string tinhTrang;
};
TaiSan t[5] = {
 	{"tivi",70000,"cu"},
 	{"tulanh",60000,"moi"},
 	{"dieuhoa",50000,"moi"},
 	{"maygiat",40000,"cu"},
 	{"quat",30000,"hong"},
 };
 int n = 5;
long Tong(TaiSan *t,long &tong,int n){
	if(n==0)
	{
		return tong + t[0].giaTri;
	}
	else if(t[n].tinhTrang.compare("hong") == 0)
	{ return Tong(t,tong,n-1);}
	else
	{
		tong += t[n].giaTri;
		return Tong(t,tong,n-1);
	}
}
int SoTaiSan(double p){
	int dem = 0;
	for(int i = n-1; i>=0; i--){
		if(p >= t[i].giaTri){
			p = p - t[i].giaTri;
			dem++;
			cout<<t[i].tenTS<<" ";
		}
	}
	return dem;
}
int main(){
	long tong = 0;
	cout<<"Tong gia tri: "<<Tong(t, tong, 0)<<endl;
	double p = 120000;
	int temp = SoTaiSan(p);
	cout<<"Can ban it nhat "<<temp<<" tai san tren de vua du so tien hoc phi "<<p<<endl;
 }
		

