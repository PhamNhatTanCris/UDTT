#include<bits/stdc++.h>
#define n 6
#define m 12
using namespace std;
struct GoiHang{
	string maGoi;
	int khoiLuong;
	double giaTien;
};
GoiHang d[6] = {
	{"GH001", 2, 30000},
	{"GH002", 4, 40000},
	{"GH003", 3, 50000},
	{"GH004", 6, 60000},
	{"GH005", 7, 70000},
	{"GH006", 8, 80000},
};
int ViTri(GoiHang d[],string x, int left, int right)
{
	if(left > right) return -1;
	int mid = (left + right)/2;
	if(d[mid].maGoi.compare(x) == 0){
		return mid;
	}else{
		if(d[mid].maGoi.compare(x) > 0){
			return ViTri(d, x, left, mid - 1);
		}else{
			return ViTri(d, x, mid + 1, right);
		}
	}
}
int F[n+1][m+1];
void QuyHoachDong(){
	int i, j;
	
	for( j = 0; j <= m; j++){
		F[0][j] = 0;
	}
	for( i =1; i <= n; i++){
		for( j = 0;j <= m; j++){
			F[i][j] = F[i - 1][j];
			float temp = F[i - 1][j - d[i-1].khoiLuong] + d[i-1].giaTien;
			if(d[i-1].khoiLuong <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}
void KetQua(){
	cout<<"Gia tri lon nhat: "<<F[n][m]<<endl;
	int i = n, j = m;
	cout<<"Lay cac goi sau ";
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			cout<<d[i-1].maGoi<<"\t";
			j = j - d[i-1].khoiLuong;
		}
		i--;
	}
}
int char_in_string(char c, string P){
	for(int i = 0; i < P.length(); i++){
		if(P[i] == c){
			return 1;
		}
	}
	return -1;
}
int Boyer_Moore_Horspool(string T){
	string p = "H00";
	int dem = 0, i = p.length(), v = p.length();
	while(i<T.length()){
		int x = v-1, j=i-1;
		while(T[j] == p[x] && x > -1){
			j--; x--;
		}
		if(x<0){
			dem++;
			i = i+v;
		}
		else{
			x = char_in_string(T[j], p);
			if(x<0)
				i= i+v;
			else
				i=i+v-x-1;
		}
	}
	return dem;
}
bool check(){
	for(int i = 0; i < 6; i++){
		if(!Boyer_Moore_Horspool(d[i].maGoi)){
			return false;
		}
	}
	return true;
}
int main(){
	int key = ViTri(d, "GH04", 0, 5);
	if(key != -1){
		cout<<"Vi tri cua goi hang trong danh sach la: "<<key<<endl;
	} else {
		cout<<"Khong tim thay goi hang"<<endl;
	}
	QuyHoachDong();
	KetQua();
	cout<<endl;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			cout<<F[i][j]<<"\t";
		}
		cout<<endl;
	}
	if(check()){
		cout<<"Tat ca cac ma deu chua H00"<<endl;
		
	}else{
		cout<<"Khong phai tat ca cac ma deu chua H00";
	}
 }
		

