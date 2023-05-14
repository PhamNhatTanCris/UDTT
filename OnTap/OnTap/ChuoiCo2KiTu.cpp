#include <iostream>
using namespace std;

void generate(int a[], int n, int i){
	//gan phan tu i = 1
	a[i++] = 1;
	
	//gan cac phat tu o sau i = 0
	while(i <= n){
		a[i++] = 0;
	}
}

void show(int a[], int n){
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == 0){
			cout<<"a ";
		} else {
			cout<<"b ";
		}
	}
	cout<<"\n";
}

void listing(int n){
	int i;
	int a[n + 1] = {0};
	do {
		show(a, n);
		i = n;
		
		//tim phan tu i dau tien co gia tri = 0 trong cau hinh hien tai
		while(i > 0 && a[i] == 1){
			i--;	
		}
		
		//sinh cau hinh moi
		if(i > 0){
			generate(a, n, i);
		}
	}
	while(i > 0);
}

int main(){
	listing(4);
}
