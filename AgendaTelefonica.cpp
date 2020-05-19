#include<stdio.h>
#include<stdlib.h>


struct contato{
	int cod;
	char nome[10], numero[10];
};

contato Lista [5];
int indice = 0;

void imprimir(){
	
	for(int x=0;x<indice;x++){
		printf("Codigo -  %d\n",Lista[x].cod);
		printf("Nome: %s\n",Lista[x].nome);
		printf("Telefone:%s\n\n",Lista[x].numero);
				

	}
}

void inserir(){
	
		if(indice>4){
			printf("Lista Cheia");
			system("pause");
		}
	
	else{
		Lista[indice].cod=indice+1;
		printf("Digite Nome:");
		scanf("%s",&Lista[indice].nome);
		printf("Digite Numero: ");
		scanf("%s",&Lista[indice].numero);
		indice = indice + 1;	
	}
	
}

void pesquisar(){
}

void retirar(){
	
	int pesq, testelog;
	
	printf("Digite o Codigo");
	scanf("%d",&pesq);
	
	for(int x=0;x<5;x++){
		if(pesq==Lista[x].cod){
		testelog=x;
          	}
	}
	for(int x=testelog;x<5;x++){
		
			Lista[x]=Lista[x+1];			
	}
}



main()
{



	int op,testeLog;
	
	do{
	
		system("cls");
		printf("1 - Inserir\n");
		printf("2 - Imprimir\n");
		printf("3 - Retirar\n");
		printf("0 - Sair\n");
		printf("OPCAO: ");
		scanf("%d",&op);
		if(op==1){
			
		
			inserir();
		}
		if(op==2){
			imprimir();
			system("pause");
		}
		
		if(op==3){
			
			retirar();
		}
		
		
		}while(op!=0);
	}
	
			
	/*	{
			testeLog=ListaCheia();
			if(testeLog==0)
				printf("Lista esta cheia\n");
			else
				Inserir();
		}

		else if(op==2)
		{
			testeLog=ListaVazia();
			if(testeLog==0)
				printf("Lista esta vazia\n");
			else
			{
				Retirar();
			}
		}
		else if(op==3)
		{
			testeLog=ListaVazia();
			if(testeLog==0)
				printf("Lista esta vazia\n");
			else
			{
				Alterar();
			}
		}
		else if(op==4)
		{
			Esvaziar();
		}
		else if(op==5)
		{
			Imprimir();
		}
		*/
		/*system("pause");*/

