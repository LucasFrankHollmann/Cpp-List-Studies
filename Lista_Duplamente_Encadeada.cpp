//Autor: Lucas Frank Hollmann

#include <stdio.h> //Biblioteca para usar printf.
#include <stdlib.h> //Biblioteca para usar malloc.

struct node //Estrutura nó, que representa cada elemento da lista.
{
	
	int valor; //Valor armazenado na lista.
	struct node *prox, *prev; //Ponteiros para o próximo nó e o nó anterior.
	
};typedef struct node node;

class ListDE
{
	private:
		
		node *raiz; //Nó inicial da lista.
		node *last; //Nó final da lista.
		int size; //Tamanho da lista.
		
	public:
		
		/* Construtor da classe ListDE, define valores iniciais para a raiz, last e o tamanho.
		 */ 
		ListDE()
		{
			raiz = NULL;
			last = NULL;
			size = 0;
		}
		
		/* Função para exibir todos os elementos da lista.
		 */
		void printList()
		{
			
			if(raiz == NULL) //Se a raiz for nula, a lista está vazia, informa isso e finaliza a função.
			{
				printf("Lista vazia\n");
				return;
			}
			
			node *aux = raiz; //Nó auxiliar para percorrer a lista.
			
			while(aux != NULL)//Percorre os elementos da lista.
			{
				printf("%d ", aux->valor);//Exibe o valor armazenado no nó atual.
				aux = aux->prox; //O nó atual se torna o próximo nó.
			}
			printf("\n");//Pula uma linha para manter a organização.
		}
		
		/* Função para exibir todos os elementos da lista em ordem invertida.
		 */
		void printListReverse()
		{
			
			if(raiz == NULL) //Se a raiz for nula, a lista está vazia, informa isso e finaliza a função.
			{
				printf("Lista vazia\n");
				return;
			}
			
			node *aux = last; //Nó auxiliar para percorrer a lista.
			
			while(aux != NULL)//Percorre os elementos da lista.
			{
				printf("%d ", aux->valor);//Exibe o valor armazenado no nó atual.
				aux = aux->prev; //O nó atual se torna o nó anterior.
			}
			printf("\n");//Pula uma linha para manter a organização.
		}

		/* Insere um elemento à direita da lista.
		 * 
		 * v - valor do elemento que será inserido.
		 */
		void insertRight(int v)
		{
			node *novo = (node *)malloc(sizeof(node)); //Aloca memória para o novo nó.
			novo->valor = v;
			novo->prox = NULL;
			novo->prev = NULL;
						
			if(raiz == NULL) //Se a lista estiver vazia, a raiz recebe o novo elemento e finaliza a função.
			{
				raiz = novo;
				last = raiz;
				size++; //Aumenta o tamanho da lista.
				return;
			}
			
			node *aux = raiz;
			while(aux->prox!=NULL)//Percorre a lista até o último elemento.
			{
				aux = aux->prox; //O nó atual se torna o próximo nó.
			}
			aux->prox = novo; //Aloca o novo nó em sequência ao último nó.
			novo->prev = aux; //Define o anterior do novo nó como o último nó.
			last = novo;
			
			size++;//Incrementa o tamanho da lista.
		}
		
		/* Insere um elemento à esquerda da lista.
		 * 
		 * v - valor do elemento que será inserido.
		 */
		void insertLeft(int v)
		{
			node *novo = (node *)malloc(sizeof(node)); //Aloca memória para o novo nó.
			novo->valor = v;
			novo->prox = NULL;
			novo->prev = NULL;
						
			if(raiz == NULL) //Se a lista estiver vazia, a raiz recebe o novo elemento e finaliza a função.
			{
				raiz = novo;
				last = raiz;
				size++; //Aumenta o tamanho da lista.
				return;
			}
			
			raiz->prev = novo; //Aloca o  novo nó à esquerda da raiz.
			novo->prox = raiz; //Define o próximo nó após o novo nó como a raiz.
			raiz = novo; //A nova raiz recebe o endereço do novo nó.
			
			size++; //Incrementa o tamanho da lista.
			
		}
		
};
