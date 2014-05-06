class NodLista
{
	private:

	char *inf;
	NodLista *urm, *ant;

	public:

	friend class Lista;
	friend Lista* Intersectie();
	friend Lista* Diferenta(Lista*);

	NodLista();
	NodLista(char*);

};