/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include "jogador.h"
int main(){

    BufferedSerial pc(USBTX, USBRX, 460800);
    th_jogador1.start(callback(thread_mover_jogador1));
    th_jogador2.start(callback(thread_mover_jogador2));

        while(1){
        imprimirTabuleiro();
        std::cout << "\033[2J\033[H";
        ThisThread::sleep_for(500ms);
        }
}