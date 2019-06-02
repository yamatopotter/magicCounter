# magicCounter
Contador de Magic para Arduino.

Se você busca um contador que não consuma a bateria do seu telefone e se perde contando os pontos de vida no d20, esse projeto é para você.

Nesse projeto utilizamos um arduino Uno, um display 16x2 e 7 push buttons.

Caso você não tenha a biblioteca LiquidCrystal, procure-a no gerenciador de biblioteca da IDE do Arduino que vocÊ encontrará com facilidade.

No código está especificado exatamente quais portas do Arduino está em uso para cada item. Mas caso tenha duvidas na hora de interpretar o código, as portas usadas são:

btnMod = 10; -> esse botão é para fazer a troca entre pontos de vida e energia (ou o contador que você estiver necessitando em usar) | Escolher o numero do dado gerado randomicamente pelo Arduino

btnAdd = 8; -> botão de adicionar +1 a vida ou energia do Player 1

btnAdd5 = 6; -> botão de adicionar +5 a vida ou energia do Player 1 p/ 1 Jogador. Para 2 jogadores, esse botão serve para adicionar +1 a vida ou energia para o jogador 2.

btnLss = 7; -> botão para remover -1 a vida ou energia do Player 1

btnLss5 = 9; -> mesma coisa do botão add5, porém, ao invés de adicionar, remove -5.

int btnPly = 13 -> faz a troca do player na tela, mas essa função foi implementada com outro intuito. Atualmente não faz muito sentido.

Portas utilizadas pelo LCD (12 - RS, 11 - E, 5 - D4, 4 - D5, 3 - D6, 2 - D7)

A principio esse é o básico. Sinta-se a vontade para clonar e contribuir para o projeto.
