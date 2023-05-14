#include<bits/stdc++.h>
using namespace std;

const int n = 5;
int f[n+1][n+1]={0};

int analys01(){
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j < i) {
				f[i][j] = f[i-1][j];
			}
			else {
				f[i][j] = f[i-1][j] + f[i][j-i];
			}
		}
	}
	return f[n][n];
}

int main(){
	f[0][0] = 1;
	analys01();
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			cout<<f[i][j]<<"\t";
		}
		cout<<"\n";
	}
 }
		

