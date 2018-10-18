#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

Tipo_No * buscano(char *entrada,Tipo_No * no)
{
	if(no == NULL){return NULL;}
	if(!strcmp(no->nome,entrada)){return no;}

	buscano(entrada, no->left);
	buscano(entrada, no->right);
}

Tipo_No * criano()
{
	Tipo_No * no = (Tipo_No*)calloc(1,sizeof(Tipo_No));
	return no;
}

int conectno(Tipo_No * no, Tipo_No * Raiz, int linhas)
{
	Tipo_No *Aux;

	char * entrada = (char*)calloc(1,sizeof(char));
	if(no == Raiz)
	{
		Aux = no;
		no->left = criano();
		no->right = criano();
		for(int j = 0; j<3; j++)
		{
			scanf("%s", entrada);
			strcpy(no->nome,entrada);
			no = Aux;
			if(j == 0){no = no->left;}
			if(j == 1){no = no->right;}
		}
	}

	for(int i = 1; i < linhas; i++)
	{
		scanf("%s",entrada);
	}

	return 0;
}
