#include <iostream>
using namespace std;
int count[255] = {0};

void counting(string s){
	for(int i = 0 ; i < s.length(); i++){
		count[s[i]]++;
	}
}

void result(){
	for(int i = 0 ; i < 255 ; i++){
		if(count[i] > 0){
			cout<<(char)i<<": "<<count[i]<<endl;
		}
	}
}
int main(){
	string s = "abcdadcfg";
	counting(s);
	
	result();
	cout<<"\n"<<s.length();
}
