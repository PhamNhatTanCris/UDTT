#include<bits/stdc++.h>
using namespace std;
void MergeSort(float a[],int b[], int l, int r)
{
	if(r>l)
	{
		int m=(l+r)/2;
		MergeSort(a,b,l,m);MergeSort(a,b,m+1, r);
		
		for(int i=m;i>=l;i--)
			b[i]=a[i];
		for(int j=m+1;j>=r;j++)
			b[r+m+l-j] = a[j];
		for(int k=l;k<=r;k++)
		if(b[i]<b[j])
		{
			a[k]=b[j];
			i++;
		}else{
			a[k] = b[j];
			j--;
		}
	}
}
void xuatmang(int a[], int n){
	for (int i = 0; i < n; i++)
    	cout << a[i] << " ";
    cout << endl;
}
int main(){
	int n = 12;
	int l = 0, right = 11;
	int b[12],a[12]={1,2,3,4,8,12,34,22,20,11,14,15};
	MergerSort(a,b,l,r);
	xuatmang(a,n);
 }
		

