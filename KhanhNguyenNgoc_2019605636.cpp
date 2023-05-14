#include<bits/stdc++.h>
using namespace std;
//de 1
struct Chuyenbay{
	string sohieu;
	double giave;
	int soghe;
};
int a[6] = {0};
int k=4;
int n=6;
Chuyenbay h[6]={
	{"VN001", 1000000, 100},
	{"VN002", 900000, 200},
	{"VN003", 800000, 300},
	{"VN004", 700000, 400},
	{"VN005", 600000, 500},
	{"VN006", 500000, 600}	
};
double tong(int n){
	if(n==0){
		return h[n].giave;
	}
	else{
		return  h[n].giave + tong(n-1);
	}
}
double p = 1100;
void sochuyen(float p){
	int count = 0;
	int i = n-1;
    while(i>=0){
        if (h[i].soghe <=p){
            p = p - h[i].soghe;
            count =count +1;
        }
        i--;
    }
    cout<<p;
}
void show(){
    for(int i = 1; i <= 4 ; i++){
        cout<<h[a[i] - 1].sohieu<<" ";
    }
    cout<<endl;
} 
void phuongan(int i){
    for(int j = a[i - 1] + 1 ; j <= n - k + i; j++){
        a[i] = j;
        if(i == k){
            show();
        } else {
            phuongan(i + 1);
        }
    }
}
int main(){
	cout<<tong(5)<<endl;
    sochuyen(190);
    cout<<endl<<"Cac cach lay 4 chuyen bay tu danh sach: "<<endl;
    phuongan(1);
} 
