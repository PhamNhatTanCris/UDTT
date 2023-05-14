#include <bits/stdc++.h>
using namespace std;

struct Computer{
	string brand;
	double cost;
	double price;
};

int n = 6;
int s[6] = {0};

Computer m[6] = {
	{"Dell", 1500, 6000},
	{"Lenovo", 1500, 5000},
	{"Acer", 1500, 4000},
	{"Asus", 1500, 3000},
	{"HP", 1500, 2000},
	{"Macbook", 1500, 1000}
};

void show_list(int i){
	cout<<m[i].brand<<"\t"<<m[i].cost<<"\t"<<m[i].price<<endl;
	if(i < n - 1){
		show_list(i + 1);
	}	
}

//bool greedy(double q){
//	for(int i = 0 ; i < n ; i++){
//		if(q >= m[i].price){
//			s[i] = q / m[i].price;
//			q = q - s[i] * m[i].price;
//		}
//	}
//	
//	if(q > 0){
//		return false;
//	} else return true;
//}

bool greedy(double q){
	for(int i = 0 ; i < n ; i++){
		if(q >= m[i].price){
			s[i] = 1;
			q = q - m[i].price;
		}
	}
	
	if(q > 0){
		return false;
	} else return true;
}

void view_config(int x[], int n){
	for (int i = 1; i <= n; i++){
		cout<<m[x[i] - 1].brand<<"\t";
	}
	
	cout<<"\n";
}

void next_config(int x[], int n, int i){
	int k = n;
	
	//tim phan tu nho nhat trong day giam dan > x[i]
	while (x[k] < x[i]){
		k--;
	}
	//doi cho 2 so cho nhau
	swap(x[i], x[k]);

	//dao nguoc doan cuoi
	int j = n; i++;	
	while (i < j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

void listing_configs(int n){
	int i, x[n + 1] = {0};

	for (i = 1; i <= n; i++) { 
		x[i] = i;
	} // khoi tao cau hinh
	
	do {
		view_config(x, n); 

		i = n - 1;
		
		while (i > 0 && x[i] > x[i + 1]) i--; //tim so lien truoc doan cuoi giam dan
		
		if (i > 0) { 
			next_config(x, n, i);
		}
	} while (i > 0);
}

int main(){
	show_list(0);
	double q = 10000;

	if(greedy(q)){
		cout<<"\nDanh sach can ban de co duoc dung so tien "<<q<<endl;
		for(int i = 0 ; i < n ; i++){
			if(s[i]){
				cout<<s[i]<<" may hang "<<m[i].brand<<endl;
			}
		}
	} else {
		cout<<"\nKhong co phuong an toi uu"<<endl;
	}
	cout<<"\nCac cach sap xep cac may trong danh sach"<<endl;
	listing_configs(6);
}
