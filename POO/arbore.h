#include<iostream>

using namespace std;

template <class T>
class Arbore
{
	private:
		T arbore;
		Arbore<T> *left;
		Arbore<T> *right;
	
	Arbore *root, *New, *temp, *parent;
	
	public:
        Arbore();	// constructor
        int vida();	// helper method returneaza 1 daca arborele e gol
        ~Arbore();	// destructor - elimina nod cu nod pana cand arborele e gol (radacina == NULL)
        
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
    int n;
    while(!vida())
        operator>>(n);
}
