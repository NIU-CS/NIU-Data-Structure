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
    cout <<"\n�e�Ǩ��X���G=> ";
    preorder(tree);

	cout <<"\n";
    system("PAUSE");
    return 0;
}

NODE *crt_bt(){
    NODE *ptr;
    char data;

    fscanf(fin,"%c",&data);
    if(data == '0')
        return NULL;
    //�إ߸`�I: �Ч����H�U�|��{��




    return ptr;
}

void visit(NODE *p){
    cout <<p->data <<" ";
}
void preorder(NODE *p){
    if(p != NULL){
    	//�e�Ǩ��X:�Ч����H�U�T��{��



    }
}


