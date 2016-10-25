#include <iostream>
//#include <ncurses.h> // substitui a biblioteca "conio.h"
#include <ctime>
#include <string>

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
	//Criando e zerando o inicio e fim da Pilha
	Pilha* inicio = NULL;
	Pilha* fim = NULL;
	Pilha* aux;
	Pilha* anterior;
	Pilha* novo = new Pilha(); // alocando
	Pilha* jogada = new Pilha(); // alocando


	do
	{
		gerar_valores(novo);
		if (inicio == NULL)
		{
			inicio = novo;
			fim = novo;
			fim->prox = NULL;
		}
		else
		{
			fim->prox = novo;
			fim = novo;
			fim->prox = NULL;
		}

		cin >> jogada->cor;

		if (jogada->cor == inicio->cor)
		{
			cout << "Você acertou!!!" << endl;
			score ++;
			cout << "Você está com: " << score << " pontos!!!" << endl;
		}
		else
		{	
			cout << "Você ERROU" << endl;
			cout << "Pontuação final: " << score << " pontos!!!" << endl;
			cout <<"cor certa " << inicio->cor << endl;
			score = 0;
			cout << "Dejesa continuar (s/n)? " << endl;
            cin >> opc;
            opc = tolower(opc);
    
            if(opc=='n')
                return 0;
            else
            if(opc=='s')
               return main();
		}

	}while(score != 0);


}

void gerar_valores(Pilha* vetor)
{
	int i;
	srand(time(NULL));

	vetor->cor = rand() % 4;	 
}
