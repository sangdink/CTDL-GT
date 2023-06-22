#include<bits/stdc++.h>
using namespace std;

class CT;
class NGUOI{
protected:
    char hoTen[30];
    int tuoi;
    char gioiTinh[20];
public:
    void Nhap();
    void Xuat();
    friend void DemNV19(CT &t);
};
void NGUOI::Nhap(){
    cout << "Ho ten: "; fflush(stdin); gets(hoTen);
    cout << "Tuoi: "; cin >> tuoi;
    cout << "Gioi tinh: "; fflush(stdin); gets(gioiTinh);
}
void NGUOI::Xuat(){
    cout << setw(20) << hoTen << setw(10) << tuoi << setw(10) << gioiTinh;
}
class NV:public NGUOI{
    char maNV[10];
	char chucVu[30];
	float luong;
	public:
		void Nhap();
		void Xuat();
        friend class CT;
};
void NV::Nhap(){
    NGUOI::Nhap();
    cout << "Ma nv: "; fflush(stdin); gets(maNV);
    cout << "Chuc vu: "; fflush(stdin); gets(chucVu);
    cout << "Luong: "; cin >> luong;
}
void NV::Xuat(){
    NGUOI::Xuat();
    cout << setw(10) << maNV << setw(10) << chucVu << setw(10) << luong << endl;
}
class CT{
    private:
		char maCT[10];
		char diaChi[30];
		NV *x;
		int n;
	public:
		void Nhap();
		void Xuat();
		friend void DemNV19(CT &t);
};
void CT::Nhap(){
    cout << "Ma ct: "; fflush(stdin); gets(maCT);
    cout << "Dia chi: "; fflush(stdin); gets(diaChi);
    cout << "Nhap so luong nv: "; cin >> n;
    x = new NV[n];
    for(int i=0; i<n; i++){
        cout << "Nhap nv thu " << i+1 << ":" << endl;
        x[i].Nhap();
    }
}
void CT::Xuat(){
    cout << "Ma ct: " << maCT << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Danh sach nv:\n";
    cout << setw(20) << "Ho ten" << setw(10) << "Tuoi" << setw(10) << "Gioi tinh";
    cout << setw(10) << "Ma nv" << setw(10) << "Chuc vu" << setw(10) << "Luong" << endl;
    for(int i=0; i<n; i++){
        x[i].Xuat();
    }
}
void DemNV19(CT &t){
    int cnt=0;
    cout << setw(20) << "Ho ten" << setw(10) << "Tuoi" << setw(10) << "Gioi tinh";
    cout << setw(10) << "Ma nv" << setw(10) << "Chuc vu" << setw(10) << "Luong" << endl;
    for(int i=0; i<t.n; i++){
        if(t.x[i].tuoi==19){
            cnt++;
            t.x[i].Xuat();
        }
    }
    cout << "So sv: " << cnt << endl;
}
int main(){
    CT a;
    a.Nhap();
    cout << "\n==========================\n";
    a.Xuat();
    cout << "\n==========================\n";
    DemNV19(a);
}
