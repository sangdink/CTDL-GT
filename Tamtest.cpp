#include<bits/stdc++.h>
using namespace std;

struct HANG{
    char maHang[10], tenHang[20];
    int soLuong;
};
struct Node{
    HANG infor;
    Node *next;
};
typedef Node *TRO;
void NhapHang(HANG &X){
    cout << "\tMa hang: "; fflush(stdin); gets(X.maHang);
    cout << "\tTen hang: "; fflush(stdin); gets(X.tenHang);
    cout << "\tSo luong: "; cin >> X.soLuong;
}
void NhapDS(TRO &L, int &n){
    L=NULL;
    HANG X;
    do{
        cout << "Nhap so mat hang: "; cin >> n;
        if(n<3) cout << "Nhap lai!\n";
    }while(n<3);
    TRO Q,P;
    for(int i=0; i<n; i++){
        cout << "Nhap mat hang thu " << i+1 << ":" << endl;
        NhapHang(X);
        P=new(Node);
        P->infor=X;
        P->next=NULL;
        if(L==NULL)
            L=P;
        else
            Q->next=P;
        Q=P;
    }
}
void HienThiDS(TRO L){
    TRO Q=L;
    cout << setw(10) << "Ma hang" << setw(20) << "Ten Hang" << setw(15) << "So luong" << endl;
    while(Q!=NULL){
        HANG X=Q->infor;
        cout << setw(10) << X.maHang << setw(20) << X.tenHang << setw(15) << X.soLuong << endl;
        Q=Q->next;
    }
}
void HangSLmin(TRO L){
    TRO Q=L;
    int Min=1e9;
    while(Q!=NULL){
        HANG X=Q->infor;
        if(X.soLuong<Min)
            Min=X.soLuong;
        Q=Q->next;
    }
    cout << "Cac mat hang co so luong nho nhat la: \n";
    cout << setw(10) << "Ma hang" << setw(20) << "Ten Hang" << setw(15) << "So luong" << endl;
    TRO P=L;
    while(P!=NULL){
        HANG X=P->infor;
        if(X.soLuong==Min)
            cout << setw(10) << X.maHang << setw(20) << X.tenHang << setw(15) << X.soLuong << endl;
        P=P->next;
    }
}
void Xoa(TRO &L, TRO T){
    if(L==T){
        TRO P=L;
        L=L->next;
        delete P;
    }
    else{
        TRO Q=L;
        while(Q->next!=T){
            Q=Q->next;
        }
        Q->next=T->next;
        Q=T->next;
    }
}
void XoaSLmax(TRO &L, int n){
    TRO Q=L;
    int Max=-1e9;
    while(Q!=NULL){
        HANG X=Q->infor;
        if(X.soLuong>Max)
            Max=X.soLuong;
        Q=Q->next;
    }
    TRO P=L;
    while(P!=NULL){
        HANG X=P->infor;
        if(X.soLuong==Max){
            Xoa(L,P);
            n--;
        }
        P=P->next;
    }
    HienThiDS(L);
}
void ChenVaoCuoi(TRO &L, int &n){
    cout << "Nhap tt hang can chen:\n";
    HANG X;
    NhapHang(X);
    TRO Q=L;

    TRO P;
    P=new(Node);
    P->infor=X;
    P->next=NULL;
    while(Q->next!=NULL)
        Q=Q->next;
    Q->next=P;
    Q=P;
    n++;
    HienThiDS(L);
}
int main(){
    TRO L;
    int n;
    NhapDS(L,n);
    cout << "\n=======================\n";
    cout << "Danh sach vua nhap:\n";
    HienThiDS(L);
    cout << "\n=======================\n";
    HangSLmin(L);
    cout << "\n=======================\n";
    XoaSLmax(L,n);
    cout << "\n=======================\n";
    ChenVaoCuoi(L,n);
    cout << "\n=======================\n";
}
