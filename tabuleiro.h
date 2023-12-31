#include "mbed.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


string tabuleiro [40][40];
bool statusMatriz = false;

int mapParede [40][40]= {
				{0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,35,36,37,38,39},
				{0,3,8,13,15,18,20,26,28,31,33,35,39},
				{0,1,5,6,7,8,9,10,11,13,14,15,16,22,23,24,26,29,32,37,39},
				{0,3,5,13,16,17,18,19,20,21,22,24,26,27,28,29,31,32,33,34,36,37,38,39},
				{0,2,3,5,7,9,10,11,12,13,14,18,22,24,29,31,39},
				{0,2,7,14,15,16,18,19,20,22,24,25,27,29,31,33,34,35,36,37,39},
				{0,2,3,4,6,7,8,10,12,16,20,22,25,27,29,35,37,38,39},
				{0,1,2,6,8,10,12,13,14,16,18,19,20,22,23,27,31,32,33,34,37,39},
				{0,4,6,10,14,18,23,25,26,27,28,29,34,36,37},
				{0,2,3,4,6,7,8,9,10,12,14,15,16,18,20,21,23,27,31,32,33,34,35,36,39},
				{0,2,4,5,6,12,17,18,21,23,24,25,27,28,29,32,36,38,39},
				{0,2,8,9,10,11,12,13,14,15,18,19,21,23,29,30,31,32,34,36,39},
				{3,4,5,6,8,13,16,19,21,25,26,27,32,34,37,39},
				{0,1,3,7,8,10,11,15,16,17,19,20,23,27,28,29,30,31,32,34,35,39},
				{0,3,5,7,11,13,14,15,17,19,22,23,24,25,26,28,37,39},
				{0,1,5,7,8,9,11,12,13,20,22,26,28,29,31,32,33,34,35,36,37,39},
				{0,2,3,5,9,14,16,18,22,24,29,37,39},
				{0,3,5,6,7,9,10,12,13,14,15,16,18,20,22,24,25,26,27,30,31,33,34,36,37,37,39},
				{0,1,9,10,11,12,17,18,20,21,22,26,28,36,39},
				{0,3,4,5,6,7,12,14,15,18,24,28,29,30,31,32,33,34,36,37,39},
				{0,2,3,7,8,9,10,15,16,21,23,26,30,37,39},
				{0,5,6,11,13,16,18,19,21,21,23,24,25,26,27,28,31,32,33,35,36,37,39},
				{0,1,2,3,4,6,8,9,10,11,13,14,18,22,29,31,34,37,39},
				{0,2,6,8,12,16,17,18,20,24,25,27,28,29,31,32,34,35,36,39},
				{0,4,6,8,10,12,14,15,20,21,22,23,28,32,36,37,38,39},
				{0,1,2,4,6,8,10,14,17,18,19,20,22,25,27,28,30,31,32,34,39},
				{0,2,4,5,6,7,9,10,11,12,13,14,15,18,24,27,34,35,36,37,38,39},
				{0,2,9,12,16,18,20,23,26,27,28,30,31,33,34,39},
				{0,3,4,5,7,8,9,11,14,16,18,20,22,23,24,26,28,29,30,36,37,38,39},
				{0,2,3,7,11,13,14,20,28,30,32,33,34,36,39},
				{0,1,5,6,7,9,15,17,18,19,20,21,23,24,25,26,27,30,38,39},
				{0,3,4,5,7,9,10,11,12,13,15,19,21,29,30,31,33,34,35,39},
				{2,4,9,15,17,18,19,22,24,25,26,27,30,33,37,39},
				{0,1,2,4,6,7,8,9,11,12,13,14,15,16,20,26,28,29,30,31,32,33,34,35,36,37},
				{0,2,7,15,18,19,20,21,23,24,26,30,39},
				{0,2,3,4,5,7,8,9,11,12,14,15,16,18,21,22,24,26,28,30,31,32,34,35,36,37,39},
				{0,3,7,12,16,18,20,28,34,39},
				{0,2,3,5,7,9,11,13,14,15,16,18,19,20,22,23,24,25,27,28,29,30,31,32,34,35,36,37,38,39},
				{0,5,9,11,22,27,39},
				{0,1,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,37,38,39}	
		};

int coordenadas_keys[] = {12, 0, 0, 8, 33, 39, 39, 32};
int coordenadas_values[] = {0, 1, 34, 39, 39, 36, 2, 0};
int x_coluna;
int x_linha;

int o_coluna;
int o_linha;
void criaCasasAleatorias() {
    srand(time(NULL));
    int randomNumber = rand() % 7;
    tabuleiro[coordenadas_keys[randomNumber]][coordenadas_values[randomNumber]] = "X ";
    x_coluna = coordenadas_keys[randomNumber];
    x_linha = coordenadas_values[randomNumber];

    int a;
    
    do {
        a = rand() % 7;
    } while (a == randomNumber);

    tabuleiro[coordenadas_keys[a]][coordenadas_values[a]] = "O ";
    o_coluna = coordenadas_keys[a];
    o_linha = coordenadas_values[a];

}


void imprimirTabuleiro(){
    
    if(statusMatriz == false){
    for(int i = 0; i < 40; i++) {
			for(int j = 0; j < 40; j++) {
				tabuleiro[i][j] = "  ";
			}
		}
		for(int i = 0; i < 40; i++) {
			for(int j = 0; j < sizeof(mapParede[i]) / sizeof(mapParede[i][0]); j++){
				tabuleiro[i][mapParede[i][j]]= "■ ";
			}
			
		}
        statusMatriz = true;
        //tabuleiro[19][19]= "# ";
        //tabuleiro[19][20]= "# ";
        //tabuleiro[20][19]= "# ";
        //tabuleiro[20][20]= "# ";
        tabuleiro[12][0] = "  ";
        tabuleiro[32][0] = "  ";
        criaCasasAleatorias();
    }else{
//⬤
	if(tabuleiro[19][19] == "X " || tabuleiro[19][20] == "X " || tabuleiro[20][19] == "X " || tabuleiro[20][20] == "X "){
            std::string text = "####################\n# JOGADOR X VENCEU #\n####################\n";
            cout << text;
            ThisThread::sleep_for(5000ms);
            statusMatriz = false;
            imprimirTabuleiro();
        }if(tabuleiro[19][19] == "O " || tabuleiro[19][20] == "O " || tabuleiro[20][19] == "O " || tabuleiro[20][20] == "O "){
            std::string text = "####################\n# JOGADOR O VENCEU #\n####################\n";
            cout << text;
            ThisThread::sleep_for(5000ms);
            statusMatriz = false;
            imprimirTabuleiro();
        }else{
		 std::string text = "";
		for(int i = 0; i < 40; i++) {
			for(int j = 0; j < 40; j++) {
				text += tabuleiro[i][j];
			}
            text += "\n";
		}
        cout << text;
        text = "";
    }
}
}
