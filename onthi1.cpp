#include<bits/stdc++.h>
using namespace std;
void z_algo(const char *s, int *z) {
	int n = strlen(s), left = 0, right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right)
		{
			left = right = i;
			while (right < n && s[right - left] == s[right]){
				right++;
			z[i] = right - left; 
				right--;
			}
		} else if (z[i - left] < right – i + 1){
				z[i] = z[i-left];
		}
		
		else 
		{ 
			left = i;
			while (right < n && s[right - left] == s[right]){
				right ++;
			z[i] = right - left; right --;
			}
		}
	}
}

int main(){
	string s="vi vietduc";
	string p="viet";
	s=p+"$"+s;
	int z[s.size()];
	z[0]=-1;
	cout<<"\nSo chuoi con la: "<<z_algo(s,z)<<endl;
	for(int i=0;i<s.size();i++){
		if(z[i]==p.size()){
			cout<<i-p.size()<<" ";
		}
	}
	
 }

