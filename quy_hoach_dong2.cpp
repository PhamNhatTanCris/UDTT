#include<bits/stdc++.h>
using namespace std;
const int n = 5;
int f[6] = {0};
int analys03() { 
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (j < i) {
				f[j] = f[j] + f[j – i];
			}
		}
	}
	return f[n];
}

int main(){
	f[0]=1;
	analys03();
		for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			cout<<f[j]<<"\t";
		}
		cout<<"\n";
	}
 }
		

