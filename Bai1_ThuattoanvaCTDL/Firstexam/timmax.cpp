#include<bits/stdc++.h>
using namespace std;
void max(int a[],int l, int r, int &M)
{
	int M1,M2;
	if(l==r)
	{
		M=a[l];
	}
	else
	{
		max(a,l,(l+r)/2,M1);
		max(a,(l+r)/2+1,r,M2);
		if(M1 > M2)
			M = M1;
		else
			M = M2;
	}
}
int main(){
	int a[10] = {1,2,4,7,8,4,3,9};
	int M;
	max(a,0,9,M);
	cout<<"Max = "<<M;
	return 0;
 }
		

