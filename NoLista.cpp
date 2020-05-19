#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct noProduto{
	int cod, qt;
	char nome[500];
	float preco;
    noProduto *prox;
};

 noProduto *inicio;

int listavazia ()
{
    if (inicio == NULL)
        return 1;
    else
        return 0; 
}

void inserir()
{
    noProduto *novo;
    novo = (noProduto*) malloc (sizeof(noProduto));
    printf("Digite Codigo:\n");
    scanf("%d",&novo->cod);
    
	printf("Digite o Nome do Produto:\n");
	scanf("%s",&novo->nome);
	
    printf("Digite Quantidade:\n");
    scanf("%d",&novo->qt);
    
    printf("Digite o preco do Produto:\n");
    scanf("%f",&novo->preco);
    
    novo->cod = novo->cod;
    strcpy(novo->nome,novo->nome);
    novo->qt = novo->qt;
    novo->preco = novo->preco;
    
    if (inicio == NULL) 
    {
        novo->prox = NULL;
        inicio = novo;
    }
    else
    {
         noProduto *aux, *ant;
        aux = inicio;
        while ((aux != NULL) && (aux->cod < novo->cod))
        {
            {
                ant = aux;
                aux = aux->prox;
            }
        }

        if ((aux!=NULL) && (aux->cod == novo->cod))
            printf("\nO elemento ja existe na estrutura");
        else
            if (inicio == aux)
            { 
                inicio = novo;
                novo->prox = aux;
            }
            else
            {
                ant->prox = novo;
                novo->prox = aux;
            }
    }
}

void remover (int numero)
{
    int removido;
    noProduto *aux, *ant;
    aux = inicio;
    while ((aux != NULL) && (aux->cod != numero))
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
        printf("\nO elemento %d nao foi encontrado na lista\n\n",numero);
    else
    {
        if (aux->cod == inicio->cod)
        {
            removido = inicio->cod;
            inicio = inicio->prox;
        }
        else
        {
            removido = aux->cod;
            ant->prox = aux->prox;
        }
        printf("\nO valor %d foi removido da lista\n\n", removido);
        free(aux);
    }
}


void listar ()
{
    struct noProduto *aux;
    aux = inicio;
   // printf("Valores inseridos na lista sao: ");
    while(aux != NULL)
    {
        printf("Valor do Produto - [%d]", aux->cod);
        printf("\n");
        printf("Codigo do Produto - [%d]", aux->cod);
        printf("\n");
        printf("Quantidade do Produto - [%d]", aux->qt);
        printf("\n\n");
        aux = aux->prox;
    }
    printf("\n\n");
}

main()
{
    int op, valor, posicao, menuPri;
    inicio = NULL;
    char senha[6];

    do{
    	system("cls");
        printf("Escolha uma opcao:\n");
        printf("1 - Gerente\n");
        printf("2 - Vendedor\n");
        printf("Opcao escolhida:");
        scanf("%d",&menuPri);
        
        if(menuPri==1)
        {
        
		for(int x=0;x<6;x++)
    	{
    	printf("Digite sua senha:\n");
		senha[x]=getch();
		printf("*");
        }
        
        }
        
	    do{
	    	system("cls");
	        printf("Escolha uma opcao:\n");
	        printf("1 - Inserir um valor na lista\n");
	        printf("2 - Remover um valor da lista\n");
	        printf("3 - Listar os elementos da lista\n");
	        printf("4- Sair do programa\n");
	        printf("Opcao escolhida:");
	        scanf("%d",&op);
	        
	        if(op==1)
	            {
	                inserir();
	            }
	      
	        else if(op==2)
	            {	
	           if (listavazia()== 0)
	            {
	                printf("\nQual valor sera removido na lista: ");
	                scanf("%d",&valor);
	                printf("\n\n");
	                remover(valor);
	            }
			    }
	
	        else if(op==3)
	           {
	    
	            if (listavazia()== 0)
	                listar();
	                system("pause");
	 		   }
	        }while(op!=0);
	    }while(op!=0);
    }




