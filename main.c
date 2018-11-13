#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()	//Função principal em que o programa é executado
{
	int conexao = 0;	//Declaração de variáveis
	int linhas = 0;
	int entradas = 0;
	int i = 0;
	Tipo_No * no;

	no = criano();	//Aloca memória para um no da árvore
	Tipo_No **Raiz = (Tipo_No**)calloc(1,sizeof(Tipo_No*));	//Cria um ponteiro de ponteiro para a struct e aloca memoria pra esse
	*Raiz = no;	//Atribui o no alocado anteriormente ao ponteiro de ponteiro

	scanf("%d",&conexao);	//Recebe como entrada o tipo de conexão à ser utilizado no programa

	switch(conexao)	//Função que roda de acordo com o escolhido
	{
		case 0:	//Caso o usuario escolha o tipo 0
            {
            	scanf("%d",&linhas);	//Recebe o numero de linhas que vai ter a descrição do circuito
		        conectno(Raiz, linhas);	//Chama a função que monta o circuito do modo 0
                scanf("%d",&entradas);	//Recebe o numero de entradas a serem colocadas
                for(i = 0; i < entradas; i++)	//Laço que roda o numero de entradas inserido
                {
                    recebeentradas(Raiz);	//Função para receber as entradas
                    fazoperacoes(Raiz);	//Função que calcula o resultado retornado do sistema
                    printf("%d\n",(*Raiz)->res);	//Print do resultado para o usuário
                }

		        break;	//Finaliza o caso 0
            }

		case 1: //Caso o usuario escolha o tipo 1
			{
				conectnorecursivo(Raiz);	//Função que monta o circuito do modo 1 (Recursivo)
                scanf("%d",&entradas);	//Recebe o numero de entradas a serem inseridas
                for(i = 0; i < entradas; i++)	//Laço que roda o numero de entradas inserido
                {
                    recebeentradas(Raiz);	//Função que recebe as entradas
                    fazoperacoes(Raiz);	//Função que calcula o resultado retornado do sistema
                    printf("%d\n",(*Raiz)->res);	//Print do resultado para o usuário
                }
				break;	//Finaliza o caso 1
			}
	}
	liberamemoria(Raiz);	//Função que libera a memória alocada previamente para os nodos
	free(Raiz);	//Libera o ponteiro de ponteiro usado no programa

    return 0;	//Fim do programa
}
