typedef struct no
{
	struct no *right;
	struct no *left;
	char nome[4];
}Tipo_No;

Tipo_No * buscano(char *,Tipo_No *);

Tipo_No * criano();

int conectno(Tipo_No *,Tipo_No *, int);