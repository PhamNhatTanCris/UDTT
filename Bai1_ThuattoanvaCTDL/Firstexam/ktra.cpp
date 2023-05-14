#include<bits/stdc++.h>
using namespace std;
struct HS{
	string ten;
	float diemTB;
	float tienht;
};
HS hs[6];
void HienTHiDS(HS x[], int i){
	cout<<x[i].ten<<"\t"<<x[i].diemTB<<"\t"<<x[i].tienht<<endl;
	if(i>=1){
		i--;
		HienTHiDS(x,i);
	}
	
}
void HienThi(HS x){
	cout<<x.ten<<"\t";
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
		HS tg = hs[x[i]];
		HienThi(tg);
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
	hs[0]={"huynh", 6, 1234};
	hs[1]={"Hoang", 7, 2345};
	hs[2]={"Kha", 10, 1235};
	hs[3]={"Minh", 6, 2345};
	hs[4]={"Linh", 8, 1234};
	hs[5]={"Manh", 9, 1222};
	HienTHiDS(hs,5);
	listing_config(6);
 }
		

