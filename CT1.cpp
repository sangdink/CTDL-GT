#include<bits/stdc++.h>
const int MAX = 100;
using namespace std;

struct HocSinh{
    char hoTen[30];
    char gioiTinh[10];
	int namSinh;
	float Diem;s
	void nhap();
	void xuat();
};
void HocSinh::nhap(){
	cout << "Ho ten hoc sinh la: ";cin.getline(hoTen,30);
	cout << "Gioi tinh la: ";cin.getline(gioiTinh,10);
	cout << "Nam sinh la: "; cin >> namSinh;
	cout << "Diem tong ket la: "; cin >> Diem;
	cin.ignore();
}
void HocSinh::xuat(){
	cout << setw(15) << hoTen;
	cout << setw(10) << gioiTinh;
	cout << setw(10) << namSinh;
	cout << setw(10) << Diem;
	cout << endl;
}
struct List{
    HocSinh data[MAX];
    int count;
};
void nhapList(List &L, HocSinh a){
	if(L.count < MAX){
		L.data[L.count] = a;
		L.count++;
	}
	else{
		cout << "Danh sach bi day!";
	}
}
void xuatList(List L){  // khong thay doi gia tri
		for(int i = 0; i < L.count; i++){
			L.data[i].xuat();
		}
}
int main() {
    HocSinh x;
    List L;
    L.cout=0;
    int n; cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++) {
        cout <<"\n\nNhap thong tin hoc sinh thu " << i+1 << endl;
        x.nhap();
        nhapList(L,x;)
    }
    cout << "\n\n\t\tTHONG TIN HOC SINH\n\n";
	cout << setw(15) << "Ho Ten";
	cout << setw(10) << "Gioi Tinh";
	cout << setw(10) << "Nam Sinh";
	cout << setw(10) << "Diem";
	cout << endl;
	xuatList(L);
}
