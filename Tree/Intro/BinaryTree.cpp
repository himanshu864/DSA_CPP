#include <iostream>
#include <queue>

using namespace std;

// Creating Binary Trees via nodes (Linked Lists)
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node(int x) : lchild(NULL), data(x), rchild(NULL) {}
};

class Tree
{
private:
    Node *root;

public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() { Preorder(root); } // Passing Private Parameter in Constructor
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    void Postorder(Node *p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); }
    int Height(Node *p);
    int Height() { return Height(root); }
};

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    // TODO
}

void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    cout << "Enter root data: " << flush;
    cin >> x;
    root = new Node(x);
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->lchild = t;
            q.push(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->rchild = t;
            q.push(t);
        }
    }
}

// simple recursive traversals
void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

// same as creating BT using queue
void Tree::Levelorder(Node *p)
{
    queue<Node *> q;
    cout << root->data << ", " << flush;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p->lchild)
        {
            cout << p->lchild->data << ", " << flush;
            q.push(p->lchild);
        }

        if (p->rchild)
        {
            cout << p->rchild->data << ", " << flush;
            q.push(p->rchild);
        }
    }
}

// Big brain recursion to find longest descendant of root
int Tree::Height(Node *p)
{
    if (p == nullptr)
        return 0;

    int l = Height(p->lchild);
    int r = Height(p->rchild);
    return max(l, r) + 1;
}

int main()
{

    Tree bt;

    bt.CreateTree();
    cout << endl;

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl;

    return 0;
}
