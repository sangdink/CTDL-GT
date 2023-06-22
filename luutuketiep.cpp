#include<bits/stdc++.h>
using namespace std;
#define max 100

struct SV{
    char maSV[10], tenSV[30];
    int diemTK;
};
struct List{
    int count;
    SV E[max];
};
void NhapSV(SV &X){
    cout << "\tNhap ma sv: "; fflush(stdin); gets(X.maSV);
    cout << "\tTen: "; fflush(stdin); gets(X.tenSV);
    cout << "\tDiem tk: "; cin >> X.diemTK;
}
void NhapDS(List &L, int &n){
    L.count =-1;
    SV X;
    cout << "Nhap so phan tu: "; cin >> n;
    for(int i=0; i<n; i++){
        cout << "Nhap sv thu " << i+1 << ":" << endl;
        NhapSV(X);
        if(L.count>=max) return; //ktra ds day;
        L.count++;
        L.E[L.count]=X;
    }
}
void HienThiDS(List L){
    cout << setw(10) << "Ma sv" << setw(20) << "Ten sv" << setw(15) << "Diem tk" << endl;
    for(int i=0; i<=L.count; i++){
        cout << setw(10) << L.E[i].maSV << setw(20) << L.E[i].tenSV << setw(15) << L.E[i].diemTK << endl;
    }
}
void XoaDau(List &L){
    if(L.count==-1) return;
    for(int i=0; i<L.count; i++)
        L.E[i]=L.E[i+1];
    L.count--;
}
void Xoa(List &L, int k){
    for(int i=k; i<L.count; i++)
        L.E[i]=L.E[i+1];
    L.count--;
}
void XoaSV3(List &L){
    for(int i=0; i<=L.count; i++){
        if(strcmp(L.E[i].maSV,"3")==0){
            Xoa(L,i);
            i--;
        }
    }
}
void Chen(List &L){
    int k;
    do{
        cout << "Nhap vi tri can chen: "; cin >> k;
    }while(0>k || k>L.count);
    SV X;
    cout << "Nhap tt sv can chen: \n";
    NhapSV(X);
    if(L.count>=max) return;
    for(int i=L.count+1; i>k; i--){
        L.E[i]=L.E[i-1];
    }
    L.E[k]=X;
    L.count++;
}
int main(){
    List L;
    int n;
    NhapDS(L,n);
    cout << "\n===========================\n";
    HienThiDS(L);
    cout << "\n===========================\n";
    XoaDau(L);
    HienThiDS(L);
    cout << "\n===========================\n";
    XoaSV3(L);
    HienThiDS(L);
    cout << "\n===========================\n";
    Chen(L);
    HienThiDS(L);
}
