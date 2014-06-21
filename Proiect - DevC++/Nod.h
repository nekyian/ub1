/*************************************************************
       Stativa Dan
       Negrila Cosmin
       
       Proiect POO Tema 8 (arbori binari)
       
       Anul 1 ID

*************************************************************/





template <class T> class node  
		{
			public:
				T data;
				unsigned int contor=1; // o cheie 'X' care apare de 5 ori in arbore se va afisa ca X{5}
				node *right,*left;
				node(){right = NULL; left = NULL;}
				node(const T& d){contor=1;right = NULL; left = NULL; data = d;}
		};
