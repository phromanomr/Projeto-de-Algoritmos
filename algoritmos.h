#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
      *a = *b;
      *b = tmp;
}

void print_heap(vector<int> &vetor){
        for(int i = 0; i<vetor.size(); i++){
        if(i == vetor.size()-1){
            cout << vetor[i] << endl;
        }else{
            cout << vetor[i] << " ";
        }
    }
}

void min_heapify(vector<int> &vetor, int tamanho, int i){
    int l = 2*i+1, r = 2*i+2;
    int menor = i;

    if(l <= tamanho && vetor[l] < vetor[menor]){
        menor = l;
    }

    if(r <= tamanho && vetor[r] < vetor[menor]){
        menor = r;
    }

    if(menor != i){
        swap(vetor[i], vetor[menor]);
        min_heapify(vetor, tamanho, menor);
    }
}

void build_min_heap(vector<int> &vetor) {
    int tamanho = vetor.size() - 1;
    for (int i = (vetor.size() - 1) / 2; i >= 0; i--) {
        min_heapify(vetor, tamanho, i);
    }
}

void heap_minimum(vector<int> &vetor){
    build_min_heap(vetor);
    cout << "Menor elemento: " << vetor[0] << endl;
}

void heapSort(vector<int> &vetor) {
    build_min_heap(vetor);
    int tamanho = vetor.size() - 1;
    for (int i = vetor.size() - 1; i > 0; i--) {
        swap(vetor[0], vetor[i]);
        tamanho--;
        min_heapify(vetor, tamanho, 0);
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

int random(int low, int high)
{
    return low + rand() % (high - low + 1);
}

void troca(int vetor[], int i, int j){
    int chave = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = chave;
}

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
        for (int i = gap; i < tamanho; i ++)
        {
            int temp = vetor[i];
            int j;            
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap)
                vetor[j] = vetor[j - gap];
            vetor[j] = temp;
        }
    }
}

int partition(int vetor[], int p, int r){
    int q = vetor[p];
    int i = p-1;
    int j = r+1;
    
    while(true){
        do{
            j--;
        }while(vetor[j] > q);
        do{
            i++;
        }while(vetor[i] < q);
        if(i < j){
            troca(vetor, i, j);
        }else{
            return j;
        }
    }
}

void quick_sort(int vetor[], int p, int r){
    if(p < r){
        int q = partition(vetor, p, r);
        quick_sort(vetor, p, q-1);
        quick_sort(vetor, q+1, r);
    }
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1], *M = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] < M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void merge_sort(int vetor[], int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(vetor, p, q);
        merge_sort(vetor, q+1, r);
        merge(vetor, p, q, r);
    }
}

int middle_partition(int vetor[], int p, int r){
    int i;

    if(p == 0){
        i = (1+r)/2;
    }else{
        i = (p+r)/2;
    }

    troca(vetor, p, i);
    return partition(vetor, p, r);
}

void middle_quicksort(int vetor[], int p, int r){
    if(p<r){
        int q = middle_partition(vetor, p, r);
        middle_quicksort(vetor, p, q-1);
        middle_quicksort(vetor, q+1, r);
    }
}

int median_partition(int vetor[], int p, int r){
    int i, med;

    if(p == 0){
        i = (1+r)/2;
    }else{
        i = (p+r)/2;
    }

    if(vetor[p] < vetor[i]){
        if(vetor[i] < vetor[r]){
            med = i;
        }else if(vetor[p] < vetor[r]){
            med = r;
        }else{
            med = p;
        }
    }else if(vetor[r] < vetor[i]){
        med = i;
    }else if(vetor[r] < vetor[p]){
        med = r;
    }else{
        med = p;
    }

    troca(vetor, p, med);
    return partition(vetor, p, r);
}

void median_quicksort(int vetor[], int p, int r){
    if(p<r){
        int q = median_partition(vetor, p, r);
        median_quicksort(vetor, p, q-1);
        median_quicksort(vetor, q+1, r);
    }
}

int random_partition(int vetor[], int p, int r){
    int i = random(p, r);
    troca(vetor, r, i);
    return partition(vetor, p, r);
}

void random_quicksort(int vetor[], int p, int r){
    if(p<r){
        int q = random_partition(vetor, p, r);
        random_quicksort(vetor, p, q-1);
        random_quicksort(vetor, q+1, r);
    }
}

#endif