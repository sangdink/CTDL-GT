#include<bits/stdc++.h>
using namespace std;

struct SINHVIEN{
    char maSV[10], hoTen[30];
    int namSinh;
    double diemTK;
};
struct Node{
    SINHVIEN infor;
    Node *next;
};
typedef Node *TRO;
void NhapSV(SINHVIEN &X){
    cout << "\tNhap ma sv: "; fflush(stdin); gets(X.maSV);
    cout << "\tHo va ten: "; fflush(stdin); gets(X.hoTen);
    cout << "\tNam sinh: "; cin >> X.namSinh;
    cout << "\tDiem tong ket: "; cin >> X.diemTK;
}
void NhapDS(TRO &L, int n){
    L = NULL;
    SINHVIEN X;

    int i=1;
    TRO Q, P;
    while(i<=n){
        cout << "Nhap sv thu " << i << endl;
        NhapSV(X);
        P = new (Node);
        P->infor = X;
        P->next = NULL;
        if(L==NULL){
            L=P;
        }
        else{
            Q->next=P;
        }
        Q=P;
        i++;
    }
}
void HienThiDS(TRO L){
    if(L==NULL){
        cout << "Danh sach rong!\n";
        return;
    }
    TRO Q=L;
    cout << setw(5) << "STT" << setw(10) << "Ma sv" << setw(25) << "Ho ten";
    cout << setw(15) << "Nam sinh" << setw(15) << "Diem tk" << endl;
    int i=1;
    while(Q!=NULL){
        SINHVIEN X = Q->infor;
        cout << setw(5) << i << setw(10) << X.maSV << setw(25) << X.hoTen;
        cout << setw(15) << X.namSinh << setw(15) << X.diemTK << endl;
        i++;
        Q=Q->next;
    }
}
//TRO Search(TRO L, double diem){
//    TRO Q=L;
//    while(Q!=NULL && Q->infor.diemTK!=diem)
//        Q = Q->next;
//    return Q;
//}
void HienThiDSSV_dtkH65(TRO L){
    //TRO T = Search(L,6.5);
//    if(T==NULL){
//        cout << "Khong ton tai sv nao co diem tong ket > 6.5!\n";
//        return;
//    }
    TRO Q=L;
    cout << "Danh sach sinh vien co diem tk > 6.5:\n";
    cout << setw(5) << "STT" << setw(10) << "Ma sv" << setw(25) << "Ho ten";
    cout << setw(15) << "Nam sinh" << setw(15) << "Diem tk" << endl;
    int i=0;
    while(Q!=NULL){
        SINHVIEN X = Q->infor;
        if(X.diemTK>=6.5){
            i++;
            cout << setw(5) << i << setw(10) << X.maSV << setw(25) << X.hoTen;
            cout << setw(15) << X.namSinh << setw(15) << X.diemTK << endl;

        }
        Q=Q->next;
    }
    if(i==0){
        cout << "Khong ton tai sv nao co diem tong ket > 6.5!\n";
    }
}
void ChenVaoDau(TRO &L, SINHVIEN X){
    TRO P;
    P = new (Node);
    P->infor = X;
    P->next = L;
    L=P;
}
void Chen(TRO &L, int &n){
    int k;
    SINHVIEN X;
    do{
        cout << "Nhap vi tri can chen: "; cin >> k;
    } while(k<1 || k>n);
    NhapSV(X);
    if(k==1){
        ChenVaoDau(L,X);
    }
    else{
        TRO Q,P;
        Q=L;
        int i=1;
        while(i<k-1){
            i++;
            Q=Q->next;
        }
        P = new(Node);
        P->infor = X;
        P->next = Q->next;
        Q->next=P;
    }
    n++;
    HienThiDS(L);
}
void ChenCuoi(TRO &L, int &n){
    SINHVIEN X;
    NhapSV(X);
    TRO Q=L;
    int i=1;
    while(i<n){
        i++;
        Q = Q->next;
    }
    TRO P;
    P=new(Node);
    P->infor = X;
    P->next = NULL;
    Q->next = P;
    n++;
    HienThiDS(L);
}
int main(){
    TRO L;
    int n;
    cout << "Nhap n: "; cin >> n;
    NhapDS(L,n);
    cout << "===================================\n";
    HienThiDS(L);
    cout << "===================================\n";
    HienThiDSSV_dtkH65(L);
    cout << "===================================\n";
    Chen(L,n);
    cout << "===================================\n";
    ChenCuoi(L,n);
}

