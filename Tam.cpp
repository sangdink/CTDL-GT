#include<bits/stdc++.h>
using namespace std;

struct HANG{
    char maHang[10], tenHang[30];
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
    do{
        cout << "Nhap so mat hang: "; cin >> n;
        if(n<3) cout << "Nhap lai!\n";
    }while(n<3);

    L = NULL;
    HANG X;
    TRO Q, P;
    for(int i=0; i<n; i++){
        cout << "Nhap sv thu " << i+1 << ":\n";
        NhapHang(X);
        P = new (Node);
        P->infor=X;
        P->next=NULL;
        if(L==NULL){
            L=P;
        }
        else{
            Q->next=P;
        }
        Q=P;
    }
}
void HienThiDS(TRO L){
    if(L==NULL){
        cout << "Danh sach rong!!";
        return;
    }
    cout << setw(10) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "So luong" << endl;
    TRO Q=L;
    while(Q!=NULL){
        HANG X=Q->infor;
        cout << setw(10) << X.maHang << setw(20) << X.tenHang << setw(15) << X.soLuong << endl;
        Q=Q->next;
    }
}
void HangSLmin(TRO L){
    int Min=1e9;
    TRO Q=L;
    while(Q!=NULL){
        HANG X = Q->infor;
        if(X.soLuong<Min)
            Min=X.soLuong;
        Q=Q->next;
    }
    cout << "Cac mat hang co so luong nho nhat: \n";
    cout << setw(10) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "So luong" << endl;
    TRO P=L;
    while(P!=NULL){
        HANG X = P->infor;
        if(X.soLuong==Min)
            cout << setw(10) << X.maHang << setw(20) << X.tenHang << setw(15) << X.soLuong << endl;
        P=P->next;
    }
}
void chenVaoCuoi(TRO L, int &n){
    HANG X;
    cout << "Nhap tt hang can chen: \n";
    NhapHang(X);
    TRO P;
    P=new(Node);
    P->infor=X;
    P->next=NULL;
    TRO Q=L;
    while(Q->next!=NULL){
        Q=Q->next;
    }
    Q->next=P;
    Q=P;
    n++;
    HienThiDS(L);
}
void Xoa(TRO &L, TRO P){
    TRO Q=L;
    if(L==P){
        L=L->next;
        delete Q;
    }
    else{
        while(Q->next!=P){
            Q=Q->next;
        }
        Q->next=P->next;
        delete P;
    }
}
void XoaHangSLmax(TRO &L, int &n){
    int Max=-1e9;
    TRO Q=L;
    while(Q!=NULL){
        HANG X = Q->infor;
        if(X.soLuong>Max)
            Max=X.soLuong;
        Q=Q->next;
    }
    TRO P=L;
    while(P!=NULL){
        HANG X = P->infor;
        if(X.soLuong==Max){
            Xoa(L,P);
            n--;
        }
        P=P->next;
    }
    HienThiDS(L);
}
int main(){
    int n;
    TRO L;
    NhapDS(L,n);
    cout << "\n============================\n";
    HangSLmin(L);
    cout << "\n============================\n";
    XoaHangSLmax(L,n);
    cout << "\n============================\n";
    chenVaoCuoi(L,n);
    cout << "\n============================\n";
    cout << n;
}
