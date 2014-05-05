#include <iostream>
#include "Arbore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Arbore<int> arb;
	
	arb.afiseaza();
	
	int v[] = {2, 23, 3, 142, 14, 57};
    for(int i = 0; i < 6; i++)
        arb + (v[i]);
        
    arb.afiseaza();
	
	return 0;
}
