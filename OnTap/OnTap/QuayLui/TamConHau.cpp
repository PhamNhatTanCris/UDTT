#include<bits/stdc++.h>
using namespace std;
int a[9];
int n;
int pa = 0;

bool safety(int k, int i){
	for(int j = 1; j < k; j++)
		if(a[j] == i || abs(j - k) == abs(a[j] - i))
			return false;
		return true;
}

void viewConfig(int n){
	for(int i = 1; i <= n; i++)
		printf("Hau %d cot %d; ", i, a[i]);
	printf("\n");
}

void Try(int k){
	for(int i = 1; i <= n; i++){
		if(safety(k, i)){
			a[k] = i;
			if(k == n){
				pa++;
				printf("PA %d: ", pa);
				viewConfig(n);
			}
			else
				Try(k + 1);
		}
	}
}

int main(){
	n = 8;
	Try(1);
	return 0;
 }
