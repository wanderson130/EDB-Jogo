#include<stdio.h>
#include<time.h>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>

//timer delay
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

using namespace std;

//Estrutura da Pilha

struct Pilha
	{
		int cor;
		Pilha* prox;
		//Pilha* anterior;
	};

//Função de gerar aleatorio
void gerar_valores(Pilha* vetor);

int main()
{
//	initscr();
	int i, j, c = 0, a, score = 0;
	int* vetor;
	char opc;
	bool loop = true;
	//Criando e zerando o inicio e fim da Pilha
	//Pilha* inicio = NULL;
	Pilha* topo= NULL;
	Pilha* aux;
	//Pilha* anterior;
	vetor = new (nothrow) int[i];
	do
	{
		Pilha* novo = new Pilha(); // alocando
		gerar_valores(novo);

		Pilha* jogada = new Pilha(); // alocando

        if(score==0){
		cin >> jogada->cor;
		novo->prox = topo;
		topo = novo;
        if(jogada->cor != novo->cor){
                c++;
                }
        }
        if(score>=1){
            novo->prox = topo;
            topo = novo;
            aux = topo;
            while(aux != NULL){
            cin >> jogada->cor;

            if(jogada->cor!= aux->cor){
                c++;
                }
            aux = aux->prox;
            }
        }
		if (c==0)
		{
			cout << "Você acertou!!!" << endl;
			score ++;
			cout << "Você está com: " << score << " pontos!!!" << endl;
			delay(1000);
			system("cls");
		}
		else
		{
		    system("cls");
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
		        cin >> opc;
		        opc = tolower(opc);
	    	}

		    if(opc=='n')
                return 0;
		    if(opc=='s')
                loop = false;
		}

		i++;
        aux = topo;
        while(aux != NULL){
            //cout << aux->cor << endl;
            delay(1000);
        if(aux->cor==0){
        system("color 4a"); //vermelho x = 0
        PlaySound(TEXT("Charmander.wav"), NULL, SND_SYNC);
        delay(500);
        system("color 0a"); // preto
        }
        if(aux->cor==1){
		system("color 6a"); //amarelo x = 1
		PlaySound(TEXT("Pikachu.wav"), NULL, SND_SYNC);
		delay(500);
		system("color 0a"); // preto
        }
		if(aux->cor==2){
		system("color 2a"); //verde x = 2
		PlaySound(TEXT("Bulbasaur.wav"), NULL, SND_SYNC);
		delay(500);
		system("color 0a"); // preto
		}
		if(aux->cor==3){
		system("color 1a"); //azul x = 3
		PlaySound(TEXT("Squirtle.wav"), NULL, SND_SYNC);
		delay(500);
		system("color 0a"); // preto
		}
        aux = aux->prox;

        }
	}while(loop != false);
	aux = topo;
	while(aux != NULL)
	{
		topo = topo->prox;
		delete(aux);
		aux = topo;
	}
	//Verifica se a pilha está vazia
	if (topo == NULL){
        cout << "Esta foi a ordem correta" << endl;
        cout << "..." << endl;
        delay(500);

        cout << "Um novo jogo sera carregado.." << endl;

        delay(3000);

        system("cls");

	}
	else
	{		aux = topo;
			while(aux != NULL)
			{
				topo = topo->prox;
				delete(aux);
				aux = topo;
			}
	}
    main();
}

void gerar_valores(Pilha* vetor)
{
	int i;
	srand(time(NULL));
	vetor->cor = rand() % 4;
        delay(1000);
        if(vetor->cor==0){
        system("color 4a"); //vermelho x = 0
        PlaySound(TEXT("Charmander.wav"), NULL, SND_SYNC);
        delay(500);
        system("color 0a"); // preto
        }
        if(vetor->cor==1){
		system("color 6a"); //amarelo x = 1
		PlaySound(TEXT("Pikachu.wav"), NULL, SND_SYNC);
		delay(500);
		system("color 0a"); // preto
        }
		if(vetor->cor==2){
		system("color 2a"); //verde x = 2
		PlaySound(TEXT("Bulbasaur.wav"), NULL, SND_SYNC);
		delay(500);
		system("color 0a"); // preto
		}
		if(vetor->cor==3){
		system("color 1a"); //azul x = 3
		PlaySound(TEXT("Squirtle.wav"), NULL, SND_SYNC);
		delay(500);
		system("color 0a"); // preto
		}
}
