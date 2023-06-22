#include<bits/stdc++.h>
using namespace std;

struct SINHVIEN{
    char maSV[10], hoTen[30];
    int namSinh;
    float diemTK;
} ;
struct Node{
    SINHVIEN infor;
    Node *next;
};
typedef Node *TRO;
void NhapSV(SINHVIEN &X){
    cout << "Nhap ma sv: "; fflush(stdin); gets(X.maSV);
    if(strcmp(X.maSV,"")==0) return;
    cout << "\tHo ten: "; fflush(stdin); gets(X.hoTen);
    cout << "\tNam sinh: "; cin >> X.namSinh;
    cout << "\tDiem tong ket: "; cin >> X.diemTK;
}
void NhapDS(TRO &L){
    L = NULL;
    SINHVIEN X;
    TRO Q, P;
    int i=1;
    do{
        cout << "Nhap sv thu " << i << endl;
        NhapSV(X);
        if(strcmp(X.maSV,"")==0) return;
        P = new (Node);
        P->infor = X;
        P->next = NULL;
        if(L==NULL)
            L=P;
        else
            Q->next = P;
        Q=P;
        i++;
    }while(1);
}
void HienThiDS(TRO L){
    if(L==NULL){
        cout << "Danh sach rong\n";
        return;
    }
    cout << setw(5) << "STT" << setw(10) << "Ma sv" << setw(25) << "Ho va ten";
    cout << setw(15) << "Nam sinh" << setw(15) << "Diem tk\n";
    TRO Q=L;
    int i=1;
    while(Q!=NULL){
        SINHVIEN X = Q->infor;
        cout << setw(5) << i << setw(10) << X.maSV << setw(25) << X.hoTen;
        cout << setw(15) << X.namSinh << setw(15) << X.diemTK << endl;
        i++;
        Q=Q->next;
    }
}
int Length(TRO L){
    TRO Q=L;
    int n=0;
    while(Q!=NULL){
        n++;
        Q=Q->next;
    }
    return n;
}
TRO Search(TRO L, char *ma){
    TRO Q=L;
    while(Q!=NULL && strcmp(Q->infor.maSV, ma)!=0)
        Q=Q->next;
    return Q;
}
void TimKiem(TRO L){
    char ma[10];
    cout << "Nhap ma sv can tim: "; fflush(stdin);gets(ma);
    TRO T = Search(L,ma);
    if(T==NULL){
        cout << "Khong ton tai ma sv!\n";
        return;
    }
    TRO Q=L;
    while(Q!=T) Q=Q->next;
    SINHVIEN X = Q->infor;
    cout << setw(10) << "Ma sv" << setw(25) << "Ho va ten";
    cout << setw(15) << "Nam sinh" << setw(15) << "Diem tk\n";
    cout << setw(10) << X.maSV << setw(25) << X.hoTen;
    cout << setw(15) << X.namSinh << setw(15) << X.diemTK << endl;

}
int main(){
    TRO L;
    NhapDS(L);
    cout << "==============================\n";
    HienThiDS(L);
    cout << "==============================\n";
    cout << "Chieu dai danh sach: " << Length(L) << endl;
    cout << "==============================\n";
    TimKiem(L);
}
