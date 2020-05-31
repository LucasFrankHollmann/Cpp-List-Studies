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
		
		/* Informa o tamanho atual da lista.
		 * 
		 * retorno - o tamanho da lista.
		 */
		int getSize()
		{
			printf("Tamanho: %d\n", size);
			return size;
		}
		
		/* Verifica se a lista está vazia ou não.
		 * 
		 * retorno - true caso a lista esteja vazia ou false caso contrário.
		 */
		 bool isEmpty()
		 {
			 bool vazio = (raiz == NULL); //Calcula o valor lógico da expressão, verificando se a lista está vazia ou não.
			 if(vazio)
			 {
				 printf("Lista vazia\n");
				 return vazio;
			 }
			 else
			 {
				 printf("Lista nao vazia\n");
				 return vazio;
			 }
			 
			 return (raiz == NULL); //Retorna o 
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
		
		/* Remove todos os elementos com o valor indicado.
		 * 
		 * v - valor dos elementos para remover.
		 */
		void removeValue(int v)
		{
			if(raiz == NULL)//Se a lista estiver vazia, encerra a função após informar isso.
			{
				printf("Lista vazia\n");
				return;
			}
			
			bool removeuAlgo = false; //Variável para verificar se algum elemento será removido.
			
			while(raiz->valor == v) //Se o valor da raiz for o valor a ser removido, torna o nó após a raiz a nova raiz.
			{
				raiz = raiz->prox;
				size--; //Decrementa o tamanho.
				if(raiz == NULL) //Se a lista ficou vazia, atualiza o last e finaliza a função.
				{
					last = NULL;
					return;
				}
				raiz->prev = NULL;
				removeuAlgo = true;
				//Essa ação é repetida, pois a raiz é atualizada, então ela deve ser analizada de novo.
			}

			node *aux = raiz; //Nó auxiliar para percorrer a lista.
			
			while(aux != NULL)
			{
				if(aux->valor == v)
				{
					node *aux2 = aux->prev; //Nó auxiliar armazena o nó anterior ao atual.
					aux2->prox = aux->prox; //O nó após o anterior se torna o próximo ao atual, excluindo o atual.
					aux = aux->prox; //Nó atual se torna o próximo nó;
					
					if(aux!=NULL)//Se o próximo nó não for nulo, ele será atualizado.
					{
						aux->prev = aux2; //Define o nó anterior ao novo atual.
					}
					else //Se o próximo nó for nulo, atualiza o next, pois alterou o fim da lista.
					{
						last = aux2;
					}
					size--; //Decrementa o tamanho da lista.
					removeuAlgo = true;//Indica que pelo menos um elemento foi removido.
				}
				else//Caso não seja necessário remover o elemento, avança para o próximo.
				{
					aux = aux->prox;
				}
			}
			if(!removeuAlgo)//Se nenhum elemento foi removido, exibe essa informação.
			{
				printf("Nenhum elemento removido\n");
			}
		}
		
		/* Remove o elemento da lista na posição indicada.
		 * 
		 * n - a posição da lista para remover o elemento (iniciando em 0).
		 */
		void removeIndex(int n)
		{
			if(n < 0) //Se o índice for inválido, encerra a função.
			{
				printf("Indice invalido\n");
				return;
			}
			
			if(raiz == NULL)//Se a lista estiver vazia, encerra a função após informar isso.
			{
				printf("Lista vazia\n");
				return;
			}
			
			if(n == 0) //Caso o nó removido seja o primeiro, atualiza a raiz, removendo a anterior.
			{
				raiz = raiz->prox;
				raiz->prev = NULL;
				size--; //Decrementa o tamanho da lista.
				return; //Encerra a função.
			}
			
			node *aux = raiz; //Nó auxiliar para percorrer a lista.
			
			for(int i=0;i<n;i++)//Percorre n nós até chegar no nó que deve ser excluído.
		    {
			   aux = aux -> prox;
			   if(aux == NULL) //Caso não seja possível percorrer até o índice n, informa e encerra a função.
			   {
				   printf("A lista e menor do que o indice informado\n");
				   return;
			   }
		    }
		   
		    if(aux->prox == NULL) //Verifica se ainda há outro nó após o nó que será excluído.
		    {
			   last = aux->prev; //Caso o nó excluído seja o útimo, atualiza o last.
			   last->prox = NULL;
		    }
		    else
		    {
			   node *aux2 = aux->prox; //Nó auxiliar para poder atualizar os nós.
			   aux = aux->prev; //Retorna ao nó anterior ao excluído.
			   aux->prox = aux2; //Nó anterior ao excluído aponta para o nó após o excluído.
			   aux2->prev = aux; //Nó após o excluído aponta o nó anterior como o nó antes do excluído.
		    }
		    size--; //Decrementa o tamanho da lista.
		}
		
		/* Acha o elemento em uma determinada posição.
		 * 
		 * n - posição do elemento para encontrar (iniciando em 0).
		 * retorno - o nó encontrado.
		 */
		node *searchIndex(int n)
		{
			if(n < 0) //Se o índice for inválido, encerra a função.
			{
				printf("Indice invalido\n");
				return NULL;
			}
			
			if(raiz == NULL)//Se a lista estiver vazia, encerra a função após informar isso.
			{
				printf("Lista vazia\n");
				return NULL;
			}
			
			node *aux = raiz; //Nó auxiliar para percorrer a lista.
			
			for(int i=0;i<n;i++)//Percorre n nós até chegar no nó que deve ser encontrado.
		    {
			   aux = aux -> prox;
			   if(aux == NULL) //Caso não seja possível percorrer até o índice n, informa e encerra a função.
			   {
				   printf("A lista e menor do que o indice informado\n");
				   return NULL;
			   }
		    }
		   
		    printf("Valor encontrado na posicao %d: %d\n", n, aux->valor); //Exibe o valor encontrado.
		    return aux; //Retorna o elemento encontrado.
		}
};
