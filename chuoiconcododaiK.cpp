#include <bits/stdc++.h>
using namespace std;
#define k 3
char s[8] = "abccaba";
char xc[3];
int dem = 0;
int n = 7;

bool comat(char c, char arr[]){
	for(int i = 0 ; i < strlen(arr); i++){
		if(arr[i] == c){
			return true;
		}
	}	
	
	return false;
}

void them(char arr[], char c){
	int len = strlen(arr);
    arr[len] = c;
    arr[len+1] = '\0';
}

void xoa(char arr[]){
	arr[strlen(arr) - 1] = '\0';
}

void Try(int i) {
	char tam[100]; 
	tam[0] = '\0';
	if (strlen(xc) == k) {
		cout<<xc<<endl;
		dem++;
	}
	else {
		for (int j = i; j < n; j++) {
			if (comat(s[j], tam) == false){
				them(tam, s[j]); 
				them(xc, s[j]);
				Try(j + 1); 
				xoa(xc);
			}
		}
	}
}

int main(){
	Try(0);
	
}

