#include <iostream>
using namespace std;

int a[9] = {0, 2, 1, -1, -2, -2, -1,  1,  2};
int b[9] = {0, 1, 2,  2,  1, -1, -2, -2, -1};

int H[6][6] = {0};
int n = 5;

void Try(int k, int x, int y, int &success){
	int u, v, sucl;
	int i = 0;
	
	do{
		i++;
		sucl = 0;
		u = x + a[i];
		v = y + b[i];
		
		if(1 <= u && u <= n && 1 <=v && v <= n && H[u][v] == 0){
			H[u][v] = k;
			if(k < n * n){
				Try(k + 1, u, v, sucl);
				if(!sucl){
					H[u][v] = 0;
				}
			} else {
				sucl = 1;
			}
		}
	}
	while(!sucl && (i < 8));
	success = sucl;
}

int main(){
	int x, y, sucl;
	n = 5;
	x = 1, y = 1;
	H[x][y] = 1;
	Try(2, x, y, sucl);
	if(sucl){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				printf("%-3d", H[i][j]);
			}
			cout<<endl;
		}
	}
}
