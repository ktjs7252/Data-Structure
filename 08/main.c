#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode* bt)
{
   // 1. 재귀함수 탈출 조건.
   if (bt == NULL)
      return;

   // 2. 재귀 MAIN LOGIC
   InorderTraverse(bt->left);
   printf("%d ", bt->data);
   InorderTraverse(bt->right);
   
     if (bt->right != NULL)
     {
         printf("%d ", bt->right->data);
     }

   //if (bt->left == NULL)
   //{
   //   printf("%d ", bt->data);
   //}
   //else
   //{
   //   InorderTraverse(bt->left);
   //   printf("%d ", bt->data);

   //   if (bt->right != NULL)
   //   {
   //      InorderTraverse(bt->right);
   //   }
   //}
}

void PreorderTraverse(BTreeNode* bt)
{
   // 1. 재귀함수 탈출 조건.
   if (bt == NULL)
      return;

   // 2. 재귀 MAIN LOGIC
   printf("%d ", bt->data);
   PreorderTraverse(bt->left);
   PreorderTraverse(bt->right);
}

int main(void)
{
   BTreeNode* bt1 = MakeBTreeNode();
   BTreeNode* bt2 = MakeBTreeNode();
   BTreeNode* bt3 = MakeBTreeNode();
   BTreeNode* bt4 = MakeBTreeNode();
   BTreeNode* bt5 = MakeBTreeNode();
   BTreeNode* bt6 = MakeBTreeNode();
   BTreeNode* bt7 = MakeBTreeNode();

   SetData(bt1, 1);
   SetData(bt2, 2);
   SetData(bt3, 3);
   SetData(bt4, 4);
   SetData(bt5, 5);
   SetData(bt6, 6);
   SetData(bt7, 7);

   MakeLeftSubTree(bt1, bt2);
   MakeRightSubTree(bt1, bt3);
   MakeLeftSubTree(bt2, bt4);
   MakeRightSubTree(bt2, bt5);
   MakeLeftSubTree(bt4, bt7);
   MakeRightSubTree(bt3, bt6);


   InorderTraverse(bt1);

   return 0;
}
