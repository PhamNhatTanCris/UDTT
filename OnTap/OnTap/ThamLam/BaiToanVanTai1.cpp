#include <iostream>
using namespace std;

int n = 5;
int k[5] = {10, 6, 4, 3, 1};
int u[5] = {0};

bool chon_xe(int m, int &count){
	
	for(int i = 0 ; i < n ; i++){
		if(m >= k[i]){
			u[i] = 1;
			m = m - k[i];
			count++;
		}
	}
	if(m > 0){
		return false;
	} else {
		return true;
	}
}

int main(){
	int count = 0;
	if(chon_xe(24, count)){
		cout<<"Can dung "<<count<<" xe, cu the nhu sau";
		for(int i = 0 ; i < n ; i++){
			if(u[i]){
				cout<<"\n- xe co trong tai "<<k[i]<<" tan";
			}
		}
	} else {
		cout<<"Khong co phuong an toi uu";
	}
}
