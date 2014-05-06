#include<iostream>

using namespace std;

typedef struct nod
{
    int data;
    struct nod *left, *right;
};

class arbore
{
    nod *root, *New, *temp, *parent;

    public:
        arbore();
        ~arbore();
        arbore& operator<<(int);
        arbore& operator>>(int&);
        int vida();
        arbore& insert(nod *, nod *);
        void display();
        void inorder(nod *);

};

arbore::arbore()
{
    root=NULL;
    cout << "am creeat arborele\n";
}

arbore::~arbore()
{
    int n;
    while(!vida())
        operator>>(n);
}

arbore& arbore::operator<<(int n)
{
    New = new nod;
    New->data = n;
    New->left = NULL;
    New->right = NULL;
    cout << "am creat noul nod";

    if(root == NULL)
        root = New;
    else
        insert(root, New);

    return *this;
}

arbore& arbore::operator>>(int &n)
{
    nod *p;
    /*
    if(!vida()){
            n=root->data;
            p=root;
            v=root->leg;
            delete p;
    }
    */
    return *this;
}

int arbore::vida(){return root==NULL;}

arbore& arbore::insert(nod *root, nod *New)
{

    // daca valoarea noului element e mai mica decat valoarea radacinii creem un subarbore stang
    if(New->data < root->data)
    {
        if(root->left == NULL)
            root->left = New;
        else
            insert(root->left, New);
    }

    // daca valoarea noului element e mai mare decat valoarea radacinii creem un subarbore drept
    if(New->data > root->data)
    {
        if(root->right == NULL)
            root->right = New;
        else
            insert(root->right, New);
    }

    return *this;

}
void arbore::display()
{
    if(root == NULL)
        cout << "arborele nu este creat";
    else
    {
        cout << "\n arborele este: ";
        inorder(root);
    }
}

void arbore::inorder(nod *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

int main()
{

    arbore ar;

    ar.display();

    cout << "incarcam arborele\n";

    int v[] = {1, 23, 3, 142, 14, 57};
    for(int i = 0; i < 6; i++) {
        cout << v[i] << endl;
        ar<<(v[i]);
    }

    cout << "afisam arborele\n";

    ar.display();

    return 0;

}

