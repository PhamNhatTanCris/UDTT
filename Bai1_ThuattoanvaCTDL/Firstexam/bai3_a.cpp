#include<bits/stdc++.h>
using namespace std;
int tongCacChuSo(int x){
	int a = x/10;
	int b = x%10;
	if (a<0)
		return 0;
	else if (a>0){
		return (tongCacChuSo(a) + b);
	}
}
main(){
	int n;
	cout<<"Nhap n: "; 
	cin>>n;
	int kq=	tongCacChuSo(n);
	cout<<"Tong cac chu so cua so vua nhap: "<<kq<<endl;
}
