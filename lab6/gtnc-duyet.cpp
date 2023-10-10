#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left; 
	Node *right;
};
typedef Node*Tree;

void KhoiTao(Tree &root){
	root=NULL;
}
Node*TaoNut(int x){
	Node*p=new Node;
	if(p!=NULL){
		p->data=x;
		p->left=p->right=NULL;
	}
	return p;
}
void ChenNut(Tree &root, Node*p){
	if(root!=NULL){
		if(root->data==p->data){
			return;}
		else if(root->data>p->data){
			ChenNut(root->left,p);
		} else {
			ChenNut(root->right,p);
		}
	} 
	else root=p;
}

void TaoCay(Tree &root){
	int n, x;
	cout<<"Nhap so nut can tao: ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"Nhap gia tri: ";
		cin>>x;
		Node*p=TaoNut(x);
		if(p!=NULL){
			ChenNut(root,p);
		}
	}
}

void DuyetGiua(Tree root){
	if(root!=NULL){
		DuyetGiua(root->left);
		cout<<root->data<<" ";
		DuyetGiua(root->right);
	}
}
//void DuyetTruoc(Tree root){
//	if(root!=NULL){
//		cout<<root->data<<" ";
//		DuyetTruoc(root->left);
//		DuyetTruoc(root->right);
//	}
//}
//void DuyetSau(Tree root){
//	if(root!=NULL){
//		DuyetSau(root->left);
//		DuyetSau(root->right);
//		cout<<root->data<<" ";
//	}
//}
Node *TimKiem(Tree root, int x){
    if(root!=NULL){
    	if(root->data==x)
    	    return root;
    	else if(root->data< x)
    	    return TimKiem(root->right, x);
    	else
    	    return TimKiem(root->left, x);
	}
}
main(){
	Tree root;
	KhoiTao(root);
	TaoCay(root);
	cout<<"\n Cay da tao:  ";
	DuyetGiua(root);
//	DuyetTruoc(root);
//	DuyetSau(root);
    int x;
    cout<<"nhap khoa can tim: ";
    cin>>x;
    Node *p=TimKiem(root, x);
    if(p!=NULL)
      cout<<"co nut chua khoa "<< x <<"tren cay.";
    else
      cout<<"khong co chua nut khoa "<< x <<"!";
}
