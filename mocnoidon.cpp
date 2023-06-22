#include<bits/stdc++.h>
using namespace std;

struct SINHVIEN {
    char masv[10], hodem[30], ten[10];
    int namsinh;
    float diemtk;
};
struct Node {
    SINHVIEN infor;
    Node *next;
};
typedef Node *TRO;
void nhapSV(SINHVIEN &X) {
    cout << "\tNhap ma sinh vien: "; fflush(stdin); gets(X.masv);
    if(strcmp(X.masv,"***")==0) return;
    cout << "\tHo dem: "; fflush(stdin); gets(X.hodem);
    cout << "\tTen: "; fflush(stdin); gets(X.ten);
    cout << "\tNam sinh: "; cin >> X.namsinh;
    cout << "\tDiem tong ket: "; cin >> X.diemtk;
}
void nhapDS(TRO &L) {
    L = NULL; //Khởi tạo
    SINHVIEN X;
    TRO Q, P;
    int i=1;
    do {
        cout << "Nhap sv thu " << i << endl;
        nhapSV(X);
        if(strcmp(X.masv,"***")==0) return;
        P = new (Node);
        P->infor = X;
        P->next = NULL;
        if(L==NULL)
            L=P;
        else
            Q->next = P; //liên kết 1 nút rời vào danh sách, them nut P vao sau Q;
        Q=P; //Dich chuyen nut Q len thanh nut P;
        i++;
    } while(1);
}
void hienthiDS(TRO L){
    if(L==NULL){
        cout << "Danh sach rong!!";
        return;
    }
    cout << setw(5) << "STT";
    cout << setw(10) << "MaSV";
    cout << setw(25) << "Ho va ten";
    cout << setw(10) << "Nam sinh";
    cout << setw(10) << "Diem tk\n";
    TRO Q = L;
    int i=1;
    while(Q!=NULL){
        SINHVIEN X = Q->infor;
        cout << setw(5) << i; i++;
        cout << setw(10) << X.masv;
        cout << setw(17) << X.hodem;
        cout << setw(8) << X.ten;
        cout << setw(10) << X.namsinh;
        cout << setw(20) << X.diemtk << endl;
        Q=Q->next;
    }
}

int Length(TRO L){
    int n=0;
    TRO Q=L;
    while(Q!=NULL){
        n++;
        Q=Q->next;
    }
    return n;
}
void xoaSVdautien(TRO &L){
    if(L!=NULL){
        TRO Q=L;
        L=L->next;
        delete Q;
        cout << "Danh sach sau khi xoa sv dau tien:\n";
        hienthiDS(L);
        return;
    }
    cout << "Danh sach rong, khong the xoa\n";
}
TRO search(TRO L, char *ma){
    TRO Q=L;
    while(Q!=NULL && strcmp(Q->infor.masv,ma)!=0)
        Q->next;
    return Q;
}
void Remove(TRO &L, TRO T){
    TRO Q;
    if(L==T){
        L=T->next;
    }
    else{
        Q=L;
        while(Q->next != T)
            Q=Q->next; //tim nut dung truoc nut tro boi T
        Q->next=T->next; //bo qua nut T
    }
    delete T;
}
void xoa_SV8089(TRO &L){
    TRO T = search(L,"sv8089");
    if(T==NULL){
        cout << "Khong co ma sv nay!";
        return;
    }
    Remove(L,T);
    cout << "Danh sach vua xoa:\n";
    hienthiDS(L);
}
void FirstAdd(TRO &L,SINHVIEN X){
    TRO P;
    P = new (Node);
    P->infor = X;
    P->next = L;
    L=P;
}
void Insert(TRO &L, TRO Q, SINHVIEN X){
    TRO P;
    P = new (Node);
    P->infor = X;
    P->next = Q->next;
    Q->next = P;
}
void BoSung(TRO &L){
    int k;
    SINHVIEN X;
    do{
        cout<< "Nhap vi tri: "; cin >> k;
    }while(k<1 || k>Length(L));
    cout << "Nhap thong tin sinh vien can bo sung:\n";
    do{
        nhapSV(X);
        if(strcmp(X.masv,"***")==0){
            cout << "Nhap lai!\n";
        }
    }while(strcmp(X.masv,"***")==0);
    if(k==1)
        FirstAdd(L,X);
    else{
        TRO Q=L;
        int d=1;
        while(d<k-1){
            d++;
            Q=Q->next;
        }
        Insert(L,Q,X);
    }
    cout << "Danh sach vua bo sung:\n";
    hienthiDS(L);
}
int main() {
    TRO L;
    nhapDS(L);
    cout << "===============================\n";
    hienthiDS(L);
    cout << "===============================\n";
    xoaSVdautien(L);
    cout << "===============================\n";
    BoSung(L);
    cout << "===============================\n";

    cout << "===============================\n";

}
