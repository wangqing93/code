#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
    node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

node* findMinCommon(node* x, node* y, node* root)
{
    if (root == NULL)
        return NULL;
    if (x == root || y == root)
        return root;
    node* left = findMinCommon(x, y, root->left);
    node* right = findMinCommon(x, y, root->right);
    if (left != NULL && right != NULL)
        return root;
    if (right == NULL)
        return left;
    else
        return right;

}

int getDis(node* x, node* root)
{
    //BFS
    if (x == root || x == NULL || root == NULL)
        return 0;
    queue<node*> mark;
    mark.push(root);
    int depth = 0;
    while(!mark.empty())
    {
        node* temp = mark.front();
        mark.pop();
        if (temp->left != NULL)
        {
            if (x == temp->left)
                return ++depth;
            else
                mark.push(temp->left);
        }
        if (temp->right != NULL)
        {
            if (x == temp->right)
                return ++depth;
            else
                mark.push(temp->right);
        }
        depth++;
    }
}

int getTwoMin(node* root, node* x, node* y)
{
    node* comm = findMinCommon(x, y, root);
    return getDis(x, comm) + getDis(y, comm);
}
void printTree(node* x, int blanklen)
{
    if (x == NULL)
        return;
    for (int i = 0; i < blanklen; i++)
        cout <<" ";
    cout << x->value << endl;
    printTree(x->left, blanklen+1);
    printTree(x->right, blanklen+1);
}

int main()
{
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    node* n5 = new node(5);
    node* n6 = new node(6);
    n1->left = n2;
    n1->right = n5;
    n2->left = n3;
    n2->right = n4;
    n3->left = n6;
    printTree(n1,0);
    cout << getTwoMin(n1, n2, n5);
    system("pause");
    return 0;
}
