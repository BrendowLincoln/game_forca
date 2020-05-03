#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[20];
int chutesdados = 0;
char chutes[26];

void  abertura()
{

 printf("\nSEJA BEM-VINDO AO JOGO DA FORCA 2000\n\n");

}

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

void escolhepalavra()
{
    FILE* f;

    f = fopen("palavras.txt", "r");

    if (f == 0)
    {
        printf("Banco de dados  de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand () % qtddepalavras;

    for(int i = 0; i <= randomico; i++)
    {

        fscanf(f, "%s", palavrasecreta);

    }

    fclose(f);

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
    escolhepalavra();

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