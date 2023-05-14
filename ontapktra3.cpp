#include<bits/stdc++.h>
using namespace std;
struct MayTinh{
	string nhanHieu;
	float tocDo;
	float dungLuong;
};
MayTinh m[6] = {
	{"MT01",3.4,500},
	{"MT02",3.5,450},
	{"MT03",3.6,400},
	{"MT04",3.7,300},
	{"MT05",3.8,250},
	{"MT06",3.9,200},
};
int n=6;
void HienThi(int n){
	cout<<m[n].nhanHieu<<"\t"<<m[n].tocDo<<"\t"<<m[n].dungLuong<<endl;
	if(n>0) return HienThi(n-1);
}
int SoMayTinh(double q){
	int dem = 0;
	for(int i = n-1 ; i >= 0 ; i--){
		if(q >= m[i].dungLuong){
			q = q - m[i].dungLuong;
			dem++;
		}
	}	
	
	return dem;
}

int main(){
	HienThi(5);
	double q = 700;
	int temp = SoMayTinh(q);
	cout<<"can it nhat "<<temp<<" may tinh de luu tru "<<q<<" GB"<<endl;
 }
		

