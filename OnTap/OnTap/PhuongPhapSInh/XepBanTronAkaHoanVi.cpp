#include <iostream>
using namespace std;
string s[7] = {" ","Cong", "Toan", "Trang", "Trung", "Tam", "Tu"};

void generate(int a[], int n, int i){
	int k = n;
	//tim x[k] nho nhat trong doan tu i den n
	while(a[k] < a[i]){
		k--;
	}
	
	//doi cho 2 gia tri cho nhau 
	swap(a[i], a[k]);
	int j = n;
	i++;
	
	//dao nguoc day tu i + 1 den n
	while(i < j){
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

void show(int a[], int n){
	for (int i = 1; i <= n; i++){
		cout<<s[a[i]]<<" ";
	}
	
	cout<<"\n";
}

void list(int n){
	int i;
	int a[n + 1] = {0};
	
	for (i = 1; i <= n; i++) { a[i] = i; }
	
	do{
		show(a, n);
		
		i = n - 1;
		//tim phan tu lien truoc doan cuoi giam dan
		while(i > 0 && a[i] > a[i+1]){
			i--;
		}
		
		if(i > 0){
			generate(a, n, i);
		}
	}
	while(i > 0);
}

int main(){
	list(6);
}
