#include<iostream>
#include <typeinfo>

using namespace std;

template <class T>
class Arbore
{
	private:
		T data;
		Arbore<T> *left;
		Arbore<T> *right;
	
	Arbore<T> *root, *New, *temp, *parent;
	
	public:
        Arbore();	// constructor
        int vida();	// helper method returneaza 1 daca arborele e gol
        ~Arbore();	// destructor - elimina nod cu nod pana cand arborele e gol (radacina == NULL)
        
        void create(T const&);
        
        void operator+(T const&);				// operator de inserare cheie in Arbore
        void insert(Arbore<T> *, Arbore<T> *);	// functie de inserare cheie in Arbore
        
        void operator-(T const&);				// operator de stergere cheie din Arbore
        
        void inorder(Arbore<T> *);		// parcurgere inordine a Arborelui
        void afiseaza();
        
        
        
};

template <class T>
Arbore<T>::Arbore()
{
    root=NULL;
    cout << "am creeat arborele\n";
}

template <class T>
int Arbore<T>::vida(){return root==NULL;}

template <class T>
Arbore<T>::~Arbore()
{
//    int n;
//    while(!vida()) {
//    	root-(n);
//    	cout << "am scos cheia " << n << "din Arbore" << endl;
//    }   
//    cout << "am scos toate cheile din arbore" << endl;
}

// metoda care creeaza un Arbore
template <class T>
void Arbore<T>::create(T const&)
{
	
}

// operator de inserare cheie in Arbore
template <class T>
void Arbore<T>::operator+(T const& element)
{
	// cream un Arbore nou din elementul primit
	New = new Arbore<int>;
	cout << typeid(New).name() << endl;
	New->data = element;
	
	cout << "valoarea nou introdusa " << New->data << endl;
	
	New->left = NULL;
	New->right = NULL;
	cout << "am creat un nou Arbore din elementul primit" << endl;
	
	// inseram Arborele nou creat in Arborele principal
	insert(root, New);
}

//functie de inserare cheie in Arbore
template <class T>
void Arbore<T>::insert(Arbore<T> *root, Arbore<T> *New)
{
	if(root == NULL)
		root = New;
	else {
		
		// daca valoarea noului element e mai mica decat valoarea radacinii creem un subarbore stang
	    if(New->data < root->data)
	    {
	        if(root->left == NULL) {
	        	root->left = New;
	            cout << "am inserat o frunza stanga" << endl;
	        }
	        else
	            insert(root->left, New);
	    }
	
	    // daca valoarea noului element e mai mare decat valoarea radacinii creem un subarbore drept
	    if(New->data > root->data)
	    {
	        if(root->right == NULL) {
	        	root->right = New;
	            cout << "am inserat o frunza dreapta" << endl;
	        }
	        else
	            insert(root->right, New);
	    }
		
	}
	
	 
}

// operator de stergere cheie din Arbore
template <class T>
void Arbore<T>::operator-(T const& element)
{
	//parcurgem Arborele si localizam cheia
	
	//se disting mai multe cazuri in functie de pozitia cheii in Arbore
	
}

template <class T>
void Arbore<T>::inorder(Arbore<T> *temp)
{
	if(temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

template <class T>
void Arbore<T>::afiseaza()
{
	cout << "aici";
	
	if(root == NULL)
        cout << "arborele nu este creat";
    else
    {
        cout << "\n arborele este: ";
        inorder(root);
    }
}