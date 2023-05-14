#include<bits/stdc++.h>
using namespace std;
struct Hocsinh{
	string tenHS;
	float score;
	double money;
};
Hocsinh h[6]={
	{"Kha", 10, 10000},
	{"Huynh", 7, 20000},
	{"Hoang", 8, 30000},
	{"Minh", 6, 40000},
	{"Hang", 9, 50000},
	{"Khanh", 6, 60000},
};
int n=6;
void hienthi(int n){
	cout<<h[n].tenHS<<"\t"<<h[n].score<<"\t"<<h[n].money<<endl;
	if(n > 0) return hienthi(n -1);
}
int max(double p, int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(p >= h[i].money){
			p = p - h[i].money;
			count++;
		}
	}
	return count;
}
void HienthiDS(Hocsinh x){
	cout<<x.tenHS<<"\t";
}
int a[6]={0,1,2,3,4,5};
void swap(int &a, int &b){
	int tg=a;
	a=b;
	b=tg;
}
void view_config(int x[], int n){
	cout<<"\n";
	for(int i=0;i<n;i++){
		Hocsinh tg = h[x[i]];
		HienthiDS(tg);
	}
}
void Next_Config(int x[], int i, int n){
	int k =n-1;
	while(x[k] < x[i]){
		k--;
	}
	swap(x[i], x[k]);
	int j=n-1;i++;
	while(i < j){
		swap(x[i],x[j]);
		i++;
		j--;
	}
}
void listing_config(int n){
	int i, x[n + 1] = {0};
	for (i = 0; i < n; i++) { x[i] = i; }
	do {
		cout<<"\n";
		view_config(x, n); 
		i = n - 2;
		while (i >= 0 && x[i] > x[i + 1]) i --;
		if (i >= 0) { 
			Next_Config(x, i, n);
		}
	} while (i >= 0);
}

int main(){
	cout<<"Hien thi danh sach: "<<endl;
	hienthi(5);
	double p = 200000;
	cout<<"Lay nhieu nhat "<<max(p, 5)<<" hoc sinh de so tien khong vuot qua"<<p<<endl;
	cout<<"Cac cach xep 6 hoc sinh vao ban tron la: "<<endl;
	listing_config(5);
 }
		

