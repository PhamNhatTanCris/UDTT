#include <bits/stdc++.h>
using namespace std;

struct Task{
	string code;
	float start;
	float finish;
};


int schedule[6] = {0};
int a[6] = {0};
int n = 6, k = 5;
Task c[6] = {
	{"CV01", 8, 8.5},
	{"CV02", 9, 11},
	{"CV03", 10, 11.5},
	{"CV04", 11, 12.5},
	{"CV05", 12, 13},
	{"CV06", 13.5, 15},
};

float sum_of_time(int n){
	if(n == 0){
		return c[n].finish - c[n].start;
	} else {
		return (c[n].finish - c[n].start) + sum_of_time(n - 1);
	}
}

int scheduling(int n){
	float last_finish = 0;
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		if(c[i].start >= last_finish){
			count++;
			schedule[i] = 1;
			last_finish = c[i].finish;
		}
	}
	return count;
}

void show(){
	for(int i = 1; i <= 5 ; i++){
		cout<<c[a[i] - 1].code<<" ";
	}
	cout<<endl;
}

void rotate_bike(int i){
	for(int j = a[i - 1] + 1 ; j <= n - k + i; j++){
		a[i] = j;
		if(i == k){
			show();
		} else {
			rotate_bike(i + 1);
		}
	}
}

int main(){
	cout<<"Tong thoi gian thuc hien cac cong viec la: "<<sum_of_time(5)<<" gio"<<endl;
	
	int maximum = scheduling(6);
	cout<<"\nMot nguoi co the thuc hien toi da "<<maximum<<" cong viec"<<endl;
	for(int i = 0 ; i < 6 ; i++){
		if(schedule[i] == 1){
			cout<<"Cong viec "<<i + 1<<", Bat dau: "<<c[i].start<<" Ket thuc: "<<c[i].finish<<endl;
		}
	}

	cout<<"\nCac cach lay 5 cong viec tu danh sach c: "<<endl;
	rotate_bike(1);
	
}
