#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct noProduto{
	int cod, qt;
	char nome[20];
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
    printf("Codigo do Produto:");
    scanf("%d",&novo->cod);
    
    printf("Nome do Produto:");
    scanf("%s",&novo->nome);
    
    printf("Quantidade:");
    scanf("%d",&novo->qt);
    
    printf("Preco do Produto:");
    scanf("%f",&novo->preco);
    
	novo->cod = novo->cod;
    strcpy(novo->nome,novo->nome);
    novo->qt = novo->qt;
    novo->preco = novo->preco;
    
    novo->prox = inicio;
    inicio = novo;
}

void remover (int dado)
{
    int removido;
    noProduto *aux, *ant;
    aux = inicio;
    while ((aux != NULL) && (aux->cod != dado))
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
        printf("Codigo %d nao foi encontrado na lista\n\n",dado);
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
        printf("Codigo [%d] foi removido da lista\n\n", removido);
        free(aux);
        system("pause");
    }
}


void listar ()
{
    noProduto *aux;
    aux = inicio;
	printf("COD - NOME - QT - PRECO\n\n");
    while(aux != NULL)
    {

    printf("%d - %s - %d - %.2f\n",aux->cod,aux->nome,aux->qt,aux->preco);
        aux = aux->prox;
    }
    printf("\n\n");
}

void vender(int codpesq)
{
noProduto *aux, *vender;
aux = inicio;
float qtc;
float precototal;

while(aux != NULL)
{
	if(aux->cod==codpesq)
	{
		system("cls");
		printf("Produto Encontrado:%s\n",aux->nome);
		printf("Quantidade Disponivel:%d\n",aux->qt);
		printf("Preco:%.2f\n",aux->preco);
		
		vender = aux;
	}
 aux = aux->prox;
 }
 
 printf("\n\n");
 printf("Digite Qt que Deseja comprar:");
 scanf("%f",&qtc);
 
 if(vender->qt >= qtc)
 {
 	precototal = qtc * vender->preco;
 	
 	printf("Compra Realizada com Sucesso!\nPreco Total:%.2f\n",precototal);
 	system("pause");
 	
 	vender->qt = vender->qt - (int)qtc;
 }
 else
 printf("Quantidade indisponivel.");
 system("pause");
 
}


int gerente()
{
	
	int op, dado, codpesq, menuPri, senha;
    inicio = NULL;
	
do{
		system("cls");
        printf("Escolha uma operacao:\n");
        printf("1 - Cadastrar Produtos\n");
        printf("2 - Remover Produto\n");
        printf("3 - Relatorio de Produtos\n");
        printf("4 - Vender Produto\n");
        printf("5 - Retornar Menu Principal\n");
        printf("0 - Sair do programa\n");
        printf("Operacao:\n");
        scanf("%d",&op);

        if(op==1)
        {
        inserir();
        }
        else if(op==2)
        {
        if (listavazia()== 0)
	    {
	    printf("Codigo Removido: ");
	    scanf("%d",&dado);
	    printf("\n\n");
	    remover(dado);
        system("pause");
        }
        }
		else if(op==3)
		{
        if(listavazia()==0)
            listar();
            system("pause");
        }
        
        else if(op==4)
        {
        	
        if(inicio!=NULL)
        	{
        printf("Digite Codigo Prod:");
        scanf("%d",&codpesq);
    	vender(codpesq);
        }
        else 
        {
        	
		printf("Nao existe produto cadastrado\n");
		_sleep(2000);
		    }
        }
        
        
       else if(op==5)
		{
			return 3;
		}
		
        }while(op!=0);

}

int vendedor()
{
	
	int op, dado, codpesq, menuPri, senha;
    inicio = NULL;
	
do{
		system("cls");
        printf("Escolha uma operacao:\n");
        printf("1 - Relatorio de Produtos\n");
        printf("2 - Vender Produto\n");
        printf("3 - Retornar Menu Principal\n");
        printf("0 - Sair do programa\n");
        printf("Operacao:\n");
        scanf("%d",&op);

  
		if(op==1)
		{
        if(listavazia()==0)
            listar();
            system("pause");
        }
        
        else if(op==2)
         {
        	
        if(inicio!=NULL)
        	{
        printf("Digite Codigo Prod:");
        scanf("%d",&codpesq);
    	vender(codpesq);
        }
        else 
        {
        	
		printf("Nao existe produto cadastrado\n");
		_sleep(2000);
		    }
        }
        
        else if(op==3)
        {
        return 3;
        }
            
        }while(op!=0);	
}

int menuinicial()
{
	
	int menuPri;
	
	
	    system("cls");
        printf("Escolha uma opcao:\n");
        printf("1 - Gerente\n");
        printf("2 - Vendedor\n");
        printf("Operacao:");
        scanf("%d",&menuPri);
    
        return menuPri;
}

main()
{
    
	int  menuPri, senha;
    inicio = NULL;

        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1 - Gerente\n");
        printf("2 - Vendedor\n");
        printf("Operacao:");
        scanf("%d",&menuPri);

do{
    
  		switch(menuPri)
  		{
        case 1:
    	printf("Digite a Senha:");
    	scanf("%d",&senha);
        if(senha==12345)
        menuPri = gerente();
        
        break;
        
		case 2:
		printf("Digite a Senha:");
    	scanf("%d",&senha);
        if(senha==321)
        
        menuPri = vendedor();
        
        break;
        
    	case 3:
    	
    	menuPri = menuinicial();
        
		}
	
	}
	
	
	while(menuPri!=0);    
}
    







