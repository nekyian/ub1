#include <iostream>
//#include <string> http://www.cplusplus.com/reference/string/
#include "Arbore.h"

//int main(int argc, char** argv)
//deocamdata nu pasam argumente cu argc si argv


int main()
{


    Arbore<char> arb1,arb2,arb3,arb4,arb5,arb6,arb7; // incercam cu char deocamdata fiind tip fundamental
	char sters,opt;
	
	char v1[] = {'d', 'e', 'f', 'a','b','c','7'};  // delimitare cu ' pentru vectori de char
    arb1.create(v1[0]); //radacina este primul element
    for(int i = 1; i < sizeof(v1); i++) 
		arb1+v1[i];
		
		
	   
    
    
    char v2[]={'a', 'b', 'c', 'w','5'} ;  //arb22 pentru testare operator arbore+arbore
    arb2.create(v2[0]);                             //initializare radacina arb22
    for(int i = 1; i < sizeof(v2); i++) 
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
   cout<<"\n arb1+arb2 = ";
   cout<<"\n";
   arb3=arb1+arb2;
   arb3.afiseaza();



 //testare arb5-arb6    
    char v5[] = {'d', 'e', 'f', 'a','b','c','7'};  // delimitare cu ' pentru vectori de char
    arb5.create(v5[0]); //radacina este primul element
    for(int i = 1; i < sizeof(v5); i++) 
		arb5+v5[i];
			
		char v6[] = {'a', 'b', '7'};  // delimitare cu ' pentru vectori de char
    arb6.create(v6[0]); //radacina este primul element
    for(int i = 1; i < sizeof(v6); i++) 
    
    
		arb6+v6[i];  
cout<<"\n arb5: ";
cout<<"\n";
   arb5.afiseaza();
cout<<"\n arb6: ";
cout<<"\n";
   arb6.afiseaza(); 
    
   arb4=arb5-arb6; 
cout<<"\n arb5-arb6 = ";  
cout<<"\n";
   arb4.afiseaza();
   
   
    
    
    return 0;
}


