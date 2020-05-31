# Listas

  Listas são estruturas de dados dinâmicas que permitem alocar elementos em sequência. Cada elemento de uma lista pode guardar valores de diversos tipos. Cada elemento de uma lista é alocado em memória no mesmo momento em que é adicionado à mesma, impedindo que a lista guarde elementos vazios como pode acontecer em vetores, assim, o uso de memória é otimizado. Também diferente dos vetores, uma lista não pode ser accessada aleatóriamente, apenas sequencialmente.
  Cada elemento de uma lista é chamado de "nó", e cada nó é referênciados pelo nó anterior, ou seja, apenas o primeiro nó, ou nó raiz, é necessário para referenciar a lista inteira.

## Listas Simplesmente Encadeada

  Além de armazenar os valores da lista, os nós também devem armazenar uma referência para o próximo nó, essa referência é feita armazenando o endereço na memória do próximo nó. O último nó da lista armazena o valor nulo como endereço ao próximo nó.
  
## Listas Duplamente Encadeadas

  Diferente das listas simplesmente encadeadas, os nós de uma lista duplamente encadeada não armazenam apenas referências ao próximo nó. Cada nó de uma lista duplamente encadeada armazena referências ao próximo nó e também ao nó anterior, possibilitando que a lista seja percorrida no sentido oposto.
