#include <iostream>

using namespace std;

template <class T>
class Arbore
{

    struct node
    {
        T data;
        struct node *left, *right;
    };

    node *root, *New, *temp, *parent;

    public: Arbore()
    {
        root = NULL;
    }
    
    Arbore(T const& element);
    void operator+(T const& element);
	void insert(node *root, node *New);
	
	void afiseaza();
	void inorder(node *temp);
	void postorder(node *temp);
	
};

template <class T>
Arbore<T>::Arbore(T const& element)
{
	New = new node;
    New->data = element;
	New->left = NULL;
    New->right = NULL;
    
    root = New;
}

// operator de inserare cheie in Arbore
template <class T>
void Arbore<T>::operator+(T const& element)
{
    // cream un Nod nou din elementul primit
    New = new node;
    New->data = element;
    New->left = NULL;
    New->right = NULL;
    cout << root << endl;
    cout << "Am creeat un nod nou:\ndata: " << element << endl;
    
//    root = New;
        
    if(root == NULL)
    	// inseram Nodul nou creat ca radacina
		root = New;
    else
    	// inseram Nodul nou creat in Arborele principal
        insert(root, New);
}

template <class T>
void Arbore<T>::insert(node *root, node *New)
{	
    // daca valoarea noului element e mai mica decat valoarea radacinii creem un subarbore stang
    if(New->data < root->data)
    {
        if(root->left == NULL) {
        	root->left = New;
            cout << "am introdus nodul nou ca copil stang" << endl;
        }
        else {
        	cout << "ne deplasam in jos stanga" << endl;
        	insert(root->left, New);
        }
        	
    }

    // daca valoarea noului element e mai mare decat valoarea radacinii creem un subarbore drept
    if(New->data > root->data)
    {
        if(root->right == NULL) {
        	root->right = New;
        	cout << "am introdus nodul nou ca copil drept" << endl;
        }
        else {
        	cout << "ne deplasam in jos dreapta" << endl;
        	insert(root->right, New);
        }
            
    }
}

template <class T>
void Arbore<T>::afiseaza()
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

