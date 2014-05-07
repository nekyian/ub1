#include <iostream>
#include <string>
#include "Arbore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n;
Arbore<int>* arbori;

int main(int argc, char** argv) 
{
	
	cout << "Cati arbori doriti sa creati?\n";
	cin >> n;
	
	arbori = new Arbore<int>[n];
	
	int m, temp;
	
	for(int i = 0; i < n; i++) {
		
		cout<<"Arborele nr. "<<i+1<<":"<<std::endl;
		cout<<"Nr elemente: ";
		std::cin>>m;
		
		for(int j = 0; j < m; j++) {
			cout<<"Elementul "<<j+1<<": ";
			cin>>temp;
			arbori[i] + temp;
		}
		
		cout<<"Arborele: ";
		arbori[i].afiseaza();
		cout<<endl;
	}
	
	
	
//	Arbore<int> arb;
//	
//	arb.create();
//	
//	int v[] = {2, 23, 3, 142, 14, 57};
//    for(int i = 0; i < 6; i++)
//        arb + (v[i]);
//        
//    arb.afiseaza();
    
//    Arbore<string> arb2;
//    
//    arb2.create();
//
//	arb2 + "mumu0";
//	arb2 + "mumu2";
//	arb2 + "mumu3";
//	arb2 + "mumu1";

//    int v[] = {"a", "c", "b", "d"};
//    for(int i = 0; i < 4; i++)
//    	arb2 + v[i];
	
//	arb2.afiseaza();
	
	return 0;
}
