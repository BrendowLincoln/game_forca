#include <stdio.h>
#include <string.h>

//Função da abertura do jogo da forca

void  abertura()
{

 printf("\nSEJA BEM-VINDO AO JOGO DA FORCA 2000\n\n");

}

//Função que pede o chute

void chuta(char chutes[26], int* tentativas)
{
    char chute;
    printf("---------------------------------------------------\n");
    printf("Qual é a letra?\n");
    printf("Chute: ");
    scanf(" %c", &chute);
    printf("\n\n");

    chutes[*tentativas] = chute;
    (*tentativas)++;
}

int jachutou(char letra, char* chutes, int tentativas)
{
    int achou = 0;

    for(int j =0; j < tentativas; j++) 
    {

        if(chutes[j] == letra) 
        {
            achou = 1;
            break;

        }

    }

    return achou;
}


int main()
{
 
    //Array da palavra secreta 
    
    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");

    //Vaiáveis que se identificara o término do loop geral e qual motivo.

    int enforcou = 0;
    int acertou = 0;

    //Armazenamento dos chutes dados para o loop de aparecer e npumero de tentativas

    int tentativas = 0;
    char chutes[26];

    //Chamando a função de inicio

    abertura();

    
    //Loop geral do software

    do 
    {

        printf("Você já deu %d chutes\n", tentativas);

        //Inteligência para identificar se acertou e descobrir a letra.

        printf("\n");

        for(int i = 0; i < strlen(palavrasecreta); i++)
        {
            
            if(jachutou(palavrasecreta[i], chutes, tentativas)) 
            {

                printf("%c", palavrasecreta[i]);

            } else 
            {

                printf("_ ");

            }

        }

        printf("\n");

        //Aqui é onde é chamado a função para dar o chute.

        chuta(chutes, &tentativas);
        
        
        /*
         *BUG DO SCANF: O scanf reconhece o enter como um caractere e quando validamos um chute,
         *o enter fica como BUFF. Então quando ele nos pergunta de novo, o BUFF é validado na hora
         *rodando mais uma vez sem nos perguntar. Por isso é preciso adicionar um espaço dentro das
         *aspas antes da máscara
         */

        printf("\n");

        //A "!" (exclamação) nas variáveis a baixo esta invertendo o valor original delas.

        //Transformou o valor da variável de 0 para 1. Então, o loop

    } while(!acertou && !enforcou);

}