#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
	int conexao = 0;
	int linhas;
	Tipo_No * no;

	no = criano();
	Tipo_No **Raiz = (Tipo_No**)calloc(1,sizeof(Tipo_No*));
	*Raiz = no;
	
	scanf("%d",&conexao);
	scanf("%d",&linhas);

	switch(conexao)
	{
		case 0: conectno(Raiz, linhas); break;

		case 1: break;
	}
	return 0;
}