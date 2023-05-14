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

long algo2 (long *a, int n, int &left, int &right){
	long max = a[0];
	left = right = 0;
	for(int i = 0; i < n; i ++){
		long s= 0;
		for(int j = i; j < n ; j++){
			s = s + a[j];
			if(max < s){
				max = s;
				left = i;
				right = j;
			}
			
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
	max = algo2(a, n, left, right);
	cout<<"Day con lon nhat la s("<<left + 1<<", "<<right + 1<<"): ";
	for(int i = left; i <= right; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Tong cua day con la "<<max<<endl;
	ghi_dl(a, left, right);
 }
		

