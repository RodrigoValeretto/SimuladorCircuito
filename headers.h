typedef struct no 	//Struct principal usada em todo o programa
{
	struct no *right;	//Nodo da direita
	struct no *left;	//Nodo da esquerda
	char nome[4];	//Nome do nodo
	int res;	//Resultado contido nele
}Tipo_No;

void buscano(char *,Tipo_No **, Tipo_No **);

void liberamemoria(Tipo_No **);

Tipo_No * criano();

void conectno(Tipo_No **, int);

void recebeentradas(Tipo_No **);

void fazoperacoes(Tipo_No **);

void conectnorecursivo(Tipo_No **);
