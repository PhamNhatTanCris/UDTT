#include<bits/stdc++.h>
using namespace std;

int main()
{
    int so;
    int soT;
    int tong = 0;
    cout << "Nhap so: ";
    cin >> so;
    soT = so;
    while (soT != 0) {
        tong += soT% 10;
        soT /= 10;
    }
    cout << "Tong cac chu so cua so " << so << " la " << tong << endl;
    return 0;
}
		

