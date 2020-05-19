#include <stdio.h>
#include <stdlib.h>

struct noFila{
    int dado;
    noFila *prox;
};

noFila *inicio, *fim;

void inserir ()
{
	 
	int dado;
    noFila *novo;
    novo = ( noFila*) malloc (sizeof(noFila));
    printf("Inserir Dados:");
    scanf("%d",&dado);
    novo->dado = dado;
    novo->prox = NULL;
    if (fim == NULL)
        inicio = novo;
    else
    {
        fim->prox = novo;
     }
    fim = novo;
}

void remover()
{
    int removido;
    noFila *aux;
    aux = inicio;
    removido = inicio->dado;
    inicio = inicio->prox;
    
    
    printf("Valor [%d] foi retirado da fila\n\n",removido);
    free(aux);
}


void imprimir ()
{
    noFila *aux;
    aux = inicio;
    printf("Dados inseridos:\n");
    while(aux != NULL)
    {
        printf("[%d]",aux->dado);
        aux = aux->prox;
    }
}

void ordenar()
{

noFila *x, *y;
int aux;


for(x=inicio;x!=NULL;x = x->prox)
{
	for(y=x;y!=NULL;y = y->prox)
	{
		if(x->dado > y->dado)
		{
		aux = y->dado;
		y->dado = x->dado;
		x->dado = aux;
		}
	}
}
}

main()
{
    int op, dado;
    inicio = NULL;
    fim = NULL;
    
    do{
    	system("cls");
    	printf("*No Fila*\n");
    	printf("\n");
        printf("1- Inserir Dados:\n");
        printf("2- Retirar:\n");
        printf("3- Imprimir.\n");
        printf("4- Ordenar\n");
        printf("Operacao: ");
        scanf("%d",&op);
        
        if(op==1)
		{
        
        inserir();
        }
        else if(op==2)
        {
        remover();
        system("pause");
        }

        else if(op==3)
        {
        imprimir();
        system("pause");   
        }
        
        else if(op==4)
        {
    	ordenar();
        }
        
    }while(op!=0);
    
}
