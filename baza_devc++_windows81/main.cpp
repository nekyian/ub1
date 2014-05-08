#include <iostream>
//#include <string> http://www.cplusplus.com/reference/string/
#include "Arbore.h"

//int main(int argc, char** argv)
//deocamdata nu pasam argumente cu argc si argv


int main()
{


    Arbore<char> arb2; // incercam cu char deocamdata fiind tip fundamental
	char sters,opt;
	
    char v[] = {'z', 'c', 't', 'd','r','5','q','b'};  // delimitare cu ' pentru vectori de char
    arb2.create(v[0]); //radacina este primul element
    for(int i = 1; i < sizeof(v); i++) 
		arb2+v[i];
		
    arb2.afiseaza();
    cout << "\n doriti sa stergeti un element? y/n \n";
    cin >> opt;
    if (opt=='y') 
	{
    	cout << "\n introduceti elementul de sters \n";
    	cin >> sters;
    	arb2-sters;
    	    }
    
    arb2.afiseaza();
    
    return 0;
}



