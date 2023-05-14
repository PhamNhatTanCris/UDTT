#include<bits/stdc++.h>
using namespace std;
void doc_dl(long *&a, int &n){
	ifstream fin("input.txt");
	fin>>n;
	a = new long[n];
	for (int i = 0; i < n; i++){
		fin>>a[i];
	}
	fin.close();
}

void display(long *a, int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

long algo4 (long *a, int n, int &left, int &right){
	long max = a[0], s[n];
	s[0]=a[0];
	max=s[0];
	left = right = 0;
	for(int i = 0; i < n; i ++){
		if(s[i-1]>0)
			s[i] = s[i-1] + a[i];
		else{
			s[i] = a[i];
			left = i;
		}
		if (max < s[i]){
			max = s[i];
			right = i;
		}
	}
	return max;
}
void ghi_dl(long *a, int left, int right){
	ofstream fout("output.txt");
	fout<<left<<" "<<right<<endl;
	for(int i = left;i <= right;i++){
		fout<<a[i]<<" ";
	}
	fout.close();
}

int main(){
	long *a, max;
	int n, left, right;;
	doc_dl(a,n);
	cout<<"Day s: ";display(a,n);
	max = algo4(a, n,left, right);
	cout<<"Day con lon nhat la s("<<left + 1<<", "<<right + 1<<"): ";
	for(int i = left; i <= right; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Tong cua day con la "<<max<<endl;
	ghi_dl(a, left, right);
 }
		


