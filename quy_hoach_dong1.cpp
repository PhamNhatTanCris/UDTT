#include<bits/stdc++.h>
using namespace std;
#define n 5
int cur[6] = {0};
int next[6] = {0};
int analys02() { 
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j < i) {
				next[j] = cur[j];
			}
			else{
				next[j] = cur[j] + next[j-i];
			}
		}
	memccpy(cur,next,(n+1)*sizeof(int));
	}
	return cur[n];
}

int main(){
	cur[0] = 1;
	next[0] = 1;
	analys02();
 }
		

