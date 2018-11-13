#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void buscano(char *dado,Tipo_No ** Raiz, Tipo_No **Aux)	//Função responsável por buscar um nó a partir de um dado
{
	if(*Raiz == NULL){return;}	//Retorna se a raiz for NULL
	if(!strcmp((*Raiz)->nome,dado)){*Aux = *Raiz; return;}	//Compara se o conteudo presente no nodo é igual ao dado desejado e, caso simc atribui esse a um ponteiro auxiliar, depois retorna

	buscano(dado, &((*Raiz)->left), Aux);	//Chama a recursão da função para a esquerda
	buscano(dado, &((*Raiz)->right), Aux);	//Chama a recursão da função para a direita
}

void liberamemoria(Tipo_No **Raiz)	//Função responsável por liberar a memória alocada em todo o programa
{
	if(*Raiz == NULL){return;}	//Retorna caso a raiz aponte para NULL

	liberamemoria(&((*Raiz)->left));	//Chama a recursão da função para a esquerda
	liberamemoria(&((*Raiz)->right));	//Chama a recursão da função para a direita

	free(*Raiz);	//Libera o nodo apontado
	*Raiz = NULL;	//Atribui NULL para a posição liberada
}

Tipo_No * criano()	//Função responsável por alocar memoria para um nodo
{
	Tipo_No * no = (Tipo_No*)calloc(1,sizeof(Tipo_No));	//Calloc que aloca memoria para o nodo e atribui a ele
	return no;	//Retorna o nodo alocado
}

void conectno(Tipo_No **Raiz, int linhas)	//Função que monta o sistema do modo 0 (Não recursivo)
{
	Tipo_No *no = *Raiz;	//Declaração de variáveis
	Tipo_No **Aux = (Tipo_No**)calloc(1,sizeof(Tipo_No*));
	char *dado1 = (char*)calloc(1,sizeof(char));
	char *dado2 = (char*)calloc(1,sizeof(char));
	char *dado3 = (char*)calloc(1,sizeof(char));
	int i = 0;

	for(i = 0; i<linhas; i++)	//Laço que roda o numero de linhas inserido pelo usuario
	{
	    fflush(stdin);	//Limpa o buffer do teclado
	    scanf("%s", dado1);	//Recebe o primeiro dado
	    scanf("%s", dado2);	//Recebe o segundo dado
	    if(dado1[0] != 'N')	//Caso o primeiro dado seja diferente de 'N'
	    {scanf("%s", dado3);}//Recebe o terceiro dado

		dado1[3] = '\n';	//Atribui '\n' ao final dos dados recebidos
		dado2[3] = '\n';	
		if(dado1[0] != 'N')	//Verifica se o dado 1 é diferente de 'N'
		{dado3[3] = '\n';}

		if(i == 0)	//Caso especifico para quando é o começo do sistema
		{
			if(dado1[0] == 'N')	//Verifica se dado1 tem 'N'
			{
				strcpy(no->nome, dado1);	//Se sim, copia o dado1 para o nome do nodo apontado
				no->left = criano();	//Aloca memoria para o nodo da esquerda
				strcpy(no->left->nome, dado2);	//Copia o conteudo do dado2 para o nodo da esquerda
			}else{	//Caso dado1 não tenha 'N'
				strcpy(no->nome, dado1);	//Copia o dado1 para o nome do nodo apontado
				no->left = criano();	//Aloca memoria para o nodo da esquerda
				strcpy(no->left->nome, dado2);	//Copia o dado2 para o nodo da esquerda
				no->right = criano();	//Aloca memoria para o nodo da direita
				strcpy(no->right->nome, dado3);	//Copia o dado3 para o nodo da direita
			}
		}else{	//Caso não seja o começo do sistema
			buscano(dado1, Raiz, Aux);	//Chama a função que busca um nodo inserido pelo usuario (dado1)
			no = *Aux;	//Atribui esse nodo encontrado a variavel no
			if(dado1[0] == 'N')//Verifica se dado1 tem 'N' 
			{
				no->left = criano();	//Se sim, aloca memoria para o nodo da esquerda
				strcpy(no->left->nome, dado2);	//E copia o conteudo de dado2 para o nome do nodo da esquerda
			}else{	//Se dado1 não tem 'N'
				no->left = criano();	//Aloca memoria para o nodo da esquerda
				strcpy(no->left->nome, dado2);	//Copia o conteudo de dado2	para o nodo da esquerda
				no->right = criano();	//Aloca memoria para o nodo da direita
				strcpy(no->right->nome, dado3);	//Copia o conteudo de dado3 para o nodo da direita
			}
		}
	}
	return;	//Finaliza a função
}

