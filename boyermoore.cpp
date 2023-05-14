#include <iostream>
#include <string>
using namespace std;
 
void makeBC(int* bc,string pat)		{
 
	for(int i = 0; i <= 255; i++)
		bc[i] = -1;
 
	for(int i = 0; i < pat.length(); i++)	
		bc[pat[i]] = i;
}
 
void makeF(int* f,int* s,string pat)	{
 
	int m = pat.length();
	for(int k = 0; k <= m; k++)	
		s[k] = 0;
 
	int i = m, j = m+1;
	f[i] = j;
 
	while(i > 0)	{
 
		while(j <= m && pat[i-1] != pat[j-1])	{
 
			if(s[j] == 0)
				s[j] = j-i;
			j = f[j];
		}
		i--;
		j--;
		f[i] = j;
	}
 
 
}
 
void makeS(int* f,int* s,string pat)	{
 
	int m = pat.length();
	int j = f[0];
 
	for(int i = 0; i <= m; i++)	{
 
		if(s[i] == 0)
				s[i] = j;
 
		if(i == j)
				j = f[j];
	}
 
 
}
 
void BM(string text, string pat)	{
 
	int m = pat.length();
	int n = text.length();
	int bc[256]; 
	int f[m+1]; 
				
	int s[m+1]; 
 
	makeBC(bc,pat);
	makeF(f,s,pat);
	makeS(f,s,pat);
 
	int i = 0,j;
 
	while(i <= n-m)	{
 
		j = m-1;
		while(j >= 0 && pat[j] == text[i+j])
			j--;
 
		if(j < 0)
		{
			cout << "Found pattern at index: " << i << endl;
			i += s[0];
		}
		else
			i += std::max(s[j+1], j - bc[text[i+j]]);
	}
 
}
 
int main()	{
 
	string text = "mothaibabonnamsaubay";
	string pat = "namsau";
 
	BM(text,pat);
	return 0;
}
