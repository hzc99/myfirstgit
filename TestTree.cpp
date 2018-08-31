//
// Created by Runix on 2018/8/26.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//#define MaxSize = 1000
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;

}BTnode;//树的链式结构(左子树,右子树)
void CreateBTnode(BTnode * &b , char *str);//生成一个二叉树；
void rotataBTree(BTnode *b);//将建好的树进行旋转;采用递归的方法来进行
void CreateBTnode (BTnode * &b,char *str)
{
    BTnode *St[1000],*p;
    int top = -1,k,j=0;
    char ch;
    b =NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch(ch)
        {
            case '(' :
                top++;
                St[top] = p ;
                k =1;
                break;
            case ')' :
                top--;
                break;
            case ',':
                k =2;
                break;
            default:p = (BTnode*)malloc(sizeof(BTnode));
                p->data =ch; p->lchild  = p->rchild = NULL;
                if(b==NULL){
                    b= p;
                }
                else{
                    switch(k)
                    {
                        case 1:St[top]->lchild = p;break;
                        case 2:St[top]->rchild = p;break;
                    }
                }

        }
        j++;
        ch = str[j];
    }
}

void preOrder(BTnode *b)
{
    if(b!= NULL)
    {
        printf("%c" , b->data);
        preOrder(b->lchild);
        preOrder(b->rchild);
    }
}
void inOrder(BTnode *b)
{
    if(b!= NULL)
    {
        inOrder(b->lchild);
        printf("%c" , b->data);
        inOrder(b->rchild);
    }
}
int main()
{
    char* tree = "A(B(D(,G)),C(E,F))";
    BTnode  * btree = NULL;
    cout<<"the preorder that tree not rotated "<<" ";
    CreateBTnode(btree,tree);
    preOrder(btree);
    cout<<endl;
    cout<<"the inorder that tree not rotated "<<" ";
    inOrder(btree);
    cout<<endl;
    cout<<"the preorder that tree rotated "<<" ";
    rotateBTree(btree);
    preOrder(btree);
    cout<<endl;
    cout<<"the inorder that tree rotated "<<" ";
    inOrder(btree);
    getchar();
    return 0;
}