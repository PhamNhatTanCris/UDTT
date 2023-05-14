#include<bits/stdc++.h>
using namespace std;
struct CongViec{
	string maCV;
	float tBD;
	float tKT;
};
CongViec c[6] = {
	{"CV01",1,3},
	{"CV02",3,5},
	{"CV03",5,8},
	{"CV04",8,9},
	{"CV05",9,12},
	{"CV06",12,15},
};
int n=6;
void HienThi(int n){
	cout<<c[n].maCV<<"\t"<<c[n].tBD<<"\t"<<c[n].tKT<<endl;
	if(n>0) return HienThi(n-1);
}
void SoCongViec(double q){
	int dem = 0;
	for(int i = n-1;i>=0;i--){
		if(q>=(c[i].tKT-c[i].tBD)){
			q = q - (c[i].tKT-c[i].tBD);
			dem++;
		}
	}
	return dem;
}
int main(){

	HienThi(5);
	double q = 8;
	int temp = SoCongViec(q);
	cout<<"\nMot nguoi thuc hien trong 8 gio duoc "<<temp<<" cong viec";
 }
		

