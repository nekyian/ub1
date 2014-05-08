
//#include <iomanip>
//#include <assert.h> 
//
//
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T>


class Arbore
{
//     typedef struct bst
//    {
//        T data;
//        struct bst *left, *right;
//    }node;



class node  
		{
			public:
				T data;
				node *right,*left;
				node(){right = NULL; left = NULL;}
				node(const T& d){right = NULL; left = NULL; data = d;}
		};



        node *root,*New;
		//*New, *temp, *parent;

    public:
        Arbore()
        {
            root = NULL;
        }
        ~Arbore()
		{
            root = NULL;
        }
        //void create();
        void create (T element);
        
        void operator+(T const& element);
        void insert(node *root, node *New);
        
        //////
        T remove(node *&p);
        //T operator -(T const& element);
        T operator -(T);
        void delnode(node*&,T);
        /////
        
        

        void afiseaza();
        void inorder(node *temp);
        void postorder(node *temp);

};

template <class T>
//void Arbore<T>::create()
//void Arbore<T>::create(T const& element)
void Arbore<T>::create(T element)

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
    else insert(root, New);
}

// operator de inserare cheie in Arbore
template <class T>
void Arbore<T>::operator+(T const& element)
{
    // cream un Nod nou din elementul primit

    
//    New = new bst;
    New = new node;
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
void Arbore<T>::afiseaza() //deocamdata doar inordine()
// TO DO: afisare gen ((a)(c)(e)) etc
{
    if(root == NULL)
        cout << "arborele nu este creat";
    else
    {
    	cout << "\n";
    	inorder(root);
    	cout << "\n";
//        cout << "\n alegeti tipul de parcurgere dorit:\n\n 1.inordine\n2.postordine\n";
//        int tip;
//        cin >> tip;
//        cout << "\n arborele este: " << " ";
//        switch(tip)
//        {
//        case 1:
//            inorder(root);
//            break;
//        case 2:
//            postorder(root);
//            break;
//        }
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






 template <class T> void Arbore<T>::delnode(node*& root,T element)
{
	// to do: seg fault dupa stergerea radacinii si afisarea finala, probabil trebuie verificat/initializat 
	// ceva cu NULL inainte/dupa delete;
	// + comentat aici.
    node *tmp;
    if (!root) cout<<"\n nodul nu exista \n";
    else if (element<root->data) delnode(root->left,element);
    else if (element>root->data) delnode(root->right,element);
    else
    {
        tmp=root;
        if (!tmp->left)
        {
            root=tmp->right;
            delete(tmp);
        }
        else if(!tmp->right)
        {
            root=tmp->left;
            delete(tmp);
        }
        else
            root->data=remove(root->left);
    }
}
template <class T> T Arbore<T>::remove(node *&p)
// completare la delnode pt cazul III cand un nod are doi copii

{
    if (p->right)
        return remove(p->right);
    else
    {
        node *q=p;
        T element=q->data;
        p=p->right;
        delete(q);
        return element;
    }
}




template <class T> T Arbore<T>::operator-(T element) //(Arbore - element)  
//to do: parametrul

                                             
{
	
    node *nou;
    nou=root;
    delnode(nou,element);

}



// to do (Cosmin)

//Arbore1 + Arbore2 scoase elementele in inordine din 2 si introduse in 1 conform cerintei (probabil cu un v[])

//Arbore1 - Arbore2 la fel
//Arbore1 = Arbore2  recursiv + o functie suplimentara

//+ & -


// to do (Dan)

//==; <, <=, >, >= (operatorii de ordine întorc 1 (sau 0) conform ordonarii
//lexicografice a sirurilor ordonate care rezulta prin parcurgerea în inordine a
//operanzilor, cu repetarea fiecarei chei conform contorului);









