#include <iostream>
using namespace std;

float S[5] = {8, 9, 10, 11, 12};
float F[5] = {8.5, 11, 11.5, 12.5, 13};

int schedule[5] = {0};

void scheduling(int n){
	float last_finish = 0;
	for(int i = 0 ; i < n ; i++){
		if(S[i] >= last_finish){
			schedule[i] = 1;
			last_finish = F[i];
		}
	}
	
	//return schedule;
}

int main(){
	int n = 5;
	scheduling(n);
	cout<<"Tap cac cong viec tuong hop la: "<<endl;
	for(int i = 0 ; i < n ; i++){
		if(schedule[i] == 1){
			cout<<"cong viec "<<i+1<<endl;
		}
	}
}
