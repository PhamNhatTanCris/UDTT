#include<bits/stdc++.h>
using namespace std;
struct MayTinh{
	string local;
	double money;
	double giaban;
};
int n = 6;
MayTinh m[6]={
	{"HP", 50000, 60000},
	{"Dell", 40000, 50000},
	{"ASUS", 50000, 70000},
	{"Samsung", 50000, 80000},
	{"iphone", 50000, 90000},
	{"nokia", 50000, 100000},
};
void hienthi(int i){
	cout<<m[i].local<<"\t"<<m[i].money<<"\t"<<m[i].giaban<<endl;
	if(i < n - 1) {
		return hienthi(i + 1);
	}
}
int min(double q){
	int count = 0;int i = n-1;
	while(i>=0){
		if(m[i].giaban <= q){
			q = q - m[i].giaban;
			count = count + 1;
		}
		i = i - 1;
	}
	if(q > 0){
		cout<<"khong hop le!!!";
			return 0;
	}else return count;
	
}
void HienthiDS(MayTinh x){
	cout<<x.local<<"\t";
}
int a[6]={0,1,2,3,4,5};
void swap(int &a, int &b){
	int tg=a;
	a=b;
	b=tg;
}
void view_config(int x[], int n){
	for(int i=0;i<n;i++){
		MayTinh tg = m[x[i]];
		HienthiDS(tg);
	}
	cout<<"\n";
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
	int dem = 1;
	for (i = 0; i < n; i++) { x[i] = i; }
	do {
		cout<<dem<<".";
		view_config(x, n); 
		i = n - 2;
		while (i >= 0 && x[i] > x[i + 1]) i --;
		if (i >= 0) { 
			Next_Config(x, i, n);
			dem = dem + 1;
		}
	} while (i >= 0);
}
int k = 5;
int b[5] = {0,1,2,3,4};
void next_config1(int x[],int k, int i){
	x[i] = x[i] + 1;
	i++;
	while(i<k){
		x[i] = x[i - 1] + 1;
		i++;
	}
}
void listing_config1(int n, int k){
	int i = k-1;
	do{
		view_config(b, k);
		while(i>=0 && b[i] == n - k + i)
		{
			i--;
		}
		if(i>=0){
			next_config1(b,k,i);
		}
	}while(i>=0);
}
int main(){
	cout<<"Danh sach may tinh la: "<<endl;
	hienthi(0);
	double q = 190000;
	int temp = min(q);
	cout<<"so may can ban la: "<<temp;
	listing_config(6);
	cout<<"=======Cach chon 5 tu 6 may======="<<endl;
	listing_config1(6,5);
 }
		

