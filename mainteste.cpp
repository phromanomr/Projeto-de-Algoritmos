#include <iostream>
#include <vector>

using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    if (i == 0) {
        return 1;
    } else {
        return 2 * i;
    }
}

int right(int i) {
    if (i == 0) {
        return 2;
    } else {
        return 2 * i + 1;
    }
}

void min_heapify(vector<int> &vetor,  int tamanho, int i) {
    int menor = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l <= tamanho && vetor[l] < vetor[i]) {
        menor = l;
    }
    if (r <= tamanho && vetor[r] < vetor[menor]) {
        menor = r;
    }
    if (menor != i) {
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

void heapSort(vector<int> &vetor) {
    build_min_heap(vetor);
    int tamanho = vetor.size() - 1;
    for (int i = vetor.size() - 1; i > 0; i--) {
        swap(vetor[0], vetor[i]);
        tamanho--;
        min_heapify(vetor, tamanho, 0);
    }
}

int main() {
    vector<int> vetor = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    heapSort(vetor);
    for (int i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    return 0;
}
