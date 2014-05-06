#include <iostream>
#include <string>
#include "Arbore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
//	Arbore<int> arb;
//	
//	arb.create();
//	
//	int v[] = {2, 23, 3, 142, 14, 57};
//    for(int i = 0; i < 6; i++)
//        arb + (v[i]);
//        
//    arb.afiseaza();
    
    Arbore<string> arb2;
    
    arb2.create();
    int v[] = {"a", "c", "b", "d"};
    for(int i = 0; i < 4; i++)
    	arb2 + v[i];
	
	arb2.afiseaza();
	
	return 0;
}
