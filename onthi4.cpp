#include<bits/stdc++.h>
using namespace std;
struct CongNhan{
	string hoTen;
	float luong;
};
CongNhan d[10] = {
	{"Nguyen Van A", 100000},
	{"Nguyen Van B", 90000},
	{"Nguyen Van C", 80000},
	{"Nguyen Van D", 70000},
	{"Nguyen Van E", 60000},
	{"Nguyen Van F", 50000},
	{"Nguyen Van G", 40000},
	{"Nguyen Van H", 30000},
	{"Nguyen Van E", 20000},
	{"Nguyen Van K", 10000}
};
int binary_search(CongNhan arr[], int l, int r, CongNhan cn)
{
    double x = cn.luong;
    int kq;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // if (arr[mid] == x)
        //     return mid;
        if (x > arr[mid].luong)
            r = mid - 1;

        else
            l = mid + 1;
        kq = r;
    }
    return kq;
}
int n = 0;
void show_list(int n){
	cout<<d[n].hoTen<<"\t"<<d[n].luong<<endl;
	if(n < 10) return show_list(n + 1);
}
int main(){
	
	CongNhan cn = {"Nguyen Van L", 45000};
	
	cout<<divide_and_conqueror(d, n, cn);
	show_list(9);
	
}

