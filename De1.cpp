#include<bits/stdc++.h>
using namespace std;

struct MH{
    char maMH[10], tenMH[30];
    int soTC;
};
struct Node{
    MH infor;
    Node *next;
};
typedef Node *TRO;
void NhapMH(MH &x){
    cout << "Nhap ma mh: "; fflush(stdin); gets(x.maMH);
    cout << "Nhap ten mh: "; fflush(stdin); gets(x.maMH);
    cout << "Nhap so tc: "; cin >> x.soTC;
}
void NhapList()
int main(){
    MH x;
    NhapMH(x);
}
