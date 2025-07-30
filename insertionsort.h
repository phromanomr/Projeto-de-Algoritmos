#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <time.h>      
#include <ctype.h>     //tipografia, colocar as letras em minusculo
#include <cstdio>      //remove
#include <windows.h>   //criar pastas

using namespace std;

void insertion_sort(int vetor[], int tamanho){
    int chave, i;

    for(int j = 1; j < tamanho; j++){
        chave = vetor[j];
        i = j - 1;
        while(i >= 0 && vetor[i] > chave){
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = chave;
    }
}

void bubble_sort(int vetor[], int tamanho){
    int chave;

    for(int i = 1; i < (tamanho - 1); i++){
        for(int j = 0; j < (tamanho - i); j++){
            if(vetor[j] > vetor[j + 1]){
                chave = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = chave;
            }
        }
    }
}

void selection_sort(int vetor[], int tamanho){
    int aux, chave;
    for(int i = 0; i < tamanho; i++){
        aux = i;
        for(int j = (i + 1); j < tamanho; j++){
            if(vetor[j] < vetor[aux]){
                aux = j;
            }
        }
        chave = vetor[i];
        vetor[i] = vetor[aux];
        vetor[aux] = chave;
    }
}

void shell_sort(int vetor[], int tamanho){
    for (int gap = tamanho/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < tamanho; i += 1)
        {
            int temp = vetor[i];
            int j;            
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap)
                vetor[j] = vetor[j - gap];
            vetor[j] = temp;
        }
    }
}

int algoritmo(){
    int tipoAlgoritmo = 0;

    do{
    cout << "Insira o Algoritmo de Ordenacao que deseja utilizar:" << endl << endl;
    cout << "1 - Insertion Sort" << endl << "2 - Bubble Sort" << endl << "3 - Selection Sort" << endl << "4 - Shell Sort" << endl << endl;

    cin >> tipoAlgoritmo;

    if(tipoAlgoritmo <= 0 || tipoAlgoritmo > 4){
        cout << "Insira um valor valido!";
        system("pause");
        system("cls");
    }

    }while(tipoAlgoritmo <= 0 || tipoAlgoritmo > 4);

    return tipoAlgoritmo;
}

string tipoAlgoritmo(int numAlgoritmo){
    string caminho;

    switch(numAlgoritmo)
    {
    case 1:
        caminho = "../insertion-sort";
        break;

    case 2:
        caminho = "../bubble-sort";
        break;
    
    case 3:
        caminho = "../selection-sort";
        break;
    
    case 4:
        caminho = "../shell-sort";
        break;
    
    default:
        break;
    }

    return caminho;
}

int tamanhoVetor(){
    int escolha;
    int tamanho;

    cout << "insira o tamanho do vetor:" << endl << endl << "Tamanho 10 - 1" << endl << "Tamanho 100 - 2" << endl << "Tamanho 1000 - 3" << endl << "Tamanho 10000 - 4" << endl << "Tamanho 100000 - 5" << endl << "Tamanho 1000000 - 6" << endl << endl;
    cin >> escolha;
    while(escolha < 1 || escolha > 6){
        cout << "Insira um numero valido!" << endl;
        cin >> escolha;
    }
    
    switch(escolha){
        case 1:
            tamanho = 10;
        break;
        case 2:
            tamanho = 100;
        break;
        case 3:
            tamanho = 1000;
        break;
        case 4:
            tamanho = 10000;
        break;
        case 5:
            tamanho = 100000;
        break;
        default:
            tamanho = 1000000;
    }

    return tamanho;
}

char tipoOrdenacao(){
    char ordenacao;
    do{
    cout << "Insira como o vetor sera ordenado:" << endl << endl << "Ordem crescente - c" << endl << "Ordem decrescente - d"  << endl << "Aleatorio - a" << endl << endl;
    cin >> ordenacao;
    ordenacao = tolower(ordenacao);
    }while(ordenacao != 'c' && ordenacao != 'd' && ordenacao != 'a');

    return ordenacao;
}

void ordenar(int *vetor, int tamanho, char ordenacao){
    switch(ordenacao){
        case 'c':
            ordenaCrescente(vetor, tamanho);
        break;
        case 'd':
            ordenaDecrescente(vetor, tamanho);
        break;
        default:
            ordenaAleatorio(vetor, tamanho);
    }
}

void executa(int numAlgoritmo, int vetor[], int tamanho){
        switch(numAlgoritmo)
    {
    case 1:
            insertion_sort(vetor, tamanho);
        break;

    case 2:
            bubble_sort(vetor, tamanho);
        break;
    
    case 3:
            selection_sort(vetor, tamanho);
        break;
    
    case 4:
            shell_sort(vetor, tamanho);
        break;
    
    default:
        break;
    }
}

void printVetor(int vetor[], int tamanho){
    int i;
    cout << endl << endl << "vetor ordenado = {";
    for(i = 0; i < tamanho - 1; i++){
        cout << vetor[i] << ", ";
    }
    cout << vetor[i] << "}" << endl << endl;
}

int random(int low, int high)
{
    return low + rand() % (high - low + 1);
}

int* alocaVetor(int tamanho){
    int* vetor = new int[tamanho];
    return vetor;
}



void criarPastas(string caminho){
    
    CreateDirectoryA(caminho.c_str(), NULL);

    cout << caminho;

    system("pause");

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

#endif