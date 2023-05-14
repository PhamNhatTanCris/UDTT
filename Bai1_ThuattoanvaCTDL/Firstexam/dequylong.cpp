#include<bits/stdc++.h>
using namespace std;
long Acker(int m, int n)
{
	if(m == 0)
		return (n+1);
	else if(n == 0)
		return Acker(m - 1, 1);
	else
		return Acker(m - 1, Acker(m, n - 1));
}
int main(){
	int m,n;
	cout<<"Nhap m: ";cin>>m;
	cout<<"Nhap n: ";cin>>n;
	cout<<Acker(m,n);
 }
		

