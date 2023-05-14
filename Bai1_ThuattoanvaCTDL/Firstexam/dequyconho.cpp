#include<bits/stdc++.h>
using namespace std;
int d[5][5] = {
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1}
};
long C(int k, int n){
	if(k == 0 || k == n)
		d[k][n] = 1;
	else if(d[k][n]< 0)
		d[k][n] = C(k, n-1) + C(k-1, n-1);
	return d[k][n];
}

int main(){
	int k,n;
	cout<<"Nhap k: ";cin>>k;
	cout<<"Nhap n: ";cin>>n;
	cout<<C(k,n);
 }



