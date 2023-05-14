#include<bits/stdc++.h>

using namespace std;

const int n = 6;
const int s = 63;

struct DienThoai
{
    string NH;
    int KT;
    int giatien;
};

DienThoai dt[6] = {
    {"samSung", 15, 3000},
	{"Oppo", 20, 2000},
	{"Nokia", 12, 1000},
	{"Iphone", 16, 4000},
	{"Bphone", 18, 2000},
	{"Lenovo", 19, 4000},
};

void gopMang(){
	int C[6];
	for(int i = 0; i < n; i++){
		C[i] = dt[i].giatien;
		cout<<C[i]<<endl;
	}
}

void HienThi(int i){
    cout<<dt[i].NH<<"\t"<<dt[i].KT<<"\t"<<dt[i].giatien<<endl;
    if(i < n - 1){
    	HienThi(i + 1);
    }
}

int F[n+1][s+1];

void algorithm(){
	int i, j;
	
	for (j = 0; j <= s; j++) { F[0][j] = 0; }
	
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= s; j++) {
			F[i][j] = F[i - 1][j]; //Khong lay goi thu i
			int temp = F[i - 1][j - dt[i-1].KT] + dt[i-1].giatien;
			if (dt[i-1].KT <= j && F[i][j] < temp) //Lay goi thu i
			F[i][j] = temp;
		}
	}
}

void result(){
	cout<<"Gia tri lon nhat co the lay: " << F[n][s] << endl;
	int i = n, j = s;
	cout<<"Lay cac dien thoai: "<<endl;
	while (i != 0) {
		if (F[i][j] != F[i - 1][j]) {
			cout<<dt[i-1].NH<<"\t"<<dt[i-1].giatien<<endl;
			j = j - dt[i-1].KT; //Lay goi thu i
		}
		i--;
	}
}

void giatri(){
	int count = 0;
	for(int i = 0; i<n; i++){
		if(dt[i].giatien >= 3000 && dt[i].giatien <= 6000){
			count = count + 1;
			//cout<<dt[i].NH<<"\t";
		}
	}
	cout<<count;
}


int main(){
	int C[6];
	cout<<"=============cau a==========="<<endl;
	HienThi(0);
	cout<<"=============cau b==========="<<endl;
	algorithm();
	result();
	cout<<"=============cau c==========="<<endl;
	cout<<"so dien thoai co gia tu 3000 den 6000 la: ";
	giatri();
	cout<<"\n"<<"=============cau d==========="<<endl;
	gopMang();
	
	
}

