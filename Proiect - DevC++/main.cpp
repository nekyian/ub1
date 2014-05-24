#include <iostream>
//#include <vector>
//#include <string> http://www.cplusplus.com/reference/string/
#include "Arbore.h"
using namespace std;


//int main(int argc, char** argv)
//deocamdata nu pasam argumente cu argc si argv


int main()
{


    Arbore<char> arb1,arb2,arb3,arb4,arb5,arb6,arb7,arb8; // incercam cu char deocamdata fiind tip fundamental
    char sters,opt;

    char v1[] = {'d', 'e', 'f', 'a','b','c','7'};  // delimitare cu ' pentru vectori de char
    arb1.create(v1[0]); //radacina este primul element
    for(unsigned i = 1; i < sizeof(v1); i++)
        arb1+v1[i];





//    char v2[]={'a', 'b', 'c', 'w','5'} ;  //arb22 pentru testare operator arbore+arbore
//    arb2.create(v2[0]);                             //initializare radacina arb22
//    for(unsigned int i = 1; i < sizeof(v2); i++)
//		arb2+v2[i];


    char v2[]= {'a', 'b', 'b', 'b','5'} ; //arb22 pentru testare operator arbore+arbore
    arb2.create(v2[0]);                             //initializare radacina arb22
    for(unsigned int i = 1; i < sizeof(v2); i++)
        arb2+v2[i];


    //decomenteaza pt. stergere  Arb2-cheie
//    arb2.afiseaza();
//    cout << "\n doriti sa stergeti un element? y/n \n";
//    cin >> opt;
//    while (opt=='y')
//	{
//
//    	cout << "\n introduceti elementul de sters \n";
//    	cin >> sters;
//    	arb2-sters;
//    	arb2.afiseaza();
//    	cout << "\n doriti sa stergeti un element? y/n \n";
//        cin >> opt;
//
//    	    }
//
//  arb2.afiseaza();
//
    cout<<"\n arb1: ";
    cout<<"\n";
    arb1.afiseaza();
    cout<<"\n arb2: ";
    cout<<"\n";
    arb2.afiseaza();
    cout<<"\n";
    arb3=arb1+arb2;
    cout<<"\n arb3=arb1+arb2 \n";
    cout<<"\n arb3=\n";
    arb3.afiseaza();

    // o cheie 'X' care apare de 5 ori in arbore se va afisa ca X{5}


//test Arbore1=Arbore2

//arb3=arb2;
//cout<<"\n afisare arb3 dupa arb3=arb2: \n";
//arb3.afiseaza();




//testare arb5-arb6
    char v5[] = {'d', 'e', 'f', 'a','b','c','7'};  // delimitare cu ' pentru vectori de char
    arb5.create(v5[0]); //radacina este primul element
    for(unsigned int i = 1; i < sizeof(v5); i++)
        arb5+v5[i];

    char v6[] = {'a', 'b', '7'};  // delimitare cu ' pentru vectori de char
    arb6.create(v6[0]); //radacina este primul element
    for(unsigned int i = 1; i < sizeof(v6); i++)
        arb6+v6[i];


    cout<<"\n arb5: ";
    cout<<"\n";
    arb5.afiseaza();
    cout<<"\n arb6: ";
    cout<<"\n";
    arb6.afiseaza();

    arb4=arb5-arb6;
    cout<<"\n arb4 = arb5-arb6 = ";
    cout<<"\n";
    arb4.afiseaza();

    cout<<"\n arb1= ";
    arb1.afiseaza();

    cout << "\n arb4=arb1 \n";
    arb4=arb1;
    cout<<"\n arb4= ";
    arb4.afiseaza();
    char c='k';
    cout <<"\n "<<c<<" + arb4 = \n";
    c+arb4;
    arb4.afiseaza();
    cout<<"\n";
    c+arb4;
    c+arb4;
    cout << "\n arb4 in care "<<c<<" apare de 3 ori \n";
    arb4.afiseaza();
    arb4-c;
    cout << "\n arb4 in care "<<c<<" apare de 2 ori \n";
    arb4.afiseaza();

    cout<< "\n caut 'a' in arb4: ";
    cout<<arb4.caut(arb4.root,'a');


    Arbore<int> arb9 = 7;
    cout << "\n initializare care cheama constructorul de initializare \n";
    cout <<" \n int arb9 = 7; \n \n arb9 = \n";
    arb9.afiseaza();

//Arbore<int> arb91 = arb9;
//arb91.afiseaza();


    arb7 = 'W';
    cout << "\n initializare care cheama operatorul de asignare  \n";
    cout << "\n char arb7; \n arb7 = 'W'; \n \n arb7 = \n";
    arb7.afiseaza();


//   cout << "\n arb8 = arb4 \n \n arb8 = \n";
//   arb8=arb4; //TODO
//   arb8.afiseaza();



    Arbore<int> arbx, arby;
    int vx[5] = {1, 2, 3, 4, 5};
    arbx.create(vx[0]);
    arby.create(vx[0]);
    for(unsigned int i = 1; i < (sizeof(vx) / sizeof(int)); i++)
    {
        arbx + vx[i];
        arby + vx[i];
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





    return 0;
}



