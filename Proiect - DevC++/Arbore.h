#include <iostream>
#include "Nod.h"


using namespace std;



template <class T>
class Arbore
{



    public:
    	node<T> *root,*New;    //was node *root,*New;
    	
        Arbore()
        {
        	
            root = NULL;
            size=0;
            
        }


//    TODO constructor de copiere arbore1=arbore2
//         constructor de initializare, sa aiba sens initializarea directa
//     Arbore<int> = 5;
     
//     Arbore<T>  (Arbore<T> const & arb) 
//     {
//     
//
//	 
//	 }
     
         
        Arbore<T> & operator= (T const& element);  
	    //asignare
		//sa aiba sens 
		//Arbore<char> Arbore1;
		//Arbore1 = 'a';
		        
        
 		 
		//Arbore<T>& operator= (const Arbore<T>& arbore1); //const           
        
        Arbore <T> operator+ (Arbore<T> arbore1);
        Arbore <T> operator- (Arbore<T> arbore1);
        
    	void create (T element);
        void insert(node<T> *root, node<T> *New);
        
        
        void operator+(T const& element);
        T operator -(T);
        friend void operator+ (T element,Arbore<T> &arbore1)
       {

	  arbore1+element;
 
	   }
		
		T remove(node<T> *&p);
        
        void delnode(node<T>*&,T);
        void afiseaza();
        
        void inorderM(node<T> *temp,int &size,T *inord);
        void preorderM(node<T> *temp,int &size,T *preord);
        
        void inorder(node<T> *temp);
        void postorder(node<T> *temp);
        
        
        int size; //nr de noduri - folosit de inordineM/preordineM
        T inord[];  // vector ce contine pargurgerea in inordine
        T preord[]; // vector ce contine pargurgerea in preordine
        
        bool operator==(Arbore<T> arbore2);
        
       
	   
	   

};



template <class T>
//void Arbore<T>::create()
//void Arbore<T>::create(T const& element)
void Arbore<T>::create(T element)

//modificata (deocamdata) pentru testare sa preia direct v[0] ca radacina. in varianta finala vom citi pe rand
//radacina si elementele. 

{
    New = new node<T>;
    New->left = NULL;
    New->right = NULL;
    
    //cout << "\n introduceti primul element al arborelui: \n";
    //cin >> New->data;
    
    New->data = element;
    
    if(root == NULL)
    {
        root = New;
        //cout << " \n am creeat radacina arborelui, cu valoare " << New->data << endl;
        
    }
    else insert(root, New);
}

// operator de inserare cheie in Arbore
template <class T>
void Arbore<T>::operator+(T const& element)
{
    // cream un Nod nou din elementul primit

    New = new node<T>;
    New->data = element;
    New->left = NULL;
    New->right = NULL;
    //cout << " \n Am creeat un nod nou:\ndata: " << element << endl;
    // inseram Nodul nou creat in Arborele principal
    insert(root, New);
    
    

}

