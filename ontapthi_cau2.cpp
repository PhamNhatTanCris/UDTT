#include<bits/stdc++.h>
using namespace std;
char s[10] = "abcabdefg";
char p[4] = "abc";


int char_in_string(char c, char *p){
	for(int i=0; i<strlen(p); i++){
		if(p[i] == c)
			return i;
	}
	return -1;
}

int Boyer_Moore_Horspool(){
	int dem = 0, i = strlen(p), v = strlen(p);
	while(i<strlen(s)){
		int x = v-1, j=i-1;
		while(s[j] == p[x] && x > -1){
			j--; x--;
		}
		if(x<0){
			dem++;
			i = i+v;
		}
		else{
			x = char_in_string(s[j], p);
			if(x<0)
				i= i+v;
			else
				i=i+v-x-1;
		}
	}
	return dem;
}

main(){
	if(Boyer_Moore_Horspool() == 0)
		cout<<p<<" khong xuat hien trong "<<s<<endl;
	else
		cout<<p<<" co xuat hien trong "<<s<<endl;
}
