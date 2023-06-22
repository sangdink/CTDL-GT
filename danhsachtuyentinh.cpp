#include<bits/stdc++.h>
using namespace std;
#define max 3
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
//Them sinh vien vao cuoi danh sach
void Add(List &L, SV sv){
	if(L.count < max){
		L.data[L.count++] = sv;
		//L.count++;
	}
	else{
		cout << "Danh sach bi day!";
	}
}
void nhapList(List &L, SV sv) {
    L.count=-1;
    int n=1;
    do {
        cout << "Nhap sv thu: " << n << endl;
        nhapSV(sv);
        if(strcmp(sv.maSV,"***")==0) break;
        Add(L,sv);
        n++;
    } while(n<=max);
}
int main() {
    SV sv;
    List L;
    nhapList(L,sv);

}
