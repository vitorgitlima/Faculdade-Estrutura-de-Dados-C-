#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct noDupla{
	int dado;
    noDupla *prox;
    noDupla *ant;
};


noDupla *inicio;

void inserir()
{
	noDupla *novo, *aux;
	int dado;
    novo = (noDupla*) malloc (sizeof(noDupla));
    printf("Digite o valor:");
	scanf("%d",&dado);
	
	if(inicio == NULL)
	{
	novo->dado = dado;
	novo->prox = novo->ant = NULL;
	inicio = novo;
	}
	else
	{
	novo->dado = dado;
	novo->ant = NULL;
	novo->prox = inicio;
	inicio->ant = novo;
	inicio =novo;
	
	}
	
}

void imprimir()
{
    noDupla *aux;
    aux = inicio;
    
    while(aux != NULL)
    {

    printf("[%d]",aux->dado);
    aux = aux->prox;
    }
    printf("\n\n");
}


main()
{
	int op, dado;
	inicio = NULL;
	
	
	    do{
	    	system("cls");
	        printf("Escolha uma opcao:\n");
	        printf("1 - Inserir valor\n");
	        printf("2 - Imprimir \n");
	        printf("Opcao escolhida:");
	        scanf("%d",&op);
	        
	        if(op==1)
	            {
	            inserir();
	            }
	            
	    	else if(op==2)
	    	{
	    	imprimir();
	    	system("Pause");
	    	}
	            
	    
	   }while(op!=0);
	    
	            
}

