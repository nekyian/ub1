class NodLista;

class Lista
{
	private:

	NodLista *first, *last;

	public:

	Lista();
	Lista (Lista&);
	~Lista();
	
	void Introducere(char*);
	void Afisare();
	void Reuniune(Lista);
	int  Cautare(char*);
	void operator= (Lista*);
	

	friend Lista* Intersectie();
	friend Lista* Diferenta(Lista*);
};

