#include<iostream>
#include<string> 
using namespace std;
void algorithm(string a, string b){  
    int n = a.size();  
    int m = b.size();
    int max_Size;     
    string subsequence = "";  
    int L[n+1][m+1];   
    
    for(int i=0; i<=n; i++) 
        L[i][0] = 0;
    for(int j=0; j<=m; j++) 
        L[0][j] = 0;
        
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]){  
                L[i][j] = L[i-1][j-1] + 1;   
            }
            else{   
                 if(L[i-1][j] >= L[i][j-1])   
                    L[i][j] = L[i-1][j];
                else
                    L[i][j] = L[i][j-1];
            }
        }
    }
    max_Size=L[n][m];
    int i = n; 
    int j = m;
    while(L[i][j] != 0){ 
        if(a[i-1] == b[j-1]){ 
            subsequence += a[i-1];   
            i--;
            j--;
        }
        else{  
            if(L[i-1][j] >= L[i][j-1]) 
                i--;
            else
                j--;
        }
    }
    
    cout<<"\nDo dai xau lon nhat: "<<max_Size;  
    cout<<"\nXau con: ";
    for(int t = max_Size-1 ; t>=0; t--) 
        cout<<subsequence[t];
}
int main(){
    string a ="viet nam";
    string b="toi yeu viet nam";
   	algorithm(a,b);
    return 0;    
}
