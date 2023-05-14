#include<bits/stdc++.h>
using namespace std;
#define n 6

struct LopHoc{
	string hoTen;
	int soHS;
	int soHSN;
	int phuCap;
};
	
LopHoc d[7] = {
	{"Nguyen Van Trong Kha", 8, 6,  5},
	{"Thi Thu Hang", 		 6, 6,  6},
	{"Pham Quoc Huy", 		 7, 4,  7},
	{"Bui Thi Manh", 		 5, 3,  8},
	{"Nguyen Thi Huynh", 	 4, 4,  9},
	{"Tran Tuan Minh", 		 3, 2, 10},
	{"Bui Van Thi", 		 3, 0,  7}
};
int binarySearch(LopHoc d[], int L, int R, int c)
    { 
      
        if (L > R) return -1;
        int mid = (L + R) / 2;
        if (d[mid].soHS - d[mid].soHSN == c) 
            return mid;
        if (d[mid].soHS - d[mid].soHSN > c) 
            return binarySearch(d, L , mid-1, c);
        if (d[mid].soHS - d[mid].soHSN < c) 
            return binarySearch(d, mid+1 , R, c);
    }
int main(){
	int index = binarySearch(d, 0, 6, 0);
	if(index != -1){
		cout<<"Lop khong co hoc sinh nam: ";
		cout<<d[index].hoTen<<endl;
	}else{
		cout<<"Tat ca cac lop deu co hoc sinh nam";
	}
}

