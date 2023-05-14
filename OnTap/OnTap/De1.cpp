#include <bits/stdc++.h>
using namespace std;

struct Student{
	string name;
	float score;
	double fee;
};

int mark[7] = {0};
int permutation[7];
int count = 0;
Student h[6] = {
	{"Kha", 10, 1000000},
	{"Huynh", 9, 2000000},
	{"Manh", 8, 3000000},
	{"Hang", 7, 4000000},
	{"Hoang", 6, 5000000},
	{"Khanh", 5, 6000000}
	};
int n = 6;

void show_list(int n){
	cout<<h[n].name<<"\t"<<h[n].score<<"\t"<<h[n].fee<<endl;
	if(n > 0) return show_list(n - 1);
}

int max(double p, int n){
	int count = 0;
	
	for(int i = 0 ; i < n ; i++){
		if(p >= h[i].fee){
			p = p - h[i].fee;
			count++;
		}
	}	
	
	return count;
}

void show_permutation(){
	for(int i = 1 ; i <= 6 ; i++){
		cout<<setw(-10)<<h[permutation[i] - 1].name<<" ";
		
	}
	cout<<endl;
}

void listed_permutaion(int k){
	for(int i = 1 ; i <= n ; i++){
		if(mark[i] == 0){
			permutation[k] = i;
			mark[i] = 1;
			if(k == n){
				show_permutation();
			} else {
				listed_permutaion(k + 1);
			}
			mark[i] = 0;
		}
	}
}

int main(){
	cout<<"Hien thi danh sach: "<<endl;
	show_list(5);
	double p = 11000000;
	cout<<"Lay nhieu nhat "<<max(p, 5)<<" hoc sinh de so tien khong vuot qua "<<p<<endl;
	cout<<"Cac cach xep hoc sinh vao cai ban tron: "<<endl;
	listed_permutaion(1);
}
