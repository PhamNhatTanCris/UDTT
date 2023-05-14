#include <iostream>
using namespace std;

int tknp_dq(int a[], int c, int L, int R){
	if(R >= L) {
		int M = (L + R)/2;
	
		if(a[M] == c){
			return M;
		}
		
		if(a[M] > c){
			return tknp_dq(a, c, L, M - 1);
		}
		
		return tknp_dq(a, c, M + 1, R);
	}
	
	return -1;
}

void chen(int a[], int n, int k, int c){
	for(int i = n - 1 ; i > k; i--){
		a[i] = a[i - 1];
	}
	
	a[k] = c;
}

int tknp_lap(int a[], int n, int c){
	int L = 0, R = n - 1, M;
	
//	do{
//		M = (L + R) / 2;
//		if(a[M] > c) R = M - 1;
//		if(a[M] < c) L = M + 1;
//	}
//	while(a[M] != c && L <= R);
//	
//	if(a[M] == c) return M;
//	else return -1;
	
	while(R >= L){
		M = (L + R) / 2;
		if(a[M] == c) return M;
		
		if(a[M] > c) 
			R = M - 1;
		else 
			L = M + 1;			
	}
	
	return -1;
}

void xuat(int a[], int n){
	for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
	int a[9] =  {1, 3, 4, 5, 6, 7, 8, 9};
	int c, n = 9;
	cout<<"Nhap vao so can tim kiem: ";
	cin>>c;
	
	int rs = tknp_lap(a, 9, c);
	if(rs != -1){
		cout<<"Chi so cua phan tu "<<c<<" la: "<<rs;
	} else {
		int index = -1;
		cout<<"Khong tim thay, chen "<<c<<" vao mang: "<<endl;
		for(int i = 0; i < n; i++){
			if(a[i] >= c){
				index = i;
				break;
			}
		}
		
		if(index == -1) 
			index = n - 1;
			
		cout<<"Vi tri thich hop danh cho "<< c<<" la: "<<index<<endl;
		chen(a, n, index, c);
		xuat(a, n);
	}	
}
