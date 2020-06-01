//Autor: Lucas Frank Hollmann

#include <stdio.h> //Biblioteca para usar printf.
#include <stdlib.h> //Biblioteca para usar malloc.

struct node
{
    int valor;
    struct node *prox;
    
};
typedef struct node node;

class List
{
    private:
        node *raiz;
        int size;
    
    public:
        
        List()
        {
            raiz = NULL;
            size = 0;
        }
        
        
        /* Exibe todos os elementos da lista.
        */ 
        void printList()
        {
            if(raiz == NULL) //Caso a lista esteja vazia, informa isso e retorna, finalizando a função.
            {
                printf("Lista vazia\n");
                return;
            }
            
            node *aux = raiz; //Nó auxiliar para percorrer a lista.
            
            while(aux != NULL) //Percorre todos os nós da lista.
            {
                printf("%d  ", aux->valor); //Exibe o valor do nó atual;
                
				aux = aux->prox; //O nó atual se torna o próximo nó.
            }
            printf("\n"); //Pula uma linha para manter a organização na tela.
        }
        
        /* Insere um novo elemento à direita da lista.
         * 
         * v - valor a ser inserido.
         */
        void insertRight(int v)
        {
            node *novo = (node*)malloc(sizeof(node)); //Cria o novo nó para ser inserido na lista.
            novo->valor = v; //Passa o valor a ser inserido para o novo nó.
            novo->prox = NULL; //Informa que o nó após o novo é NULL.
            
            if(raiz == NULL)//Caso a lista estiver vazia, o novo nó será inserido na raiz.
            {
                raiz = novo;
            }
            else //Caso a lista não esteja vazia, insere o novo nó à direita da lista.
            {
                node *aux = raiz; //Nó auxiliar para percorrer a lista.
                while(aux->prox!=NULL) //Percorre a lista para achar o último nó.
                {
                    aux = aux->prox;
                }
                aux->prox = novo; //Insere o novo nó em frente ao último nó da lista.
            }
            
            size++; //Incrementa o tamanho da lista.
        }

		/* Insere um novo elemento à esquerda da lista.
		 * 
		 * v - valor a ser inserido.
		 */
        void insertLeft(int v) 
        {
            node *novo = (node*)malloc(sizeof(node)); //Cria o novo nó para ser inserido na lista.
            novo->valor = v; //Passa o valor a ser inserido para o novo nó.
            novo->prox = NULL; //Informa que o nó após o novo é NULL.
            
            if(raiz == NULL)//Caso a lista estiver vazia, o novo nó será inserido na raiz.
            {
                raiz = novo;
            }
            else //Caso a lista já tenha elementos, o novo nó é inserido atrás da raiz atual.
            {
                novo->prox = raiz; //A raiz é posicionada na frente do novo nó.
                raiz = novo; // Novo se torna a nova raiz.
            }
            
            size++; //Incrementa o tamanho da lista;
        }
        
		/* Acha o elemento em uma determinada posição.
		 * 
		 * n - posição do elemento para encontrar (iniciando em 0).
		 * retorno - o nó encontrado.
		 */
		int *searchIndex(int n)
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
		    return &(aux->valor); //Retorna o elemento encontrado.
		}
       
       /* Exibe o tamanho atual (quantidade de elementos) da lista.
        *
        * retorno - o tamanho da lista.
        */
       int getSize()
       {
		   printf("O tamanho da lista e %d\n", size);
		   return size;
	   }
	   
	   /* Mostra se a lista está vazia ou não.
	    * 
	    * retorno - verdadeiro caso a lista esteja vazia, falso caso contrário.
	    */
	   bool isEmpty()
	   {
		   if(raiz==NULL)
		   {
			   printf("A lista esta vazia\n");
			   return true;
		   }
		   else
		   {
			   printf("A lista nao esta vazia\n");
			   return false;
		   }
	   }
       
       /* Remove todos os elementos que tenham um determinado valor.
        * 
        * v - valor a ser removido.
        */
       void remove(int v)
       {
		   
		   if(raiz == NULL)
		   {
			   printf("Lista vazia\n");
			   return; //Caso a lista esteja vazia, encerra a função.
		   }
		   
		   
		   
		   bool removeuAlgo = false; //Variável para verificar se ao menos um elemento foi removido.
		   
		   while(raiz->valor == v)
		   {
			   raiz = raiz->prox; //Se o valor da raiz for um valor para remover, o próximo nó após a raiz se torna a próxima raiz, eliminando a raiz anterior.
			   removeuAlgo = true;
			   size--; //Diminui o tamanho da lista.
			   //essa ação é repetida pois a raiz é alterada durante o processo, então é necessário checar a nova raiz.
		   }
		   
		   node *aux = raiz; //Nó auxiliar para percorrer a lista.
		   node *aux2 = aux->prox; //Segundo nó auxiliar, será utilizado para poder marcar o nó anterior ao atual.
		   
		   while(aux2 != NULL) //Percorre todos os nós da lista.
		   {
			   if(aux2->valor == v)//O valor do nó atual deve ser removido.
			   {
				   aux->prox = aux2->prox; //O nó após o atual se torna o nó que estava após o próximo.
				   delete(aux2); //Deleta o nó removido.
				   removeuAlgo = true;
				   size--; //Diminui o tamanho da lista.
			   }
			   else
			   {
				   aux = aux->prox; //O nó atual se torna o próximo nó.
			   }
			   
			   aux2 = aux->prox; //O segundo nó auxiliar vira o nó após o atual.
			   
			   
		   }
		   if(!removeuAlgo)//Se nenhum elemento foi removido, exibe essa informação.
		   {
			   printf("Nenhum elemento para remocao foi encontrado\n");
		   }
	   }
	   
	   /* Remove o elemento de índice n da lista.
        * 
        * n - índice do elemento para remover (iniciando em 0).
        */
	   void removeIndex(int n)
       {
		   		   		      
		   node *aux;//Nó auxiliar para percorrer a lista.
		   node *aux2 = raiz; //Segundo nó auxiliar, será utilizado para poder marcar o nó anterior ao atual.
		   
		   if(n == 0 ) //Caso o nó removido seja o primeiro, atualiza a raiz, removendo a anterior.
		   {
			   if(raiz == NULL)//Se a lista estiver vazia, finaliza a função.
			   {
				   printf("A lista é menor do que o indice informado\n");
				   return;
			   }
			   raiz = raiz->prox; //Se o valor da raiz for um valor para remover, o próximo nó após a raiz se torna a próxima raiz, eliminando a raiz anterior.
			   size--; //Diminui o tamanho da lista.
			   return; //Finaliza a função.
		   }
		   
		   for(int i=0;i<n;i++)//Percorre n nós até chegar no nó que deve ser excluído.
		   {
			   if(aux2==NULL) //Caso não seja possível percorrer até o índice n, informa e encerra a função.
			   {
				   printf("A lista e menor do que o indice informado\n");
				   return;
			   }
			   aux = aux2;
			   aux2 = aux2->prox;
		   }
		   
		   if(aux2->prox == NULL) //Verifica se ainda há outro nó após o nó que será excluído.
		   {
			   delete(aux2); //Caso não haja mais nós após o excluído, apenas deleta o nó.
			   aux->prox = NULL; //Define o prox do nó anterior ao excluído como NULL.
		   }
		   else
		   {
			   aux->prox = aux2->prox;//Caso haja mais nós após o excluído, define o prox do anterior como o prox do excluído.
			   delete(aux2);//Deleta o nó excluído.
		   }
		   size--; //Decrementa o tamanho da lista.

	   }
       
};
