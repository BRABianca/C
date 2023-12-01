/*
Procedência de operadores:

++ -- (postfix);
= - ! (operadores unários)
* / % 
<> <= >=
== !=
&& ("E")
|| ("OU")
! ("NAO")
= += -= *= /= %=

int (inteiro)
chat (único caractere)
float (ponto flutuante de precisão simples)
double (ponto flutuante de precisão dupla)

for (inicialização; teste; atualização)
*/

#include <stdio.h>

int main() {
    int i = 5;
    if (i) {
        printf("in if\n");
    } else {
        printf("in else\n");
    }
    while (i>=0){
        printf("%d\n", i);
        i--;
    }
    return 0;
}