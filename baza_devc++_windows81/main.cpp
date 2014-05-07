#include <iostream>
//#include <string> http://www.cplusplus.com/reference/string/ 

#include "Arbore.h"



//int main(int argc, char** argv)
//deocamdata nu pasam argumente cu argc si argv


int main()
{
//	Arbore<int> arb;
//
//	arb.create();
//
//	int v[] = {2, 23, 3, 142, 14, 57};
//    for(int i = 0; i < 6; i++)
//        arb + (v[i]);
//
//    arb.afiseaza();


    Arbore<char> arb2; // incercam cu char deocamdata fiind tip fundamental
    
    // 
    
    char v[] = {'z', 'c', 't', 'd','r','5','q','b'};  // delimitare cu ' pentru vectori de char
    
    arb2.create(v[0]); //radacina este primul element
    
    for(int i = 1; i < sizeof(v); i++)
        arb2+v[i];
        
    arb2.afiseaza();
    return 0;
}


