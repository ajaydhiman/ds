#include<iostream>
#include<queue>
using namespace std;

#include"binaryTree.h"


void BSTree::Insert(Node *&r, Node* node) {
    if (r == NULL) {
        r = node;
        return;
    }

    if (r->data < node->data) 
        Insert(r->right, node);
    else
        Insert(r->left, node);
}

void BSTree::Insert(int data) {
    Node *node = new Node(data);
    Insert(root, node);
}

void BSTree::Delete() {
}

void BSTree::Search(int d) {
}

void BSTree::printTree(Node *root) {
    if (root) {
        printTree(root->left);
        cout<<root->data<<endl;
        printTree(root->right);
    }
}

int BSTree::size(Node *r) {
    if (r == NULL)
        return 0;

    return size(r->left) + size(r->right) + 1; 
}

int BSTree::Size() {
    return size(root);
}

void BSTree::printLevel(int low, int high) {
    queue<Node*> qu;  
    qu.push(root);
    qu.push(NULL);
    int level = 1;
    while (qu.size() > 0) {
        Node* tmp = (Node*)qu.front();
        qu.pop();
        if (tmp == NULL) {
            ++level;
            if (qu.size() > 0)
                qu.push(NULL);
        }
        else {
            if (level >= low && level <= high)
                cout<<tmp->data<<" ";
            if (tmp->left)
                qu.push(tmp->left);
            if (tmp->right)
                qu.push(tmp->right);
        }
    }

    cout<<endl;
}

void BSTree::levelOrder() {
    queue<Node*> qu;  
    qu.push(root);
    qu.push(NULL);
    int level = 0;
    while (qu.size() > 0) {
        Node* tmp = (Node*)qu.front();
        qu.pop();
        if (tmp == NULL) {
            cout<<endl<<"level : "<<++level<<" completed"<<endl;
            if (qu.size() > 0)
                qu.push(NULL);
        }
        else {
            cout<<tmp->data<<" ";
            if (tmp->left)
                qu.push(tmp->left);
            if (tmp->right)
                qu.push(tmp->right);
        }
    }
}

int BSTree::getLeafNode(Node* r) {
    if (r == NULL)
        return 0;
    if (r->left == NULL && r->right == NULL)
        return 1;

    return getLeafNode(r->left) + getLeafNode(r->right);
}

int BSTree::getLeafNode() {
    return getLeafNode(root);
}

bool BSTree::isSumProperty(Node* r) {
    if (r == NULL || (r->left == NULL && r->right == NULL))
        return 1;

    int left_data = 0, right_data = 0;
    if (r->left)
        left_data = r->left->data;
    if (r->right)
        right_data = r->right->data;

    return (root->data == left_data + right_data) && isSumProperty(r->left) && isSumProperty(r->right);
}

bool BSTree::isSumProperty() {
    return isSumProperty(root);
}

int BSTree::max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int BSTree::height(Node* r) {
    if (r == NULL)
        return 0;

   return 1 + max(height(r->left), height(r->right));
}

int BSTree::height() {
    return height(root);
}

bool isIdenticalTree(BSTree::nodeptr a, BSTree::nodeptr b) {
    if (!a && !b)
       return 1;

   return a && b && (a->data == b->data) && isIdenticalTree(a->left, b->left) && isIdenticalTree(a->right, b->right); 
}

bool isIdenticalTree(BSTree *a, BSTree *b) {
    isIdenticalTree(a->root, b->root);
}

void BSTree::treeToList(Node *r, Node *&prev, Node *&head) {
    if (!r)
        return;

    treeToList(r->left, prev, head);
    if (!prev) {
        head = r;
    }
    else {
        r->left = prev;
        prev->right = r;
    }

    prev = r;
    treeToList(r->right, prev, head);
}

BSTree::nodeptr BSTree::treeToList() {
    Node *head = NULL, *prev = NULL;
    treeToList(root, prev, head);
    return head;
}

void BSTree::printTree() {
    printTree(root);
}

int main() {
    BSTree *tree = new BSTree();
    tree->Insert(4);
    tree->Insert(2);
    tree->Insert(3);
    tree->Insert(1);
    tree->Insert(6);
    tree->Insert(5);
    tree->Insert(7);
    tree->Insert(8);
    BSTree *tree1 = new BSTree();
    tree1->Insert(4);
    tree1->Insert(2);
    tree1->Insert(3);
    tree1->Insert(1);
    tree1->Insert(6);
    tree1->Insert(5);
    tree1->Insert(7);
    tree1->Insert(9);

    cout<<"isIdentical : "<<isIdenticalTree(tree, tree1)<<endl;
    tree->printTree();
    cout<<"size : "<<tree->Size()<<endl;
    cout<<"Leaf Nodes Count : "<<tree->getLeafNode()<<endl;
    tree->levelOrder();
    tree->printLevel(2, 3);
    cout<<"height : "<<tree->height()<<endl;
    BSTree::nodeptr head = tree->treeToList();
    while (head) {
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<endl;

    //delete tree;
}
