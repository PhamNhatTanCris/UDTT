#include<stdio.h>
#include<math.h>
int a[20];
bool Ok(int x2,int y2){
    //kiem tra cach dat co thoa man khong
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )
            return false;
    //Neu kiem tra het cac truong hop van khong sai thi tra ve true
    return true;
}
 
void Xuat(int n){
    //in ra mot ket qua
    for(int i=1;i<=n;i++)
        printf(" %d",a[i]);
    printf("\n");
}
 
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        // thu dat quan hau vao cac cot tu 1 den n
        if(Ok(i,j)){
            //neu cach dat nay thoa man thi luu lai vi tri
            a[i] = j;
            //neu dat xong quan hau thu n thi xuat ra mot ket qua
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
 
int main(){
    int n = 8;//cho 8 quan hau tren ban co 8*8
    Try(1,n);
    return 0;
}
