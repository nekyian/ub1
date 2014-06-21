/*************************************************************
       Stativa Dan
       Negrila Cosmin
       
       Proiect POO Tema 8 (arbori binari)
       
       Anul 1 ID

*************************************************************/







#include "Arbore.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;



int main()


{	
	int n=0,k,n2;
	char r,c;
	Arbore<char> arb1,arb2,arb3,arb4,arb5,arb6,arb8,arb9;
	srand (time(NULL));
	
	cout <<" \n dati nr de elemente al arborelui arb1: ";
	cin >> n;
	cout <<" \n dati radacina arborelui arb1: ";
	cin >> r;
	arb1.create(r);
	
	for (int i=1; i<=n-1; i++) 
	{
		cout << "\n introduceti elementul "<<i<<": ";
		cin >> r;	
		arb1+r;
	}
	cout << "arborele arb1 este:\n";
	arb1.afiseaza();
	cout <<"\n";
	
	
	
	k= rand()%3;	
	if (k % 3 == 0) r= rand()%25+97;
	else if (k % 3 == 1 ) r= rand()%25+65;
	else if (k % 3 == 2) r= rand()%9+48;
	arb2.create(r);
	
	for (int i=1; i<=n-2; i++) 
	{
		k= rand()%3;
		if (k % 3 == 0) r= rand()%25+97;
		else if (k % 3 == 1 ) r= rand()%25+65;
		else if (k % 3 == 2) r= rand()%9+48;
		arb2+r;
	}
	cout << "arborele arb2 generat aleator este: \n";
	arb2.afiseaza();
	cout << "\n";
	
	cout<<"arborele arb3 este egal cu suma arb1+arb2:\n";
	arb3=arb1+arb2; 
	arb3.afiseaza();
	cout << "\n";
	

    char v5[] = {'d', 'e', 'f', 'a','b','c','7','B','A'}; 
    arb5.create(v5[0]); //radacina este primul element
    for(unsigned int i = 1; i < sizeof(v5); i++)
        arb5+v5[i];     //apeleaza metoda corespunzatoare pentru ARBORE+ELEMENT

    char v6[] = {'e','a', 'b', '7'};  
    arb6.create(v6[0]); //radacina este primul element
    for(unsigned int i = 1; i < sizeof(v6); i++)
        v6[i]+arb6;     //apeleaza metoda corespunzatoare pentru ELEMENT+ARBORE


    cout<<"\n arborele arb5 este: ";
    cout<<"\n";
    arb5.afiseaza();
    cout<<"\n arborele arb6 este: ";
    cout<<"\n";
    arb6.afiseaza();
	arb4=arb5-arb6;
    cout<<"\n arborele arb4 = arb5-arb6 este: ";
    cout<<"\n";
    arb4.afiseaza();
	cout << "\n introduceti caracterul de sters din arb4: ";
	
	cin>>c;
	arb4 - c; //apeleaza metoda corespunzatoare pentru ARBORE-ELEMENT
	cout << "\n";
	cout<<"\n arborele arb4 = arb4-"<<c<<" este: \n";
	arb4.afiseaza();
	
	
	Arbore<int> arb7 = 7;
	cout << "\n initializare care cheama constructorul de initializare \n";
	cout <<" \n int arb7 = 7; \n \n arborele arb7 este: \n";
	arb7.afiseaza();
	

    arb8 = 'W';
    cout << "\n initializare care cheama operatorul de asignare  \n";
    cout << "\n char arb8; \n";
	cout<<" \n arb8 = 'W'; \n \n arborele arb8 este: \n";
    arb8.afiseaza();



arb9 = arb8;  //cheama operatorul supraincarcat de asignare intre doi arbori A=B
cout << "\n arborele arb9 = arb8  \n";
cout << "\n arborele arb9 este:  \n";
arb9.afiseaza();

	
//supraincarcare operatori relationali



    Arbore<int> arbx, arby,arbx1,arby1,arbx2,arby2;
    int vx[5] = {1, 2, 3, 4, 5};
    
    arbx.create(vx[0]);
    arby.create(vx[0]);
    arbx1.create(vx[0]);
    arby1.create(vx[0]);
    arbx2.create(vx[0]);
    arby2.create(vx[0]);
    for(unsigned int i = 1; i < (sizeof(vx) / sizeof(int)); i++)
    {
        arbx + vx[i];
        arby + vx[i];
        arbx1 + vx[i];
        arby1 + vx[i];
        arbx2 + vx[i];
        arby2 + vx[i];
    }
    arbx + 6;

    cout << "_______________________" << endl;
    cout << "arb1: ";
    arbx.afiseaza();
    //cout << "------------------" << endl;
    cout << "arb2: ";
    arby.afiseaza();
    //cout << "------------------" << endl;
    cout << (arbx==arby) << endl;

    cout << "_______________________" << endl;
    
//   arbx1+6;
//   arbx1-5;
//
//    cout << "_______________________" << endl;
//    cout << "arb1: ";
//    arbx1.afiseaza();
//    //cout << "------------------" << endl;
//    cout << "arb2: ";
//    arby1.afiseaza();
//    //cout << "------------------" << endl;
//    cout << (arbx>arby) << endl;
//
//    cout << "_______________________" << endl;
//    
//    arby2 + 6;
//    arby2-5;
//
//    cout << "_______________________" << endl;
//    cout << "arb1: ";
//    arbx2.afiseaza();
//    //cout << "------------------" << endl;
//    cout << "arb2: ";
//    arby2.afiseaza();
//    //cout << "------------------" << endl;
//    cout << (arbx<arby) << endl;
//
//    cout << "_______________________" << endl;



    return 0;
}


