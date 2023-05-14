#include <iostream>
using namespace std;

int C[5] = {100, 25, 10, 5, 1};
int S[5] = {0};

bool CASHIERS_ALGORITHM(int m, int n){
	int i = 0;
	
	while(n > 0 && i < m){
		S[i] = n / C[i];
		n = n - S[i] * C[i];
		i++;
	}
	
	if(n > 0) return false;
	else return true;
}

int main(){
	int n;
	cout<<"Nhap so tien: ";
	cin>>n;
	
	if(CASHIERS_ALGORITHM(5, n)){
		cout<<"Ket qua: "<<endl;
		for(int i = 0 ; i < 5 ; i++){
			cout<<S[i]<<" Dong co menh gia "<<C[i]<<endl;
		}
	} else {
		cout<<"Khong co phuong an phu hop";
	}
}
