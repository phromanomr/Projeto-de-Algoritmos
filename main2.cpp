#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
      *a = *b;
      *b = tmp;
}

void min_heapify(vector<int> &vetor, int tamanho, int i){
    int l = 2*i+1, r = 2*i+2;
    int menor = i;

    if(l < tamanho && vetor[l] < vetor[menor]){
        menor = l;
    }

    if(r < tamanho && vetor[r] < vetor[menor]){
        menor = r;
    }

    if(menor != i){
        swap(vetor[i], vetor[menor]);
        min_heapify(vetor, tamanho, menor);
    }
}

void build_min_heap(vector<int> &vetor){
    for(int i = (vetor.size()/2) - 1; i >= 0; i--){
        min_heapify(vetor, vetor.size()-1, i);
    }
}

void print_min_heap(vector<int> &vetor){
    build_min_heap(vetor);
    cout << "Menor numero: " << vetor[0] << endl;
}

void heapSort(vector<int> &vetor){
    build_min_heap(vetor);

    for(int i = vetor.size()-1; i >= 0; i--){
        swap(vetor[0], vetor[i]);
        min_heapify(vetor, i, 0);


        /*for(int j = 0; j<10; j++){
            if(j == 9){
                cout << vetor[j] << endl;
            }else{
                cout << vetor[j] << ", ";
            }
        }*/
    }
}

void heap_extract_min(vector<int> &vetor){
    build_min_heap(vetor);
    int menor = vetor[0];
    
    swap(vetor[0], vetor[vetor.size()-1]);
    vetor.pop_back();
    min_heapify(vetor, vetor.size(), 0);
    cout << menor << endl;
}

void heap_increase_min(vector<int> &vetor, int posicao){
    build_min_heap(vetor);
    vetor[posicao] = 1000;
    min_heapify(vetor, vetor.size(), 0);
}

void max_heap_insert(vector<int> &vetor){
    build_min_heap(vetor);
    vetor.push_back(1000);
    min_heapify(vetor, vetor.size(), 0);
}

void heap_minimum(vector<int> &vetor){
    build_min_heap(vetor);
    cout << "Menor elemento: " << vetor[0];
}

int main(){

    vector<int> vet;
    int t = 10;

    /*heapSort(vet);*/

    /*cout << "Antes :";

    for(int i = 0; i<t; i++){
        if(i == t-1){
            cout << vet[i] << endl;
        }else{
            cout << vet[i] << " ";
        }
    }*/

    /*heapSort(vet);*/
    /*heap_extract_min(vet);*/
    /*max_heap_insert(vet);*/
    /*heap_increase_min(vet, 0);*/

    /*cout << "Depois: " << t << endl;*/

    for(int i = 0; i<vet.size(); i++){
        if(i == vet.size()-1){
            cout << vet[i] << endl;
        }else{
            cout << vet[i] << " ";
        }
    }

    return 0;
}