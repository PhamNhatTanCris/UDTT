#include<bits/stdc++.h>
using namespace std;
struct TaiSan{
	string tenTs;
	int soLuong;
};
int n = 10;
TaiSan d[10] = {
	{"Apple", 5},
	{"Bphone", 3},
	{"Calculator", 22},
	{"Desktop", 7},
	{"Ephone", 12},
	{"Family", 10},
	{"Guild", 1},
	{"Hello", 9},
	{"Katot", 8},
	{"Samsung", 6},
};
int ChiaDeTri(TaiSan array[], int L, int R, TaiSan ts)
{
    string x = ts.tenTs;
    int vitri;
   
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (d[mid].tenTs.compare(x) > 0)
            R = mid - 1;
        else
            L = mid + 1;
        vitri = R;
    }
    return vitri;
}


void Chen(int index, TaiSan x){
    for (int i = n; i > index;i--){
        d[i] = d[i - 1];
    }
    d[index] = x;
}

void Show(){
    for (int i = 0; i < n + 1; i++){
        cout<<"  "<<d[i].tenTs<<"  "<<d[i].soLuong<<endl;
    }
    cout<<endl;
}

int tam = 0;
void KhoiTao(double x)
{
    int i = 0;
    while (x > 0){
        tam++;
        x = x - d[i].soLuong;
        i++;
    }
}

int main(){
	TaiSan temp;
    temp = {"Xanh", 13};
    int kq = ChiaDeTri(d, 0, n - 1, temp) + 1;
    cout << "Can chen tai san tren vao vi tri "<< kq + 1<<" trong danh sach" << endl;
    Chen(kq, temp);
    cout<<"Danh sach tai san moi la: "<<endl;
    Show();
    cout << endl;
    double p = 30;
    KhoiTao(p);
    cout << "Can lay it nhat" << tam << " tai san de duoc tong so luong lon hon " << p << endl;
}

