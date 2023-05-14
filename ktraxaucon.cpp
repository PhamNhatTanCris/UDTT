#include<bits/stdc++.h>
using namespace std;
char p[50] = "con";
char t[50] = "conginuadaumakhoc";
int indexOf(const char *p,const char *t){
	int m=strlen(p);
	int n=strlen(t)-m;
	for(int i=0;i<n;i++){
		int j=0;
		while(j<m&&t[i+j]==p[j]){
			j++;
		}
		if(j==m)
			return i;
	}
	return -1;
}
int main(){
	if(indexOf(p,t) == -1) cout<<"Khong";
	else cout<<"Co";
	
 }
		

