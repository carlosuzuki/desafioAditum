
# Desafio Aditum C++

### Descrição do projeto:

* O projeto possui um arquivo CSV como base de dados que contém o nome, horário de abertura e fechamento de uma lista de restaurantes.
* Como input do programa o usuário informa uma hora do dia no formato HH:MM, sendo HH entre 1 e 24 e MM entre 00 e 60.
* O programa e retorna uma lista de strings com os nomes dos restaurantes que estão abertos nessa hora. 

O projeto possui um método principal denominado de availableHours que foi desenvolvido em C++ utilizado o Qt Creator V5.15 
Esse método possui dois parâmetros: nome do arquivo CSV e o horário de consulta 
exemplo: availableHours("restaurant-hours.csv", "17:45");

Para compilar o programa é necessário apontar/substituir na linha 20 do arquivo "mainwindow" o local em que o arquivo CSV encontra-se salvo em seu computador.
