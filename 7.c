#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    float *lista;
    int i=0,c=0;
    float num;
    lista = malloc(sizeof(float));
    if (!lista)
    {
        printf("Erro memoria lista - main");
        return;
    }
    else
    {
        for(i=0;;i++)
        {
            printf("Digite um numero para adicionar\n");
            printf("Digite 0 para sair\n");
            scanf("%f", &num);
            if (num==0) break;
            else
            {
                lista[i]=num;
                lista = realloc(lista, sizeof(lista) *i+1);
                c++;
                if(!lista)
                {
                    printf("Erro memoria lista - main\n");
                    return;
                }
            }
        }
        ordenar(lista,c);
        c=limpar(lista,c);
        imprimir(lista,c);
        free(lista);
    }
}
int limpar(float *lista, int c)
{
    int i,j,k;
    for(i=0;i<c;i++)
    {
        for(j=i+1;j<c;)
        {
            if(lista[j]==lista[i])
            {
                for(k=j;k<c;k++) lista[k]=lista[k+1];
                c--;
            }
            else j++;
        }
    }
    return c;
}
void ordenar(float *lista, int c)
{
    int i,j;
    float aux;
    for(j=0;j<c-1;j++)
    {
        for (i=0;i<c-1;i++)
        {
            if (lista[i]>lista[i+1])
            {
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
            }
        }
    }
}
void imprimir(float *lista, int c)
{
    int i;
    for (i=0;i<c;i++)
        printf("%.2f\t", lista[i]);
    printf("\n");
}