template <class T>
void Arbore<T>::insert(node<T> *root, node<T> *New)
{
    // daca valoarea noului element e mai mica decat valoarea radacinii creem un subarbore stang
    if(New->data < root->data)
    {
        if(root->left == NULL)
        {
            root->left = New;
            //cout << " \n am introdus nodul nou = copil stang al lui " <<" "<<root->data<<"\n"; 
			//afiseaza explicit unde il introduce
        }
        else
        {
            //cout << " ne deplasam in jos stanga \n" << endl;
            insert(root->left, New);
        }
    }
    // daca valoarea noului element e mai mare decat valoarea radacinii creem un subarbore drept
    if((New->data > root->data)||(New->data >= root->data))//
    {
        if(root->right == NULL)
        {
            root->right = New;
            //cout << " \n am introdus nodul nou = copil drept al lui " <<" "<<root->data <<"\n";
            //afiseaza explicit unde il introduce
        }
        else
        {
            //cout << "ne deplasam in jos dreapta  \n" << endl;
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
    	//cout<<"afisare(): ";
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
void Arbore<T>::inorder(node<T> *temp)
{
	if(temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}



template <class T>
void Arbore<T>::inorderM(node<T> *root,int &size,T *inord) //inordine iterativa pentru facilitarea inserarii elementelor in inord[] 

{
	
	size=0;
	inord[size]={}; 

// //debug garbage
//	cout<<"\n";
//	cout<<"size inainte inordineM este: "<<size<<"\n";
//	cout <<"\n inord inainte de inordineM este: "<<"\n";
//	for (int i=0; i<=size; i++) cout <<inord[i];
//	cout<<"\n";
    node<T>* current,*pre;
    current=root;
    while(current!=NULL) {
        if(current->left==NULL) {
            //cout<<current->data;
            size++;                          //incrementare si asignare inord[]
            inord[size]=current->data;        //
            current=current->right;
        }
        else {
            pre=current->left;
            while(pre->right != NULL && pre->right !=current)
                pre=pre->right;
            if(pre->right==NULL) {
                pre->right=current;
                current=current->left;
            }
            else {
                pre->right=NULL;
                //cout<<current->data;
                size++;                        //incrementare si asignare inord[]
                inord[size]=current->data;      //
                current=current->right;
            }
        }
    }
// //debug garbage
//    cout<<"\n";
//	cout<<"size dupa inordineM este: "<<size<<"\n";
//	cout <<"\n inord dupa de inordineM este: "<<"\n";
//	for (int i=0; i<=size; i++) cout <<inord[i];
//	cout <<"\n";
}



template <class T>
void Arbore<T>::preorderM(node<T> *root,int &size,T *preord)  //TODO cu parametri locali!
{
    
    size=0;
	inord[size]={};
	node<T>* tmp, *current;
	tmp = root;

    while (tmp)
    {
        
        if (tmp->left == NULL)
        {
        	size++;
        	preord[size]=tmp->data;
            //cout << tmp->data;
            tmp = tmp->right;
        }
        else
        {
            
            current = tmp->left;
            while (current->right && current->right != tmp)
                current = current->right;

            
            if (current->right == tmp)
            {
                current->right = NULL;
                tmp = tmp->right;
            }

            
            else
            {
            	size++;
        		preord[size]=tmp->data;
                //cout << tmp->data;
                current->right = tmp;
                tmp = tmp->left;
            }
        }
    }
    for (int i=1; i<=size; i++) cout <<preord[i];
}








template <class T>
void Arbore<T>::postorder(node<T> *temp)
{
    if(temp != NULL)
    {
        postorder(temp->right);
        cout << " " << temp->data;
        postorder(temp->left);
    }
}



 template <class T> void Arbore<T>::delnode(node<T>*& root,T element)
{
	
	// fixed lipsea 'new' pentru delete-ul din remove()
	// TO DO segfault la ultimul element,cand stergem ultimul element
    node<T> *tmp;
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
template <class T> T Arbore<T>::remove(node<T> *&p)
// completare la delnode pt cazul III cand un nod are doi copii

{
    if (p->right)
        return remove(p->right);
    else
    {
        node<T> *q = p ;	
        T element=q->data;
        p=p->right;
        delete(q);
        return element; 
    }
}




template <class T> T Arbore<T>::operator-(T element) //(Arbore - element)  
//to do: parametrul

                                             
{
	
    node<T> *nou;
    nou=root;
    delnode(nou,element);
    return 0;
}





template <class T>
Arbore<T> Arbore<T>::  operator- (Arbore<T> arbore1) 
{

inorderM(arbore1.root,arbore1.size,arbore1.inord);          // dupa inorderM(...) 
													         //arbore1.inord[] contine parcurgerea in inordine	
for (int i=1;i<=arbore1.size;i++) *this-arbore1.inord[i];    //arbore1.size=nr de noduri
return *this;

}

template <class T>
Arbore<T> Arbore<T>::  operator+ (Arbore<T> arbore1) 
{

inorderM(arbore1.root,arbore1.size,arbore1.inord);
for (int i=0;i<=arbore1.size;i++) *this+arbore1.inord[i];
return *this;

}


//template <class T>
//Arbore<T>& Arbore<T>:: operator= (const Arbore<T>& arbore1)
//{
//		Arbore<T> arboretemp;
//			
//		preorderM(arbore1.root,arbore1.size,arbore1.preord);
//		arbore1.root-left=NULL;
//		
//	
//}


template <class T>
Arbore<T>& Arbore<T>::  operator=(T const& element)
{
        	
    New = new node<T>;
    New->left = NULL;
    New->right = NULL;
    New->data = element;
    root = New;
    return *this;
        	
}






template <class T>
bool Arbore<T>::operator==(Arbore<T> arbore2)
{
    //parcugem cei 2 arbori si incarcam lista inord pentru fiecare
    inorderM(this->root,this->size,this->inord);
    inorderM(arbore2.root,arbore2.size,arbore2.inord);

    //in primul rand verificam daca arborii au aceeasi dimensiune
    cout << this->size << "==" << arbore2.size << endl;
    if(this->size != arbore2.size)
        return false;

    for(int i; i < this->size; i++)
        if(this->inord[i] != arbore2.inord[i])
            return false;

    return true;
}







//template <class T>
//Arbore<T> Arbore<T>::  operator= (Arbore<T> arbore1) 
//{
//
//
//}



//
//TODO (Cosmin)
//Arbore1 - element TO DO: segfault (acum la cazul cand se incearca eliminarea ultimului element);
//inserare/stergere cu contor 



//arbore1=arbore2 (constructor de copiere) 
//constructor de initializare (directa): Arbore<int> = 5; 
//
//





//Arbore1 = Arbore2 TODO constructor de copiere;

//
//TODO (Dan) (editeaza aici)
//
//==; <, <=, >, >= (operatorii de ordine întorc 1 (sau 0) conform ordonarii
//lexicografice a sirurilor ordonate care rezulta prin parcurgerea în inordine a
//operanzilor, cu repetarea fiecarei chei conform contorului);
//







