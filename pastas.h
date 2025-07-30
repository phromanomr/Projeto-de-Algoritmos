#ifndef PASTAS_H
#define PASTAS_H

#include <stdio.h>
#include <iostream>
#include <string>    
#include <fstream>
#include <ctype.h>
#include <time.h> 
#include <ctime>
#include <windows.h>   //criar pastas

#include "algoritmos.h"

using namespace std;


void criarPastas(string caminho){
    
    CreateDirectoryA(caminho.c_str(), NULL);

    CreateDirectoryA((caminho + "/aleatorio").c_str(), NULL);
    CreateDirectoryA((caminho + "/aleatorio/entrada").c_str(), NULL);
    CreateDirectoryA((caminho + "/aleatorio/saida").c_str(), NULL);
    CreateDirectoryA((caminho + "/aleatorio/tempo").c_str(), NULL);

    CreateDirectoryA((caminho + "/crescente").c_str(), NULL);
    CreateDirectoryA((caminho + "/crescente/entrada").c_str(), NULL);
    CreateDirectoryA((caminho + "/crescente/saida").c_str(), NULL);
    CreateDirectoryA((caminho + "/crescente/tempo").c_str(), NULL);

    CreateDirectoryA((caminho + "/decrescente").c_str(), NULL);
    CreateDirectoryA((caminho + "/decrescente/entrada").c_str(), NULL);
    CreateDirectoryA((caminho + "/decrescente/saida").c_str(), NULL);
    CreateDirectoryA((caminho + "/decrescente/tempo").c_str(), NULL);
}

void entradaArquivo(int vetor[], int tamanho, char ordenacao, string caminho){
    int i;
    ofstream arquivo;
    string caminhoDefinitivo;
    if(ordenacao == 'a'){
        caminhoDefinitivo = string(caminho) + "/aleatorio/entrada/entrada-aleatoria" + to_string(tamanho) + ".txt";
    }else if(ordenacao == 'c'){
        caminhoDefinitivo = string(caminho) + "/crescente/entrada/entrada-crescente" + to_string(tamanho) + ".txt";
    }else{
        caminhoDefinitivo = string(caminho) + "/decrescente/entrada/entrada-decrescente" + to_string(tamanho) + ".txt";
    }

    remove(caminhoDefinitivo.c_str());
    arquivo.open(caminhoDefinitivo, ios::app);
    arquivo << to_string(tamanho);
    arquivo << endl << "{";
    for(i = 0; i < tamanho - 1; i++){
        arquivo << vetor[i] << ", ";
    }
    arquivo << vetor[i] << "}";
    
    arquivo.close();
}

void saidaArquivo(int vetor[], int tamanho, char ordenacao, string caminho){
    int i;
    ofstream arquivo;
    string caminhoDefinitivo;
    if(ordenacao == 'a'){
        caminhoDefinitivo = string(caminho) + "/aleatorio/saida/saida-aleatoria" + to_string(tamanho) + ".txt";
    }else if(ordenacao == 'c'){
        caminhoDefinitivo = string(caminho) + "/crescente/saida/saida-crescente" + to_string(tamanho) + ".txt";
    }else{
        caminhoDefinitivo = string(caminho) + "/decrescente/saida/saida-decrescente" + to_string(tamanho) + ".txt";
    }

    remove(caminhoDefinitivo.c_str());
    arquivo.open(caminhoDefinitivo, ios::app);

    arquivo << to_string(tamanho);
    arquivo << endl << "{";
    for(i = 0; i < tamanho - 1; i++){
        arquivo << vetor[i] << ", ";
    }
    arquivo << vetor[i] << "}";

    arquivo.close();
}

void tempoArquivo(clock_t tempo, int tamanho, char ordenacao, string caminho){
    ofstream arquivo;
    string caminhoDefinitivo;
    if(ordenacao == 'a'){
        caminhoDefinitivo = string(caminho) + "/aleatorio/tempo/tempo-aleatoria" + to_string(tamanho) + ".txt";
    }else if(ordenacao == 'c'){
        caminhoDefinitivo = string(caminho) + "/crescente/tempo/tempo-crescente" + to_string(tamanho) + ".txt";
    }else{
        caminhoDefinitivo = string(caminho) + "/decrescente/tempo/tempo-decrescente" + to_string(tamanho) + ".txt";
    }

    remove(caminhoDefinitivo.c_str());
    arquivo.open(caminhoDefinitivo, ios::app);

    arquivo << to_string(tamanho);
    arquivo << endl;

    arquivo << (float)tempo/CLOCKS_PER_SEC << " segundos";

    arquivo.close();
}

void ordenaCrescente(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = i + 1;
    }
}

void ordenaDecrescente(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = tamanho - i;
    }
}

void ordenaAleatorio(int *vetor, int tamanho){
    srand(time(NULL));
    
    for(int i = 0; i < tamanho; i++){
        vetor[i] = random(0, 9999999);
    }
}

void ordenaHeapCrescente(vector<int> &vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor.push_back(i+1);
    }
}

void ordenaHeapDecrescente(vector<int> &vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor.push_back(tamanho-i);
    }
}

void ordenaHeapAleatorio(vector<int> &vetor, int tamanho){
    srand(time(NULL));
    
    for(int i = 0; i < tamanho; i++){
        vetor.push_back(random(0, 9999999));
    }
}

void entradaHeapArquivo(vector<int> &vetor, int tamanho, char ordenacao, string caminho){
    int i;
    ofstream arquivo;
    string caminhoDefinitivo;
    if(ordenacao == 'a'){
        caminhoDefinitivo = string(caminho) + "/aleatorio/entrada/entrada-aleatoria" + to_string(tamanho) + ".txt";
    }else if(ordenacao == 'c'){
        caminhoDefinitivo = string(caminho) + "/crescente/entrada/entrada-crescente" + to_string(tamanho) + ".txt";
    }else{
        caminhoDefinitivo = string(caminho) + "/decrescente/entrada/entrada-decrescente" + to_string(tamanho) + ".txt";
    }

    remove(caminhoDefinitivo.c_str());
    arquivo.open(caminhoDefinitivo, ios::app);
    arquivo << to_string(tamanho);
    arquivo << endl << "{";
    for(i = 0; i < tamanho - 1; i++){
        arquivo << vetor[i] << ", ";
    }
    arquivo << vetor[i] << "}";
    
    arquivo.close();
}

void saidaHeapArquivo(vector<int> &vetor, int tamanho, char ordenacao, string caminho){
    int i;
    ofstream arquivo;
    string caminhoDefinitivo;
    if(ordenacao == 'a'){
        caminhoDefinitivo = string(caminho) + "/aleatorio/saida/saida-aleatoria" + to_string(tamanho) + ".txt";
    }else if(ordenacao == 'c'){
        caminhoDefinitivo = string(caminho) + "/crescente/saida/saida-crescente" + to_string(tamanho) + ".txt";

    }else{
        caminhoDefinitivo = string(caminho) + "/decrescente/saida/saida-decrescente" + to_string(tamanho) + ".txt";
    }

    remove(caminhoDefinitivo.c_str());
    arquivo.open(caminhoDefinitivo, ios::app);

    arquivo << to_string(tamanho);
    arquivo << endl << "{";
    for(i = 0; i < tamanho - 1; i++){
        arquivo << vetor[i] << ", ";
    }
    arquivo << vetor[i] << "}";

    arquivo.close();
}


#endif