#include <iostream>
using namespace std;

void ThapHaNoi(int n, char a, char b, char c){
	if(n == 1){
		cout<<"Chuyen 1 dia tu coc "<<a<<" sang coc "<<c<<endl;
		return;
	}
	ThapHaNoi(n - 1, a, c, b);
	ThapHaNoi(1, a, b, c);
	ThapHaNoi(n- 1, b, a, c);
}

int main(){
	ThapHaNoi(3, 'A', 'B', 'C');
}
