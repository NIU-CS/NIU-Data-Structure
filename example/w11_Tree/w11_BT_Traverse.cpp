#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Tnode{
    struct Tnode *left_c;
    char   data;
    struct Tnode *right_c;
}NODE;
NODE *crt_bt();
void preorder(NODE *p);
void inorder(NODE *p);
void postorder(NODE *p);
void visit(NODE *p);
FILE *fin;

int main(void){
	NODE *tree;		
	if ((fin=fopen("Tree.dat","r"))==NULL){
		cout <<"Tree.dat Not Found !";
		exit(1);
	}    
	tree=crt_bt();
	fclose(fin);
    cout <<"\n前序走訪結果=> ";
    preorder(tree);

	cout <<"\n中序走訪結果=> ";
    inorder(tree);

    cout <<"\n後序走訪結果=> ";
    postorder(tree);
    
	cout <<"\n";
    system("PAUSE");	
    return 0;
}

NODE *crt_bt(){	
    NODE *ptr;
    char data;

    fscanf(fin,"%c",&data);
    if(data == '0')
        return (NULL);
    ptr=new NODE;
    ptr->data=data;
    ptr->left_c=crt_bt();
    ptr->right_c=crt_bt();
    return(ptr);
}

void visit(NODE *p){
    cout <<p->data <<" ";
}
void preorder(NODE *p){
    if(p != NULL){
        visit(p);
        preorder(p->left_c);
        preorder(p->right_c);
    }
}
void inorder(NODE *p){
    if(p != NULL){
        inorder(p->left_c);
        visit(p);
        inorder(p->right_c);
    }
}
void postorder(NODE *p){
   if(p != NULL){
        postorder(p->left_c);
        postorder(p->right_c);
        visit(p);
   }
}


