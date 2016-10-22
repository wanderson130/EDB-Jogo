/*	tá dando um erro ..
*  
*
*/

#include <iostream>
#include <ncurses.h> // substitui a biblioteca "conio.h"
#include <ctime>

using namespace std;

//Estrutura da lista
struct Lista
	{
		int cor;
		Lista* prox;
	};
//Função de gerar aleatorio
void gerar_valores(Lista* vetor);

int main()
{
//	initscr();

	int score = 1;

	//Criando e zerando o inicio e fim da lista
	Lista* inicio = NULL;
	Lista* fim = NULL;
	Lista* aux;
	Lista* anterior;
	Lista* novo = new Lista(); // alocando
	Lista* jogada = new Lista(); // alocando

	do
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
		cout << "Você está com:" << score << "pontos!!!" << endl;
	}
	else
	{	
		cout << "Você ERROU" << endl;
		score = 0;
	}
	cout << inicio->cor << endl;
	while(score != 0);


	return 0;
}
void gerar_valores(Lista* vetor)
{
	int i;
	srand (time(NULL));
	
	vetor->cor = rand() % 4;	 
}