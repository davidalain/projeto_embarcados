#include "mbed.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include "tabuleiro.h"

typedef struct jogador {
    AnalogIn cord_x;
    AnalogIn cord_y;
} jogador;

jogador jogador1 = {PA_0, PA_1};
jogador jogador2 = {PA_4, PB_0};
  
Thread th_jogador1;
Thread th_jogador2;
void thread_mover_jogador1(){
    while(1)
    
    if(jogador1.cord_x.read_u16() <= 40000){
           if(tabuleiro[x_coluna - 1][x_linha] == "  "){
               tabuleiro[x_coluna - 1][x_linha] = "X ";
               tabuleiro[x_coluna][x_linha] = "  ";
               x_coluna = x_coluna - 1;
               ThisThread::sleep_for(500ms);
           }
    }else if(jogador1.cord_x.read_u16() >= 53000){
           if(tabuleiro[x_coluna + 1][x_linha] == "  "){
               tabuleiro[x_coluna + 1][x_linha] = "X ";
               tabuleiro[x_coluna][x_linha] = "  ";
               x_coluna = x_coluna + 1;  
               ThisThread::sleep_for(500ms);
           }
    }
    else if(jogador1.cord_y.read_u16() <= 40000){
           if(tabuleiro[x_coluna][x_linha + 1] == "  "){
               tabuleiro[x_coluna][x_linha + 1] = "X ";
               tabuleiro[x_coluna][x_linha] = "  ";
               x_linha = x_linha + 1;
                ThisThread::sleep_for(500ms);
           }
    }else if(jogador1.cord_y.read_u16() >= 53000){
           if(tabuleiro[x_coluna][x_linha - 1] == "  "){
               tabuleiro[x_coluna][x_linha - 1] = "X ";
               tabuleiro[x_coluna][x_linha] = "  ";
               x_linha = x_linha - 1;
                ThisThread::sleep_for(500ms);
           }
    }
}

void thread_mover_jogador2(){
    while(1)
    if(jogador2.cord_x.read_u16() <= 40000){
           if(tabuleiro[o_coluna - 1][o_linha] == "  "){
               tabuleiro[o_coluna - 1][o_linha] = "O ";
               tabuleiro[o_coluna][o_linha] = "  ";
               o_coluna = o_coluna - 1;
               ThisThread::sleep_for(500ms);
           }
    }else if(jogador2.cord_x.read_u16() >= 53000){
           if(tabuleiro[o_coluna + 1][o_linha] == "  "){
               tabuleiro[o_coluna + 1][o_linha] = "O ";
               tabuleiro[o_coluna][o_linha] = "  ";
               o_coluna = o_coluna + 1;
               ThisThread::sleep_for(500ms);
           }
    }
    else if(jogador2.cord_y.read_u16() <= 40000){
           if(tabuleiro[o_coluna][o_linha + 1] == "  "){
               tabuleiro[o_coluna][o_linha + 1] = "O ";
               tabuleiro[o_coluna][o_linha] = "  ";
               o_linha = o_linha + 1;
               ThisThread::sleep_for(500ms);
           }
    }else if(jogador2.cord_y.read_u16() >= 53000){
           if(tabuleiro[o_coluna][o_linha - 1] == "  "){
               tabuleiro[o_coluna][o_linha - 1] = "O ";
               tabuleiro[o_coluna][o_linha] = "  ";
               o_linha = o_linha - 1;
               ThisThread::sleep_for(500ms);
           }
    }
}