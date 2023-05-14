#include <iostream>
using namespace std;

struct KienHang{
	int trongLuong;
	int theTich;
	float tiLe;
	int pa;
};

int K = 37; //kich thuoc thung xe
int n = 4; //so kien hang
int m[4] = {25, 30, 6, 2}; //trong luong cua tung kien hang
int k[4] = {10, 15, 4, 2}; //the tich cua cac kien hang

float tl[4] = {2.5, 2.0, 1.5, 1.0}; //ti le trong luong tren moi don vi the tich
int solution[4] = {0};

void tham_lam(){
	for(int i = 0; i < n ; i++){
		if(K >= k[i]){
			solution[i] = 1;
			K = K - k[i];
		}
	}
}

int main(){
	tham_lam();
	for(int i = 0 ; i < n; i++){
		if(solution[i]){
			cout<<"Kien hang "<< i + 1 <<" Khoi luong: "<<m[i]<<" The tich: "<<k[i]<<endl;
		}
	}
}
