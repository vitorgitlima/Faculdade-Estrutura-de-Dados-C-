#include <stdio.h>
#include <stdlib.h>

struct noPila{
    int dado;
    noPila *prox;
};

noPila *topo;

void inserir (int dado)
{
    noPila *novo;
    novo = (noPila*)malloc(sizeof(noPila));
    novo->dado = dado;
    novo->prox = topo;
    topo = novo;
}

void remover ()
{
    int removido;
    noPila *aux;
    aux =  topo;
    removido = topo->dado;
    topo = topo->prox;
    printf("O Valor [%d] foi retirado da pilha.\n\n", removido);
    free(aux);
}

void imprimir ()
{
    noPila *aux;
    aux = topo;
    printf("Dados inseridos:\n");
    while(aux != NULL)
    {
        printf("[%d]\n", aux->dado);
        aux = aux->prox;
    }
}

 main()
{
    int op, dado;
    topo = NULL;

    do{
    	system("cls");
        printf("*No Pilha*\n");
       	printf("\n");
        printf("1 - Inserir Dado na Pilha\n");
        printf("2 - Retirar\n");
        printf("3 - Imprimir\n");
        printf("Operacao: ");
        scanf("%d",&op);
    
        if(op==1)
            {
        printf("Inserir Dados:");
        scanf("%d",&dado);
        inserir(dado);
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
        
       }while(op!=0);
    
}



