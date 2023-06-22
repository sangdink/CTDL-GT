#include <bits/stdc++.h>
using namespace std ;

struct nhanvien {
	string id;
	string name ;
	int age ;
	double salary ;
};
struct Node {
	nhanvien data;
	Node* next ;
     
};
typedef Node *node ;
//định nghĩa  một cấu trúc node 
void nhapnhanvien(nhanvien &x){
	cout <<"nhap ma nhan vien :";
	getline(cin,x.id);
	cout <<"nhap ten nhan vien :";
	getline(cin,x.name);
	cout <<"nhap tuoi :";
	cin>>x.age;
	cout <<"nhap muc luong :";
	cin>>x.salary;
	cin.ignore(1);
}
// tạo một node mới ;
node  createnode (nhanvien x){
	node a = new Node ;
	a->data= x;
	a->next=nullptr ;
	
return a ;	
}
//định nghĩa một cấu trúc Linkedlist lưu trữ địa chỉ đầu vfa cuối  bằng con trỏ 
struct Linkedlist{
	node head ;
	node tail;
};
//khởi tạo một cấu trúc  mới ta có thể hai cong trỏ chỉ địa chỉ đầu cuối 
//bằng null 

void createlinkedlist (Linkedlist &l){
	l.head= nullptr ;
	l.tail= nullptr;
}
// thêm một phần tử vào đầu 
void addtohead(Linkedlist &l , node x){
	if (l.head==nullptr) {
		l.head = x;
		l.tail = x; 
	}
	else {
		x->next=l.head;
		l.head=x;
	}
}
// thêm vào cuối danh sách ;
void addtotail(Linkedlist &l, node x){
	if (l.head==nullptr){
		l.head=x;
		l.head=x;	
	}
	else{
		l.tail->next=x;
		l.tail=x ;
	}

// thêm node q vào sau vị trí node q bất kì trong danh sách ;
void addafterQ(Linkedlist &l, node p, node q){
	if (q==nullptr){
		addtohead(l,p);
	}
	else {
		p->next=q->next;
		q->next=p;
		if(l.tail==q){
			l.tail=p;
		}
		
	}
}
// xóa đầu danh sách 
void removehead (Linkedlist &l, nhanvien &x){
	if(l.head!=nullptr){
		node a= l.head;
		x= a->data;
		l.head =a->next;
		delete a;
		if(l.head==nullptr){
			l.tail==nullptr;	
		}
	}
}
// xóa bất kì trong danh sách danh sách sau node z ;
void removeQ(Linkedlist &l , nhanvien &x, node z ){
	if (z!=nullptr){
		node p = z->next;
		if (z->next!=nullptr){
			if (l.tail==z->next){
				l.tail=z;
			}
		z->next=p->next;
		delete p;
		}	
	}
}
//duyệt danh sách bằng lệnh in danh sach ;
void PrintList(Linkedlist l)
{
	if (l.head != NULL)
	{
		node a = l.head;
		while (a!= NULL)
		{
			cout <<a->data.id << ' ';
			cout <<a->data.name<< ' ';
			cout <<a->data.age << ' ';
			cout <<a->data.salary<< ' ';
			cout<<endl;
			a = a->next; // Chuyển sang node tiếp theo
		}
	}
}


// hàm tìm hiếm 
void search(Linkedlist l, string s){
	if(l.head!=nullptr){
		node a=l.head;
		int uk=1;
		while (a!=nullptr){
		
			string u=a->data.id;
			if(u==s){
				uk=0;
			cout <<"ma nhan vien: " <<a->data.id << endl;
			cout <<"ten nhan vien: "<<a->data.name<<endl;
			cout <<"tuoi nhan vien: "<<a->data.age <<endl;
			cout <<"luong thang nhan vien: "<<a->data.salary<<endl;
			cout<<endl;
			break;
			}
			a=a->next;
		}
		if(uk==1)cout<<"trong danh sachs khong co id can tim !";
	}
}
void timkiem(Linkedlist l){
	cout<<"nhap id can tim : ";
	string s; 
	getline(cin,s);
	search(l,s);
}

int main (){
	nhanvien a,b,c;
	nhapnhanvien (a);
	nhapnhanvien (b);
	nhapnhanvien (c);
	
	node n1,n2,n3;
	n1=createnode(a);
	
	n2=createnode(b);
	
	n3=createnode(c);
	
	
	Linkedlist l1;
	createlinkedlist(l1);
	
	addtohead(l1,n1);
	
	addtotail(l1,n3);
	cout<<"bang1"<<endl;
	PrintList(l1);
	
	addafterQ(l1,n2,n1);
	cout<<"bang1"<<endl;
	PrintList(l1);
	
	nhanvien d;
	nhapnhanvien(d);
	node n4;
	n4=createnode(d);
	addtotail(l1,n4);
	
	nhanvien u;
	removehead(l1,u);
	PrintList (l1);
	
	removeQ(l1,u,n2);

	cout<<"bang3"<<endl;
	PrintList (l1);
	timkiem(l1);

		
return 0;
}