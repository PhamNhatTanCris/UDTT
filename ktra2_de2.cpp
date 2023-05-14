#include<bits/stdc++.h>
using namespace std;
struct HocSinh{
	string hoTen;
	int Tuoi;
	float diemTK;
};
HocSinh d[7] = {
	{"Nguyen Huynh", 12, 3},
	{"Nguyen Hoang", 14, 4},
	{"Tran Minh", 13, 5},
	{"Bui Manh", 16, 6},
	{"Diep Hang", 17, 7},
	{"Ngoc Khanh", 18, 8},
	{"Trong Kha", 20, 10},
};
int ViTri(HocSinh d[],float x, int left, int right)
{
	if(left > right) return -1;
	int mid = (left + right)/2;
	if(x == d[mid].diemTK){
		return mid;
	}else{
		if(x < d[mid].diemTK){
			return ViTri(d, x, left, mid - 1);
		}else{
			return ViTri(d, x, mid + 1, right);
		}
	}
}
int main(){
	int key = ViTri(d, 10, 0, 6);
	if(key != -1){
		cout<<"Hoc sinh co diem TK cao nhat la: "<<d[key].hoTen<<endl;
	}
}

