typedef struct no
{
	struct no *right;
	struct no *left;
	char nome[4];
	int res;
}Tipo_No;

void buscano(char *,Tipo_No **, Tipo_No **);

void liberamemoria(Tipo_No **);

Tipo_No * criano();

void conectno(Tipo_No **, int);

void recebeentradas(Tipo_No **);

void fazoperacoes(Tipo_No **);

void conectnorecursivo(Tipo_No **);
