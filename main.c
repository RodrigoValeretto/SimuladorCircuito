#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
	int conexao = 0;
	int linhas = 0;
	int entradas = 0;
	int i = 0;
	Tipo_No * no;

	no = criano();
	Tipo_No **Raiz = (Tipo_No**)calloc(1,sizeof(Tipo_No*));
	*Raiz = no;

	scanf("%d",&conexao);

	switch(conexao)
	{
		case 0:
            {
            	scanf("%d",&linhas);
		        conectno(Raiz, linhas);
                scanf("%d",&entradas);
                for(i = 0; i < entradas; i++)
                {
                    recebeentradas(Raiz);
                    fazoperacoes(Raiz);
                    printf("%d\n",(*Raiz)->res);
                }

		        break;
            }

		case 1:
			{
				conectnorecursivo(Raiz);
                scanf("%d",&entradas);
                for(i = 0; i < entradas; i++)
                {
                    recebeentradas(Raiz);
                    fazoperacoes(Raiz);
                    printf("%d\n",(*Raiz)->res);
                }
				break;
			}
	}
    return 0;
}
