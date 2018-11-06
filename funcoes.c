#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void buscano(char *entrada,Tipo_No ** Raiz)
{
	if(*Raiz == NULL){return;}
	if(!strcmp((*Raiz)->nome,entrada)){return;}

	buscano(entrada, &((*Raiz)->left));
	buscano(entrada, &((*Raiz)->right));
}

Tipo_No * criano()
{
	Tipo_No * no = (Tipo_No*)calloc(1,sizeof(Tipo_No));
	return no;
}

int conectno(Tipo_No **Raiz, int linhas)
{
	Tipo_No *no = *Raiz;
	char * entrada = (char*)calloc(10,sizeof(char));
	char dado1[4];
	char dado2[4];
	char dado3[4];

	for(int i = 0; i<linhas; i++)
	{
		int j = 0;
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
			buscano(dado1, Raiz);
			no = *Raiz;
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
	return 0;
}
