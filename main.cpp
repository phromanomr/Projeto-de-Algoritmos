#include <stdio.h>
#include <iostream>
#include "menu.h"

using namespace std;

int main(){
    int tamanho;
    char ordenacao;
    clock_t tempo;
    string caminho;
    int numAlgoritmo;

    numAlgoritmo = algoritmo();

    caminho = tipoAlgoritmo(numAlgoritmo);

    system("cls");

    criarPastas(caminho);

    tamanho = tamanhoVetor();
    system("cls");

    ordenacao = tipoOrdenacao();
    system("cls");

    if(numAlgoritmo == 7){
        vector<int> vetor;

        ordenar_heap(vetor, tamanho, ordenacao);

        entradaHeapArquivo(vetor, vetor.size(), ordenacao, caminho);

        tempo = clock();
        heap_tipes(vetor);
        tempo = clock() - tempo;

        tempoArquivo(tempo, vetor.size(), ordenacao, caminho);

        saidaHeapArquivo(vetor, vetor.size(), ordenacao, caminho);

        cout << "Vetor pos operacao: ";
        print_heap(vetor);
    }else{
        int* vetor = alocaVetor(tamanho);

        ordenar(vetor, tamanho, ordenacao);

        entradaArquivo(vetor, tamanho, ordenacao, caminho);

        tempo = clock();
        executa(numAlgoritmo, vetor, tamanho);
        tempo = clock() - tempo;

        tempoArquivo(tempo, tamanho, ordenacao, caminho);
        saidaArquivo(vetor, tamanho, ordenacao, caminho);

        system("cls");

        printVetor(vetor, tamanho);

        cout << "Vetor ordenado com sucesso!" << endl;

        delete[] vetor;
    }

    return 0;
}