#include<bits/stdc++.h>
using namespace std;

algorithm(){
	for (j = 0; j <= m; j++) { F[0][j] = 0; }
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			F[i][j] = F[i – 1][j]; //Khong lay goi thu i
			temp = F[i – 1][j – w[i]] + v[i];
			if (w[i] <= j && F[i][j] < temp) //Lay goi thu i
				F[i][j] = temp;
			}
		}
}
result(){
	cout<<"Max value: " << F[n][m] << endl;
		i = n; j = m;
	while (i != 0) {
		if (F[i][j] != F[i – 1][j]) {
			cout<<i<<" ";
			j = j – w[i]; //Lay goi thu i
		}
		i--;
	}
}
int main(){
	algorithm();
	resylt();
 }
		

