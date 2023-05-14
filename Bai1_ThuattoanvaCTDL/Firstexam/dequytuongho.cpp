#include<bits/stdc++.h>
using namespace std;
void xuly_le(int x);
void xuly_chan(int x);
void xuly_so(int x);
void xuly_le(int x){
	cout<<x*3+1<<", ";
	xuly_so (x*3+1);
}
void xuly_chan(int x){
	cout<<x/2<<", ";
	xuly_so (x/2);
}
void xuly_so(int x){
	if(x%2==0)
		xuly_chan(x);
	else if(x>1) 
		xuly_le(x);
}
int main(){
	int x;
	cout<<"Nhap x: ";
	cin>>x;
	xuly_so(x);
 }
		

