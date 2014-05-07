#include <iostream>
//#include <iomanip>
//#include <assert.h> 
//
//

using namespace std;

template <class T>
class Arbore
{

        typedef struct bst
        {
            T data;
            struct bst *left, *right;
        } node;

        node *root, *New, *temp, *parent;

    public:
        Arbore()
        {
            root = NULL;
        }

        //void create();
        void create (T const& element);
        void operator+(T const& element);
        void insert(node *root, node *New);

        void afiseaza();
        void inorder(node *temp);
        void postorder(node *temp);

};

template <class T>
//void Arbore<T>::create()
void Arbore<T>::create(T const& element)

//modificata (deocamdata) pentru testare sa preia direct v[0] ca radacina. in varianta finala vom citi pe rand
//radacina si elementele. 

{
    New = new node;
    New->left = NULL;
    New->right = NULL;
    
    //cout << "\n introduceti primul element al arborelui: \n";
    //cin >> New->data;
    
    New->data = element;
    
    if(root == NULL)
    {
        root = New;
        cout << " \n am creeat radacina arborelui, cu valoare " << New->data << endl;
    }
    else;
        insert(root, New);
}

// operator de inserare cheie in Arbore
template <class T>
void Arbore<T>::operator+(T const& element)
{
    // cream un Nod nou din elementul primit

    
    New = new bst;
    New->data = element;
    New->left = NULL;
    New->right = NULL;
    cout << " \n Am creeat un nod nou:\ndata: " << element << endl;
    // inseram Nodul nou creat in Arborele principal
    insert(root, New);
    

}

template <class T>
void Arbore<T>::insert(node *root, node *New)
{
    // daca valoarea noului element e mai mica decat valoarea radacinii creem un subarbore stang
    if(New->data < root->data)
    {
        if(root->left == NULL)
        {
            root->left = New;
            cout << " \n am introdus nodul nou = copil stang al lui " <<" "<<root->data; 
			//afiseaza explicit unde il introduce
        }
        else
        {
            cout << " ne deplasam in jos stanga \n" << endl;
            insert(root->left, New);
        }
    }
    // daca valoarea noului element e mai mare decat valoarea radacinii creem un subarbore drept
    if(New->data > root->data)
    {
        if(root->right == NULL)
        {
            root->right = New;
            cout << " \n am introdus nodul nou = copil drept al lui " <<" "<<root->data;
            //afiseaza explicit unde il introduce
        }
        else
        {
            cout << "ne deplasam in jos dreapta  \n" << endl;
            insert(root->right, New);
        }
    }
}

template <class T>
void Arbore<T>::afiseaza() 
// TO DO: afisare gen ((a)(c)(e)) etc
{
    if(root == NULL)
        cout << "arborele nu este creat";
    else
    {
        cout << "alegeti tipul de parcurgere dorit:\n1. inordine\n2.postordine\n";
        int tip;
        cin >> tip;
        cout << "\n arborele este: ";
        switch(tip)
        {
        case 1:
            inorder(root);
            break;
        case 2:
            postorder(root);
            break;
        }
    }
}

template <class T>
void Arbore<T>::inorder(node *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

template <class T>
void Arbore<T>::postorder(node *temp)
{
    if(temp != NULL)
    {
        postorder(temp->right);
        cout << " " << temp->data;
        postorder(temp->left);
    }
}



