#include<bits/stdc++.h>
using namespace std;
void next_config(int x[], int n, int i){
	x[i] += 1;
	i++;
	while(i<=n){
		x[i] = x[i - 1] + 1;	
		i++;
	}
}
void view_config(int x[], int n){
	for (int i = 1; i<=n ; i++)
		cout<<x[i];
	cout<<endl;
}
void listing_configs(int k, int n){
	int i;
	int x[n + 1];
	// cau hinh dau tien{1 2 ... k}
	for(int i = 1; i <= k;i++){
		x[i] = i;
	}
	do{
		view_config(x,k);
		i = k;
		while(i>0 && x[i] == n - k + i){
			i --;
		}
		if(i>0){
			next_config(x, k, i);
		}
	}while(i > 0);
}
int main(){
	int n, k;
	cout<<"do dai day S, n = ";
	cin>>n;
	cout<<"do dai day con, k = ";
	cin>>k;
	listing_configs(k,n);
 }
		

