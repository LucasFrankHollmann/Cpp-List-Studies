#include "Lista_Simplesmente_Encadeada.h"
#include "Lista_Duplamente_Encadeada.h"

#include <stdio.h> //Biblioteca para usar printf.


int main()
{
	printf("Lista simplesmente encadeada:\n\n");
	
	List L;
	
	printf("	Inserindo valores na lista\n\n");
	
	L.insertLeft(1);
	L.insertRight(2);
	L.insertRight(3);
	L.insertRight(4);
	L.insertRight(5);
	L.insertLeft(-1);
	
	printf("		Lista: ");
	L.printList();
	
	printf("\n	Procurando o elemento da posicao 3\n\n");
	printf("		");
	L.searchIndex(3);
	
	printf("\n	Removendo o elemento da posicao 3\n\n");
	L.removeIndex(3);
	
	printf("		Lista: ");
	L.printList();
	
	
	
	
	printf("\n\n\n\nLista duplamente encadeada:\n\n");
	
	ListDE LDE;
	
	printf("	Inserindo valores na lista\n\n");
	
	LDE.insertLeft(50);
	LDE.insertRight(51);
	LDE.insertRight(52);
	LDE.insertRight(54);
	LDE.insertRight(55);
	LDE.insertLeft(-50);
	
	printf("		             Lista: ");
	LDE.printList();
	printf("		Lista ao contrario: ");
	LDE.printListReverse();
	
	printf("\n	Procurando o elemento da posicao 3\n\n");
	printf("		");
	LDE.searchIndex(3);
	
	printf("\n	Removendo o elemento da posicao 3\n\n");
	LDE.removeIndex(3);
	
	printf("		             Lista: ");
	LDE.printList();
	printf("		Lista ao contrario: ");
	LDE.printListReverse();
	
}
