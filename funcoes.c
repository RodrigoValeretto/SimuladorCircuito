#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void buscano(char *dado,Tipo_No ** Raiz, Tipo_No **Aux)
{
	if(*Raiz == NULL){return;}
	if(!strcmp((*Raiz)->nome,dado)){*Aux = *Raiz; return;}

	buscano(dado, &((*Raiz)->left), Aux);
	buscano(dado, &((*Raiz)->right), Aux);
}

void liberamemoria(Tipo_No **Raiz)
{
	if(*Raiz == NULL){return;}

	liberamemoria(&((*Raiz)->left));
	liberamemoria(&((*Raiz)->right));

	free(*Raiz);
	*Raiz = NULL;
}

Tipo_No * criano()
{
	Tipo_No * no = (Tipo_No*)calloc(1,sizeof(Tipo_No));
	return no;
}

void conectno(Tipo_No **Raiz, int linhas)
{
	Tipo_No *no = *Raiz;
	Tipo_No **Aux = (Tipo_No**)calloc(1,sizeof(Tipo_No*));
	char *dado1 = (char*)calloc(1,sizeof(char));
	char *dado2 = (char*)calloc(1,sizeof(char));
	char *dado3 = (char*)calloc(1,sizeof(char));
	int i = 0;

	for(i = 0; i<linhas; i++)
	{
	    fflush(stdin);
	    scanf("%s", dado1);
	    scanf("%s", dado2);
	    if(dado1[0] != 'N')
	    {scanf("%s", dado3);}

		dado1[3] = '\n';
		dado2[3] = '\n';
		if(dado1[0] != 'N')
		{dado3[3] = '\n';}

		if(i == 0)
		{
			if(dado1[0] == 'N')
			{
				strcpy(no->nome, dado1);
				no->left = criano();
				strcpy(no->left->nome, dado2);
			}else{
				strcpy(no->nome, dado1);
				no->left = criano();
				strcpy(no->left->nome, dado2);
				no->right = criano();
				strcpy(no->right->nome, dado3);
			}
		}else{
			buscano(dado1, Raiz, Aux);
			no = *Aux;
			if(dado1[0] == 'N')
			{
				no->left = criano();
				strcpy(no->left->nome, dado2);
			}else{
				no->left = criano();
				strcpy(no->left->nome, dado2);
				no->right = criano();
				strcpy(no->right->nome, dado3);
			}
		}
	}
	return;
}

void recebeentradas(Tipo_No **Raiz)
{
	if(*Raiz == NULL){return;}
	if((*Raiz)->nome[0] == 'E'){scanf("%d",&((*Raiz)->res)); return;}

	recebeentradas(&((*Raiz)->left));
	recebeentradas(&((*Raiz)->right));
}

void fazoperacoes(Tipo_No **Raiz)
{
    if(*Raiz == NULL){return;}
    if(*Raiz != NULL)
    {
        fazoperacoes(&((*Raiz)->left));
        fazoperacoes(&((*Raiz)->right));

        switch((*Raiz)->nome[0])
        {
            case 'A':(*Raiz)->res = (*Raiz)->left->res & (*Raiz)->right->res; break;

            case 'O':(*Raiz)->res = (*Raiz)->left->res | (*Raiz)->right->res; break;

            case 'D':(*Raiz)->res = !((*Raiz)->left->res & (*Raiz)->right->res); break;

            case 'R':(*Raiz)->res = !((*Raiz)->left->res | (*Raiz)->right->res); break;

            case 'X':(*Raiz)->res = (*Raiz)->left->res ^ (*Raiz)->right->res; break;

            case 'N':(*Raiz)->res = !((*Raiz)->left->res); break;

            case 'E': break;
        }
    }
}

void conectnorecursivo(Tipo_No **Raiz)
{
    char entrada[4];

    scanf("%s",entrada);
	entrada[3] = '\n';


    if(!strcmp(entrada,"\n") || !strcmp(entrada,"\0")){return;}
	if(*Raiz == NULL){*Raiz = criano();}

	strcpy((*Raiz)->nome,entrada);

	if((*Raiz)->nome[0] == 'E'){return;}

	conectnorecursivo(&((*Raiz)->left));
	if((*Raiz)->nome[0] != 'N')
	{conectnorecursivo(&((*Raiz)->right));}

}



