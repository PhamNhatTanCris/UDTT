#include <bits/stdc++.h>
using namespace std;

const int m = 12;
const int n = 6;

struct GoiHang{
	string ma;
	int khoiLuong;
	int giaTien;
};

int vi_tri(GoiHang d[], string key, int l, int r){
	int m = (l + r)/2;
	if(d[m].ma.compare(key) == 0){
		return m;
	} else {
		if(d[m].ma.compare(key) > 0){
			return vi_tri(d, key, l, m-1);
		} else {
			return vi_tri(d, key, m+1, r);
		}
	}
	
	return -1;
}

GoiHang d[6] = {
	{"GH001", 3, 3},
	{"GH002", 1, 2},
	{"GH003", 4, 1},
	{"GH004", 2, 4},
	{"GH005", 6, 2},
	{"GH06", 5, 4},
	};
	
int F[n+1][m+1];

void algorithm(){
	int i, j;
	
	for (j = 0; j <= m; j++) { F[0][j] = 0; }
	
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			F[i][j] = F[i - 1][j]; //Khong lay goi thu i
			int temp = F[i - 1][j - d[i-1].khoiLuong] + d[i-1].giaTien;
			if (d[i-1].khoiLuong <= j && F[i][j] < temp) //Lay goi thu i
			F[i][j] = temp;
		}
	}
}


void result(){
	cout<<"Gia tri lon nhat co the lay: " << F[n][m] << endl;
	int i = n, j = m;
	cout<<"Lay cac goi sau: ";
	while (i != 0) {
		if (F[i][j] != F[i - 1][j]) {
			cout<<d[i-1].ma<<"\t";
			j = j - d[i-1].khoiLuong; //Lay goi thu i
		}
		i--;
	}
}

int char_in_string(char c, string P){
	for(int i = 0 ; i < P.length() ; i++){
		if(P[i] == c){
			return 1;
		}
	}
	
	return -1;
}

int Boyer_Moore_Horspool(string T){
	string P = "H00";
  	int dem = 0, i = P.length(), v = P.length();
  	while (i < T.length()) {
	    int x = v - 1, j = i - 1;
	    while (T[j] == P[x] && x > -1) {
	      j--;
	      x--;
	    }
	    
	    if (x < 0) {
	      dem++;
	      i = i + v;
	    } else {
	      x = char_in_string(T[j], P);
	      
	      if (x < 0) {
	      	i = i + v;
		  } else {
		  	i = i + v - x - 1;
		  }
	    }
  	}
  return dem;
}

bool check(){
	for(int i = 0 ; i < 6 ; i++){
		if(!Boyer_Moore_Horspool(d[i].ma)){
			return false;
		}
	}
	return true;
}

int main(){
	
	int index = vi_tri(d, "GH002", 0, 5);
	if(index != -1){
		cout<<"Vi tri cua goi hang trong danh sach la: "<<index<<endl;
	} else {
		cout<<"Khong tim thay goi hang"<<endl;
	}
	
	algorithm();
	result();
	cout<<endl;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			cout<<F[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	if(check()){
		cout<<"Tat ca cac ma deu chua GH00"<<endl;
	} else {
		cout<<"Khong phai tat ca cac ma deu chua GH00"<<endl;
	}
}