void recebeentradas(Tipo_No **Raiz)	//Função responsável por receber entradas
{
	if(*Raiz == NULL){return;}	//Verifica se o conteudo da raiz aponta pra NULL e retorna caso sim
	if((*Raiz)->nome[0] == 'E'){scanf("%d",&((*Raiz)->res)); return;}	//Verifica se o nome da raiz tem 'E', e caso sim, recebe uma entrada e coloca no 'res' do nodo, depois retorna

	recebeentradas(&((*Raiz)->left));	//Chama a recursão para a esquerda
	recebeentradas(&((*Raiz)->right));	//Chama a recursão para a direita
}

void fazoperacoes(Tipo_No **Raiz)	//Função responsável por realizar as operações do sistema
{
    if(*Raiz == NULL){return;}	//Verifica se o conteudo da raiz aponta pra NULL e se sim, retorna
    if(*Raiz != NULL)	//Caso a raiz seja diferente de NULL
    {
        fazoperacoes(&((*Raiz)->left));	//Chama a recursão para a esquerda
        fazoperacoes(&((*Raiz)->right));//Chama a recursão para a direita

        switch((*Raiz)->nome[0])	//Switch responsável por verificar qual operação vai ser realizada
        {
            case 'A':(*Raiz)->res = (*Raiz)->left->res & (*Raiz)->right->res; break;	//Caso A realiza um And entre os nodos e atribui para o nodo pai o resultado

            case 'O':(*Raiz)->res = (*Raiz)->left->res | (*Raiz)->right->res; break;	//Caso O realiza um Or entre os nodos e atribui para o nodo pai o resultado

            case 'D':(*Raiz)->res = !((*Raiz)->left->res & (*Raiz)->right->res); break;	//Caso D realiza um NAnd entre os nodos e atribui o resultado para o nodo pai

            case 'R':(*Raiz)->res = !((*Raiz)->left->res | (*Raiz)->right->res); break;	//Caso R realiza um NOr entre os nodos e atribui o resultado para o nodo pai

            case 'X':(*Raiz)->res = (*Raiz)->left->res ^ (*Raiz)->right->res; break;	//Caso X realiza um Xor entre os nodos e atribui o resultado para o nodo pai

            case 'N':(*Raiz)->res = !((*Raiz)->left->res); break;	//Caso N realiza um Not no nodo seguinte e atribui o resultado para o nodo pai

            case 'E': break;	//Caso E retorna
        }
    }
}

void conectnorecursivo(Tipo_No **Raiz)	//Função que realiza a montagem do sistema pelo modo 1(Recursivo)
{
    char entrada[4];	//Declaração de variaveis

    scanf("%s",entrada);	//Recebe uma entrada correspondente ao nome do nodo
	entrada[3] = '\n';	//Atribui '\n' ao fim dela


    if(!strcmp(entrada,"\n") || !strcmp(entrada,"\0")){return;}	//Verifica se a entrada é '\n' ou '\0' e retorna caso ela for
	if(*Raiz == NULL){*Raiz = criano();}	//Verifica se o conteudo da raiz aponta pra NULL e caso sim, ele aloca um nodo para esse

	strcpy((*Raiz)->nome,entrada);	//Copia a entrada digitada para o nome do nodo apontado

	if((*Raiz)->nome[0] == 'E'){return;}	//Verifica se o nome do conteudo da raiz tem 'E', se sim, retorna

	conectnorecursivo(&((*Raiz)->left));	//Chama a recursão para a esquerda
	if((*Raiz)->nome[0] != 'N')	//Verifica se o nome do nodo apontado pela raiz é diferente de 'N'
	{conectnorecursivo(&((*Raiz)->right));}	//Se sim, chama a recursão para a direita

}



