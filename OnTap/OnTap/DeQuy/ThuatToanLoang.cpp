#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int n = 3, m = 3;

int a[12][12] = {0};
	
bool flag[12][12] = {0};
	

void initFlag(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			flag[i][j] = 0;
		}
	}
}

void initGrid(){
	srand (time(NULL));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			a[i][j] = rand() % (6);
		}
	}
}

void showGrid(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void loang(int i, int j){
	flag[i][j] = true;
	
	if(a[i][j] == a[i-1][j]  && !flag[i-1][j] && i > 0){
		loang(i - 1, j);
	}
	
	if(a[i][j] == a[i+1][j]  && !flag[i+1][j] && i < n - 1 ){
		loang(i + 1, j);
	}
	
	if(a[i][j] == a[i][j + 1]  && !flag[i][j + 1] && j < m - 1){
		loang(i, j + 1);
	}
	
	if(a[i][j] == a[i][j - 1]  && !flag[i][j - 1] && j > 0){
		loang(i, j - 1);
	}
}

int main(){
	initGrid();
	initFlag();
	showGrid();
	int count = 0;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(!flag[i][j] && a[i][j] == 5){
				count++;
				loang(i, j);
			}
		}
	}
	
	cout<<count;
}
