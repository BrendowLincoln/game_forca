#include <stdio.h>
#include <string.h>
#include "forca.h"

char palavrasecreta[20];
int chutesdados = 0;
char chutes[26];

//Função da abertura do jogo da forca

void  abertura()
{

 printf("\nSEJA BEM-VINDO AO JOGO DA FORCA 2000\n\n");

}

//Função que pede o chute

void chuta()
{
    char chute;
    printf("---------------------------------------------------\n");
    printf("Qual é a letra?\n");
    printf("Chute: ");
    scanf(" %c", &chute);
    printf("\n\n");

    chutes[chutesdados] = chute;
}

int jachutou(char letra)
{
    int achou = 0;

    for(int j =0; j < chutesdados; j++) 
    {

        if(chutes[j] == letra) 
        {
            achou = 1;
            break;

        }

    }

    return achou;
}

int ganhou()
{

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
        
    }
    
    return 1;

}

void desenhaforca()
{

    printf("Você já deu %d chutes\n", chutesdados);

        //Inteligência para identificar se acertou e descobrir a letra.

        printf("\n");

        for(int i = 0; i < strlen(palavrasecreta); i++)
        {
            
            if(jachutou(palavrasecreta[i])) 
            {

                printf("%c", palavrasecreta[i]);

            } else 
            {

                printf("_ ");

            }

        }

        printf("\n");

}

void escolherpalavra()
{
    sprintf(palavrasecreta, "MELANCIA");
}

int enforcou()
{
    
    int erros = 0;

    for(int i =0; i < chutesdados; i++)
    {

        int existe = 0;

        for(int j = 0; j <strlen(palavrasecreta); j++)
        {

            if(chutes[i] == palavrasecreta[j])
            {

                existe = 1;
                break;

            }

        }

        if(!existe) erros++;

    }
    
    return erros >= 5;

}


int main()
{

    abertura();
    escolherpalavra();

    //Loop geral do software

    do 
    {

        desenhaforca();
        //Aqui é onde é chamado a função para dar o chute.

        chuta();
        chutesdados++;
        

        printf("\n");

    } while (!ganhou() && !enforcou());

}