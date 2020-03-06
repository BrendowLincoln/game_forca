#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("\nSEJA BEM-VINDO AO JOGO DA FORCA 2000\n\n");
    
    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");

    /*Vaiáveis que se identificara o término do loop geral e qual motivo.*/

    int enforcou = 0;
    int acertou = 0;
    int tentativas = 0;
    char chutes[26];

    
    /*Loop geral do software*/

    do {

        /*Aqui é onde há a interação com o usuário pergunto o chute que ele dá.*/

        char chute;

        printf("Qual é a letra?\n");
        printf("Chute: ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;


        //Inteligência para identificar se acertou e descobrir a letra.

            for(int i = 0; i < strlen(palavrasecreta); i++){

                int achou =  0;

                for(int j =0; j < tentativas; j++) {

                    if(chutes[j] == palavrasecreta[i]) {
                        achou = 1;
                        break;

                    }

                }

                if(achou) {

                    printf("%c", palavrasecreta[i]);

                } else {

                    printf("_");

                }

            }

            printf("\n");
        
        
        /*BUG DO SCANF: O scanf reconhece o enter como um caractere e quando validamos um chute,
        o enter fica como BUFF. Então quando ele nos pergunta de novo, o BUFF é validado na hora
        rodando mais uma vez sem nos perguntar. Por isso é preciso adicionar um espaço dentro das
        aspas antes da máscara*/

        /*Loop de repetição para apresentação da palavra secreta*/

        for(int i = 0; i <= strlen(palavrasecreta); i++) {

            /*Condicional para verificar se o chute informado bate com alguma letra da
            palavra secreta e mostrar qual posição estás.*/

            if(palavrasecreta[i] == chute) {

                printf("A posição %d tem essa letra\n", i + 1);

            }

        }

        /*A "!" (exclamação) nas variáveis a baixo esta invertendo o valor original delas.*/
        /*Transformou o valor da variável de 0 para 1. Então, o loop*/

    } while(!acertou && !enforcou);

}