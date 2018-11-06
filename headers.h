typedef struct no
{
	struct no *right;
	struct no *left;
	char nome[4];
}Tipo_No;

void buscano(char *,Tipo_No **);

Tipo_No * criano();

int conectno(Tipo_No **, int);