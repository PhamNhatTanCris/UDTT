#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
int l[100];
int T[100];
int algorithm(){
	a[0]=-2147483648;
	a[n+1]=2147483648;
	l[n+1]=1;
	for(int i=n;i>=0;i--){
		int jmax=n+1;
		for(int j=i+1;j<=n+1;j++){
			if(a[j]>a[i]&&l[j]>l[jmax])
				jmax=j;
		}
		l[i]=l[jmax]+1;
		T[i]=jmax;
	}
	int k=T[0];
	cout<<endl;
	while(k!=n+1){
		cout<<a[k]<<"  ";
		k=T[k];
	}
}

int main(){
	cout<<"Nhap n: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap a["<<i<<"]= ";
		cin>>a[i];
	}
	algorithm();
}	

