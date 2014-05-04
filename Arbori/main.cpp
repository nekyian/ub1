#include <iostream>
#include <curses.h>
#include <limits>

using namespace std;

class bintree
{
    typedef struct bst
    {
        int data;
        struct bst *left, *right;
    }
    node;

    node *root, *New, *temp, *parent;

    public: bintree()
    {
        root = NULL;
    }

    void create();
    void display();
    void delet();
    void find();
    void insert(node *, node*);
    void inorder(node *);
    void postorder(node *);
    void search(node**, int, node **);
    void del(node *, int);

};

void bintree::create()
{

    New = new node;
    New->left = NULL;
    New->right = NULL;

    cout << "\n enter the element";
    cin >> New->data;

    if(root == NULL)
        root = New;
    else
        insert(root, New);

}

void bintree::insert(node *root, node *New)
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

}

void bintree::display()
{

    if(root == NULL)
        cout << "arborele nu este creat";
    else
    {
        cout << "\n arborele este: ";
        postorder(root);
    }

}

void bintree::inorder(node *temp)
{

    if(temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }

}

void bintree::postorder(node *temp)
{
    if(temp != NULL)
    {
        postorder(temp->right);
        cout << " " << temp->data;
        postorder(temp->left);
    }
}

void bintree::find()
{

    int key;

    cout << "\n introduceti elementul cautat";
    cin >> key;

    temp = root;
    search(&temp, key, &parent);

    if(temp == NULL)
        cout << "\n elementul cautat nu este prezent";
    else
        cout << "\n parintele nodului" << temp->data << " este " << parent->data;
}

void bintree::search(node **temp, int key, node ** parent)
{

    if(temp == NULL)
        cout << endl << " arborele nu este creat" << endl;
    else
    {
        while(*temp != NULL)
        {
            if((*temp)->data == key)
            {
                cout << "\n elementul " << (*temp)->data << " este prezent";
                break;
            }
            *parent = *temp; // retinem valoarea parintelui

            if((*temp)->data == key)
                *temp = (*temp)->left;
            else
                *temp = (*temp)->right;
        }
    }

    return;

}

void bintree::delet()
{

    int key;
    cout << "\n introduceti elemetul care urmeaza a fi sters";
    cin >> key;

    if(key == root->data)
    {
        bintree(); // asignam valoarea NULL radacinii root
    }
    else
    {
        del(root, key);
    }

}

void bintree::del(node *root, int key)
{

    node *temp_succ;

    if(root == NULL)
        cout << " arborele nu este creat";
    else
    {

        temp = root;
        search(&temp, key, &parent);

        if(temp->left != NULL && temp->right != NULL)
        {

            parent = temp;
            temp_succ = temp_succ->left;

            while(temp_succ->left != NULL)
            {
                parent = temp_succ;
                temp_succ = temp_succ->left;
            }

            temp->data = temp_succ->data;
            temp->right = NULL;

            cout << " elementul a fost sters!";

            return;
        }

        if(temp->left != NULL && temp->right == NULL)
        {
            if(parent->left == temp)
                parent->left = temp->left;
            else
                parent->right = temp->left;

            temp = NULL;
            delete temp;

            cout << " elementul a fost sters!";

            return;
        }

        if(temp->left == NULL && temp->right != NULL)
        {
            if(parent->left == temp)
                parent->left = temp->right;
            else
                parent->right = temp->right;

            temp = NULL;
            delete temp;

            cout << "elementul a fost sters!";

            return;
        }

        // stergerea unui nod care nu are copii
        if(temp->left == NULL && temp->right == NULL)
        {
            if(parent->left == temp)
                parent->left = NULL;
            else
                parent->right = NULL;

            cout << "elementul a fost sters!";

            return;
        }
    }

}





int main()
{

    int choice;

    char ans='N';
    bintree tr;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

    cout << "\n\t program pentru arbori binari de cautare";
    cout << "\n1.creare\n2.cautare\n3.stergere\n4.afisare";

    do
    {

        cout << "\n\n alegeti operatiunea:";
        cin >> choice;

        switch(choice)
        {
            case 1:
                do
                {
                    tr.create();
                    cout << "vreti sa introduceti si alt element?: (y/n)" << endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    ans = std::cin.get();
                } while(ans == 'y');
                break;

            case 2:
                tr.find();
                break;

            case 3:
                tr.delet();
                break;

            case 4:
                tr.display();
                break;
        }

    } while(choice != 5);

    return 0;
}
