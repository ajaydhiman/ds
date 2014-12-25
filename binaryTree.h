#ifndef _BSTREE_
#define _BSTREE_

class BSTree {
    private:
    struct Node {
        int data;
        Node *left;
        Node *right;

        Node(int d) {
            data = d;
            left = 0;
            right = 0;
        }
        ~Node() {
            cout<<"~Node()"<<endl;
            delete left;
            delete right;
        }
    };
        Node *root;
        void printTree(Node*);
        void Insert(Node*&, Node*);
        int size(Node*);
        int height(Node*);
        int getLeafNode(Node*);
        bool isSumProperty(Node*);
        int max(int, int);
        void treeToList(Node*, Node*&, Node*&);

    public:
        typedef Node* nodeptr;
        BSTree() { root = 0; }
        ~BSTree() { cout<<"~BSTree()"<<endl; delete root; }
        void Insert(int);
        void Delete();
        void Search(int);
        int Size();
        int height();
        int getLeafNode();
        void printTree();
        void levelOrder();
        void printLevel(int, int);
        bool isSumProperty();
        Node* treeToList();
        friend bool isIdenticalTree(BSTree*, BSTree*);
};

bool isIdenticalTree(BSTree::nodeptr, BSTree::nodeptr);

#endif
