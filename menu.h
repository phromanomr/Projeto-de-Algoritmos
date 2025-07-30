#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <random>    
#include <ctype.h>     //tipografia, colocar as letras em minusculo

#include "pastas.h"


using namespace std;


int algoritmo(){
    int escolha = 0;

    do{
    cout << "Insira o Algoritmo de Ordenacao que deseja utilizar:" << endl << endl;
    cout << "1 - Insertion Sort" << endl << "2 - Bubble Sort" << endl << "3 - Selection Sort" << endl << "4 - Shell Sort" << endl << "5 - Merge Sort" << endl << "6 - Quick Sort" << endl << "7 - Heap Sort" << endl << endl;

    cin >> escolha;

    if(escolha <= 0 || escolha > 7){
        cout << "Insira um valor valido!";
        system("pause");
        system("cls");
    }

    }while(escolha <= 0 || escolha > 7);

    return escolha;
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

    case 5:
        caminho = "../merge-sort";
        break;

    case 6:
        caminho = "../quick-sort";
        break;

    case 7:
        caminho = "../heap-sort";
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

void ordenar_heap(vector<int> &vetor, int tamanho, char ordenacao){
    switch(ordenacao){
        case 'c':
            ordenaHeapCrescente(vetor, tamanho);
        break;
        case 'd':
            ordenaHeapDecrescente(vetor, tamanho);
        break;
        default:
            ordenaHeapAleatorio(vetor, tamanho);
    }
}

void quick_tipes(int vetor[], int tamanho){
    int escolha;

    do{
        cout << "Insira a versão desejada do Quick Sort:" << endl << endl;
        cout << "1 - V1(Pivo no inicio)" << endl << "2 - V2(Media)" << endl << "3 - V3(Mediana)" << endl << "4 - V4(Randomizado)" << endl;

        cin >> escolha;

        if(escolha <= 0 || escolha > 4){
            cout << "Insira um valor valido!";
            system("pause");
            system("cls");
        }
    }while(escolha <= 0 || escolha > 4);

    switch(escolha)
    {
    case 1:
        quick_sort(vetor, 0, tamanho);
        break;
    
    case 2:
        middle_quicksort(vetor, 0, tamanho);
        break;

    case 3:
        median_quicksort(vetor, 0, tamanho);
        break;

    case 4:
        random_quicksort(vetor, 0, tamanho);
        break;

    default:
        break;
    }
}

int heapPosition(int tamanho){
    int resultado = -1;
    do{
        cout << "Em que posicao voce deseja adicionar o numero 1000?(0, " << tamanho << ")" << endl;
        cin >> resultado;
        if(resultado < 0 || resultado > tamanho){
            cout << "Insira uma posicao valida!" << endl << endl;
        }
    }while(resultado < 0 || resultado > tamanho);

    return resultado;
}

void heap_tipes(vector<int> &vetor){
    int escolha;

    do{
        cout << "Insira a versão desejada do Quick Sort:" << endl << endl;
        cout << "1 - Heap Sort" << endl << "2 - Heap Minimo" << endl << "3 - Heap Extract Min" << endl << "4 - Heap Increase" << endl << "5 - Heap Insert" << endl;

        cin >> escolha;

        if(escolha <= 0 || escolha > 5){
            cout << "Insira um valor valido!";
            system("pause");
            system("cls");
        }
    }while(escolha <= 0 || escolha > 5);

        /*cout << endl <<"Vetor original: ";
        print_heap(vetor);*/

    switch(escolha)
    {
    case 1:
        heapSort(vetor);
        break;
    
    case 2:
        heap_minimum(vetor);
        break;

    case 3:
        heap_extract_min(vetor);
        break;

    case 4:
        heap_increase_min(vetor, heapPosition(vetor.size()));
        break;

    case 5:
        max_heap_insert(vetor);
        break;

    default:
        break;
    }

    /*cout << "Vetor pos operacao: ";
    print_heap(vetor);*/
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

    case 5:
            merge_sort(vetor, 0, tamanho);
        break;

    case 6:
            quick_tipes(vetor, tamanho);
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

int* alocaVetor(int tamanho){
    int* vetor = new int[tamanho];
    return vetor;
}


#endif