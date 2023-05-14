#include<bits/stdc++.h>
using namespace std;
int a[9] = {0,2,1,-1,-2,-2,-2,1,2};
int b[9] = {0,1,2,3,1,-1,-2,-2,-1};
int **H;
int n;
void Try(int k, int x, int y, int &success){
	int u, v, suc1;
	int i =0;
	do{
		i++;
		suc1 = 0;
		u = x +a[i];
		v = y +b[i];
		if(1 <= u && u <= n && 1 <= v && v <= n && H[u][v] == 0){
			H[u][v] = k;
			if(k < n*n){
				Try(k + 1, u, v, suc1);
				if(!suc1)
					H[u][v] = 0;
			}
			else suc1 = 1;
		}
	}
	while(!suc1 && (i < 8));
	success = suc1;
}
int main(){
	int x, y, suc;
	n=5;
	H = new int*[n+1];
	for(int i =1;i<=n;i++)
		H[i] = new int[n+1];
	for(int i=1;i<=n;i++)
		for(int j=1; j <= n; j++)
			H[i][j] = 0;
	x=5; y=1;
	H[x][y] = 1;
	Try(2, x, y, suc);
	if(suc)
		for(int i = 1; i <= n; i++){
			for(int j = 1; j<= n; j++)
				cout<<H[i][j]<<"\t";
			cout<<endl<<endl;
		}
	else cout<<"Khong tin duoc duong di nao...!";
}
		

