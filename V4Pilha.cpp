#include <iostream>
//#include <ncurses.h> // substitui a biblioteca "conio.h"
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

//Estrutura da Pilha

struct Pilha
	{
		int cor;
		Pilha* prox;
	};

//Função de gerar aleatorio
void gerar_valores(Pilha* vetor);

int main()
{
//	initscr();
	int score = 0;
	char opc;
	bool loop = true;
	//Criando e zerando o inicio e fim da Pilha
	//Pilha* inicio = NULL;
	Pilha* topo= NULL;
	Pilha* aux;
	Pilha* anterior;

	do
	{
		Pilha* novo = new Pilha(); // alocando
		gerar_valores(novo);
		
		Pilha* jogada = new Pilha(); // alocando
		cin >> jogada->cor;
		novo->prox = topo;
		topo = novo;

		if (jogada->cor == novo->cor)
		{
			cout << "Você acertou!!!" << endl;
			score ++;
			cout << "Você está com: " << score << " pontos!!!" << endl;
		}
		else
		{	
			cout << "Você ERROU" << endl;
			cout << "Pontuação final: " << score << " pontos!!!" << endl;
			cout <<"cor certa " << topo->cor << endl;
			score = 0;
			cout << "Dejesa continuar (s/n)? " << endl;
              	
            cin >> opc;
   			opc = tolower(opc);
			while(opc != 'n' and opc !='s')
			{
				cout << "Opção INVALIDA!!" << endl << "Dejesa continuar (s/n)? " << endl;
		        system("clr"); //NÃO TÁ PEGANDO NO LINUX.. TEM QUE PROCURAR UMA FUNÇÃO QUE FUNCIONE!!!
		        cin >> opc;
		        opc = tolower(opc);
	    	}
	            
		    if(opc=='n')
		        loop = false;
		    else
		    if(opc=='s')
	       		loop =  true;
		}		
	}while(loop != false);

	//Para imprimir a pliha..
	// 			obs:
	//				Ela será imprimida da ultima até a primeira!!!
	aux = topo;
	while(aux != NULL)
	{
		cout << aux->cor <<endl;
		aux = aux->prox;
	}

	//Para remover toda a pliha..
	aux = topo;
	while(aux != NULL)
	{
		topo = topo->prox;
		delete(aux);
		aux = topo;
	}
	//Verifica se a pilha está vazia
	if (topo == NULL)
		cout << "A pilha está vazia" << endl;
	else
	{		aux = topo;
			while(aux != NULL)
			{
				topo = topo->prox;
				delete(aux);
				aux = topo;
			}
	}

	return 0;
}

void gerar_valores(Pilha* vetor)
{
	int i;
	srand(time(NULL));

	vetor->cor = rand() % 4;	 
}
