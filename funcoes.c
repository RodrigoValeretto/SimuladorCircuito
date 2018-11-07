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

Tipo_No * criano()
{
	Tipo_No * no = (Tipo_No*)calloc(1,sizeof(Tipo_No));
	return no;
}

void conectno(Tipo_No **Raiz, int linhas)
{
	Tipo_No *no = *Raiz;
	Tipo_No **Aux = (Tipo_No**)calloc(1,sizeof(Tipo_No*));
	char * entrada = (char*)calloc(10,sizeof(char));
	char *dado1 = (char*)calloc(1,sizeof(char));
	char *dado2 = (char*)calloc(1,sizeof(char));
	char *dado3 = (char*)calloc(1,sizeof(char));
	int j = 0;
	int i = 0;

	for(i = 0; i<linhas; i++)
	{
	    fflush(stdin);
		fgets(entrada, 40, stdin);
		for(j=0; j<3; j++)
		{
			dado1[j] = entrada[j];
			dado2[j] = entrada[j+4];
			dado3[j] = entrada[j+8];
		}

		dado1[j] = '\n';
		dado2[j] = '\n';
		dado3[j] = '\n';

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
	
}



