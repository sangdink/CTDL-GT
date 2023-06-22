#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
typedef struct node node; //C++ thi ko can

node* makeNode(int x){
    //node *newNode = (node*)malloc(sizeof(node));
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){
    while(head !=NULL){
        cout << head->data << ' ';
        head = head->next;
    }
}
int count(node *head){
    int dem=0;
    while(head!=NULL){
        ++dem;
        head=head->next;
    }
    return dem;
}
//Them 1 nutvao dau
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    //Buoc 1: phan next cua newNode => head
    newNode->next = *head; //*head => dia chi cua node head trong dslk
    //Buoc 2: Cap nhat node head => newNode
    *head = newNode;
}
//Them 1 nut vao cuoi danh sach
void pushBack(node **head, int x){
    node *temp = *head;
        node *newNode = makeNode(x);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
       temp = temp->next;
    }
    //cho phan next cua node temp -> newnode
    temp->next = newNode;
}
void pushBack2(node *&head, int x) {
    node *temp = head;
    node *newNode = makeNode(x);
    if(head==NULL){
        head = newNode; return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    //cho phan next cua node temp -> newnode
    temp->next = newNode;
}
//Chen 1 nut vao giua danh sach:
void insert(node **head, int k, int x) {
    int n = count(*head); //so luong node trong danh sach lien ket;
    if(k<1 || k>n+1) return;
    if(k==1){
        pushFront(head,x); return;
    }
    node *temp=*head;
    for(int i=1; i<=k-2; i++) {
        temp=temp->next;
    }
    //temp: k-1;
    node *newNode = makeNode(x);
    newNode->next = temp->next; //gan dia chi cua not k cho newNode
    temp->next = newNode; //Gan gia tri cua newNode vao k: temp->next
}
//void insert2(node *&head, int k, int x) {
//    int n = count(head); //so luong node trong danh sach lien ket;
//    if(k<1 || k>n+1) return;
//    if(k==1){
//        pushFront(head,x); return;
//    }
//    node *temp=head;
//    for(int i=1; i<=k-2; i++) {
//        temp=temp->next;
//    }
//    //temp: k-1;
//    node *newNode = makeNode(x);
//    newNode->next = temp->next; //gan dia chi cua not k cho newNode
//    temp->next = newNode; //Gan gia tri cua newNode vao k: temp->next
//}

void popFront(node **head){
    if(*head==NULL) return;
    node *temp=*head;
    *head = (*head)->next;
    //free(temp);
    delete temp;
}
void popBack(node **head){
    if(*head==NULL) return;
    node *temp=*head;
    if(temp->next == NULL){
        *head=NULL; delete temp;
        return;
    }
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    node *last=temp->next; //node cuoi
    temp->next=NULL;
    delete last;
}
void erase(node **head, int k){
    int n=count(*head);
    if(k<1 || k>n) return; //ko xoa
    if(k==1) popFront(head);
    else{
        node *temp=*head;
        for(int i=1; i<=k-2; i++)
            temp=temp->next;
        node *kth = temp->next; //nde thu k;
        temp->next=kth->next;
        delete kth;
    }
}
void erase2(node *&head, int k){
    int n=count(head);
    if(k<1 || k>n) return; //ko xoa
    if(k==1) popFront(head);
    else{
        node *temp=head;
        for(int i=1; i<=k-2; i++)
            temp=temp->next;
        node *kth = temp->next; //nde thu k;
        temp->next=kth->next;
        delete kth;
    }
}
int main(){
////pushFront
//    node *head = NULL;
//    for(int i=1; i<=5; i++) {
//        pushFront(&head,i);
//    }
//    duyet(head);
//    cout << count(head);

////PushBack
//    node *head = NULL;
//    for(int i=1; i<=10; i++)
//        pushBack(&head,i);
//    duyet(head);
//    cout << endl;
//    for(int i=1; i<=10; i++)
//        pushBack2(head,i);
//    duyet(head);

////Lua chon:
    node *head = NULL;
	while(1){
		cout << "------------------------------------\n";
		cout << "1. Them vao dau\n";
		cout << "2. Them vao cuoi\n";
		cout << "3. Them vao giua\n";
		cout << "4. Xoa dau\n";
		cout << "5. Xoa cuoi\n";
		cout << "6. Xoa giua\n";
		cout << "7. Duyet\n";
		cout << "0. Thoat !\n";
		cout << "------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x :"; cin >> x;
			pushFront(&head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap x :"; cin >> x;
			pushBack(&head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap x :"; cin >> x;
			int k; cout << "Nhap k :"; cin >> k;
			insert(&head, k, x);
		}
		else if(lc == 4){
            popFront(&head);
		}
		else if(lc == 5){
            popBack(&head);
		}
		else if(lc == 6){
            int k; cout << "Nhap vi tri xoa: "; cin >>k;
            erase(&head,k);
		}
		else if(lc == 7){
			duyet(head);
			cout << endl;
		}
		else{
			break;
		}
	}

    //node *head = NULL;
}
