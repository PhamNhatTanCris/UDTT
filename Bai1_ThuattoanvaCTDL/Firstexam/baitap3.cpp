#include<bits/stdc++.h>
using namespace std;
int n  = 5;
float S[5] = {8,9,10,11,12};
float F[5] = {8.5, 11, 11.5, 12.5, 13};
int schedule[5] = {0};
float last_finish = 0;
void interval_Schduling(int n, float S[], float F[]){
	for (int i = 0; i<n; i++){
		if (S[i] >= last_finish){
			schedule[i] = 1;
			last_finish = F[i];
		}
  }  
}
void Xuat(int A[]){
	for (int i=0; i<n;i++){
		if (A[i] == 1)
			cout<<"Cong viec "<<i+1<<", ";
		}
}
main(){
	interval_Schduling(5,S,F);
	Xuat(schedule);
}
