#include <bits/stdc++.h>
using namespace std;
#define n 6
#define m 20 

struct LopHoc{
	string gv;
	int soHs;
	int soHsNu;
	int phuCap;
};

LopHoc d[7] = {
	{"Nguyen Van Trong Kha", 8, 6,  5},
	{"Thi Thu Hang", 		 6, 6,  6},
	{"Pham Quoc Huy", 		 7, 4,  7},
	{"Bui Thi Manh", 		 5, 3,  8},
	{"Nguyen Thi Huynh", 	 4, 2,  9},
	{"Tran Tuan Minh", 		 3, 2, 10},
	{"Bui Van Thi", 		 3, 0,  7}
};

int binarySearch(LopHoc d[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
 
    if (d[mid].soHs - d[mid].soHsNu == x)
      return mid;
 
    if (d[mid].soHs - d[mid].soHsNu > x){
    	return binarySearch(d, l, mid - 1, x);
	}
      
    return binarySearch(d, mid + 1, r, x);
  }
 
  return -1;
}

int F[n+1][m+1];
void ghep_lop(){
	int i, j;
	for (j = 0; j <= m; j++) { F[0][j] = 0; }
	
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			F[i][j] = F[i - 1][j]; 
			
			int temp = F[i - 1][j - d[i-1].soHs] + d[i-1].soHsNu;
			
			if (d[i-1].soHs <= j && F[i][j] < temp){
				F[i][j] = temp;
			}
		
		}
	}
}

void truy_vet(){
	cout<<"So luong hoc sinh nu lon nhat co the ghep: " << F[n][m] << endl;
	int i = n, j = m;
	cout<<"Ghep cac lop cua cac giao vien sau: ";
	while (i != 0) {
		if (F[i][j] != F[i - 1][j]) {
			cout<<"\n"<<d[i-1].gv;
			j = j - d[i].soHs; 
		}
		i--;
	}
}

int dem_so_tu(string str)
{
    int count = (str[0] != ' ');
    
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            count++;
        }
    }
    return count;
}

bool Z(string hoten, string ten){
	string s = ten + "$"+ hoten;
	int k = s.length(), l = 0, r = 0;
	int z[k];
	
	for(int i = 1; i < k; i++){
		if(i > r){
			l = r = i;
			while(r < k && s[r - l] == s[r]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
		else {
			if(z[i - l] < r - i + 1){
				z[i] = z[i - l];
			} else{
				l = i;
				while(r < k && s[r - l] == s[r]){
					r++;
				}
				z[i] = r - l;
				r--;
			}
		}
	}
	
	for(int i = 0 ; i < k ; i++){
		if(z[i] == ten.length() && s[i + ten.length()] == ' ' && s[i-1] == ' '){
			return true;
		}
	}
	
	return false;
}

int main(){
	int index = binarySearch(d, 0, 6, 0);
	if(index != -1){
		cout<<"Ho ten giao vien lop khong co hoc sinh nam: ";
		cout<<d[index].gv<<endl;
	} else {
		cout<<"Tat cac lop hoc deu co hs nam"<<endl;
	}
	
	cout<<"\n\n";
	ghep_lop();
	truy_vet();
	
	cout<<"\n\n";
	cout<<"Cac giao vien co ten dem la Thi"<<endl;
	for(int i = 0 ; i < 7; i++){
		if(Z(d[i].gv, "Thi")){
			cout<<d[i].gv<<endl;
		}
	}
}
