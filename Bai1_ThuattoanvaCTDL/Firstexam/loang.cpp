#include<bits/stdc++.h>
using namespace std;
int so_mien = 0;
int a[5][6] = {
		{1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0, 1},
		{0, 0, 1, 0, 0, 1}
	};
bool flag[5][6] = {
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0}
};


void loang(int i, int j){
	flag[i][j] = true;
	if((a[i-1][j]==a[i][j]) && (! flag[i-1][j]))
		loang(i-1, i);
	if((a[i+1][j]==a[i][j]) && (! flag[i+1][j]))
		loang(i+1, j);
	if((a[i][j-1]==a[i][j]) && (! flag[i][j-1]))
		loang(i, j-1);
	if((a[i][j+1]==a[i][j]) && (! flag[i][j+1]))
		loang(i, j+1);
}
int main(){
	for (int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			flag[i][j] = false;
		}
	}
	for (int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			if(!flag[i][j]){
				so_mien++;
				loang(i, j);
			}
		}
	}
	cout<<"So mien lien thong: "<<so_mien<<endl;
 }
		

