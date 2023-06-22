#include<bits/stdc++.h>
using namespace std;
#define max 100
struct SV {
    char maSV[10], hoDem[30], ten[10];
    int nam;
    double dtk;
};
struct List {
    int count;
    SV data[max];
};
//nhap thong tin cho moi sinh vien
void nhapSV(SV &sv) {
    cout << "Nhap ma sv: "; fflush(stdin); gets(sv.maSV);
    if(strcmp(sv.maSV,"***")==0) return;
    cout << "Ho dem: "; fflush(stdin); gets(sv.hoDem);
    cout << "Ten: "; fflush(stdin); gets(sv.ten);
    cout << "Nam sinh: "; cin >> sv.nam;
    cout << "Diem tk: "; cin >> sv.dtk;
}
//Nhap danh sach sinh vien
void nhapDS(List &L) {
    L.count=-1;
    SV sv;
    int i=1;
    do {
        cout << "Nhap sv thu: " << i << endl;
        nhapSV(sv);
        if(strcmp(sv.maSV,"***")==0) return;
        if(L.count == max-1) return;
        else {
            L.data[L.count++] = sv;
        }
        i++;
    } while(1);
}
int main() {
    List L;
    nhapDS(L);
}
