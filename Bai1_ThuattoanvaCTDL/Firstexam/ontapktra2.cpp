#include<bits/stdc++.h>
#define n 5
#define m 12
using namespace std;

struct GoiHang{
	string maGoi;
	float khoiLuong;
	double giaTien;
};
GoiHang d[6] = {
	{"GH001",30,300000},
	{"GH002",35,400000},
	{"GH003",45,500000},
	{"GH004",70,600000},
	{"GH005",60,700000},
	{"GH006",50,800000},
};
int timKiem(GoiHang d[],string x ,int left, int right)
    { 
        int mid = (left + right) / 2;
        if (d[mid].maGoi.compare(x) == 0) {
        	 return mid;
		}else{
			if (d[mid].maGoi.compare(x) > 0){
        	 	return timKiem(d ,x ,left , mid-1);
			}else{
        	 	return timKiem(d ,x ,mid+1 , right);
			}
           
		}
    	return -1;
    }
int main(){
    int c = timKiem(d, "GH004", 0, 5);
    if(c != -1){
    	cout<<"Vi tri cua goi hang la: "<<c<<endl;
	}else{
		cout<<"Khong tim thay goi hang"<<endl;
	}
 }
		

