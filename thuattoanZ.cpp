#include<bits/stdc++.h>
using namespace std;
void z_algo(string s, int *z) {
	int n = s.size(), l = 0, right = 0;
	for(int i = 1; i < n; i++) {
		if (i > right) {
			l = right = i;
			while (right < n && s[right - l]== s[right]) 
				right++;
			z[i] = right - l; right --;
		} 
		else 
			if (z[i - l] < (right - i + 1))
				z[i] = z[i-l];
		else { 
			l = i;
			while (right < n && s[right - l] == s[right]) right ++;
			z[i] = right - l; right --;
		}
	}
}

int main(){
	string s="vi vietduc";
	string p="viet";
	s=p+"$"+s;
	int n = s.size();
	int z[n] = {0};
	z[0]=-1;
	z_algo(s,z);
	int check = -1;
	for(int i=0;i<s.length();i++)
	{
		if(z[i]== p.size()){
			check=i-p.length()-1;
			break;
		}
	}	
	if(check == -1) cout<<"P khong xuat hien trong S!!";
	else cout<<"P xuat hien trong S, tai vi tri dau tien la:  "<<check<<endl;
 }
		

