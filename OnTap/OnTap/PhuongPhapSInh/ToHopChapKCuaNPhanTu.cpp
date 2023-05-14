#include <iostream>
using namespace std;

string s[7] = {" ","Cong", "Toan", "Trang", "Trung", "Tam", "Tu"};

void generate(int a[], int k, int i){
	//tang a[i] len 1 don vi
	a[i] += 1;
	i++;
	
	//gan cac phan tu sau i bang gioi han duoi cua no
	while(i <= k){
		a[i] = a[i - 1] + 1;
		i++;
	}
}

void show(int a[], int k){
	for(int i = 1 ; i <= k ; i++){
		cout<<s[a[i]]<<" ";
	}
	cout<<"\n";
}

void list(int n, int k){
	int i, a[k + 1] = {0};
	
	//khoi tao cau hinh dau tien
	for(i = 1 ; i <= k ; i++) a[i] = i;
	
	
	do{
		//hien thi 1 cau hinh
		show(a, k);
		//xet tu dau day
		i = k;
		
		//tim phan tu dau tien chua dat gioi han tren
		while(i > 0 && a[i] == n - k + i){
			i--;
		}
		
		//sinh cau hinh moi
		if(i > 0){
			generate(a, k , i);
		}	
	}
	while(i > 0);
}

int main(){
	list(6, 4);
}
