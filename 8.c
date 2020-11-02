#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void imprimir(char *aux, int contador);
char *separar(char linha[80], char *aux);
int main()
{
    char linha[80];
    char *aux;
    int contador = 0;
    printf("Digite as palavras separadas por espaco: ");
    fgets(linha, 80, stdin);
    contador=strlen(linha);
    aux = (char *)malloc(sizeof(linha) * sizeof(char));
    if (!aux)
    {
        printf("erro alocar memoria\n");
        return 0;
    }
    else
    {
        aux=separar(linha, aux);
        contador=strlen(aux);
        imprimir(aux,contador);
        free(aux);
        return 0;
    }
}
void imprimir(char *aux, int contador)
{
    int i;
    for(i=0;i<contador;i++)
    {
        printf("%c",aux[i]);
    }
}
char *separar(char linha[80], char *aux)
{
    int i = 0;
    printf("Separando...\n");
    while (linha[i] != '\0')
    {
        if (linha[i] == ' ')
        {
            aux[i]='\n';
        }
        else aux[i]=linha[i];
        i++;
    }
    return (char*) aux;
}
