#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct NoHuffman {
    char caractere; 
    unsigned frequencia;
    NoHuffman *esquerda, *direita;

    NoHuffman(char caractere, unsigned frequencia) {
        this->caractere = caractere;
        this->frequencia = frequencia;
        esquerda = direita = nullptr;
    }
};

struct comparar {
    bool operator()(NoHuffman* l, NoHuffman* r) {
        return (l->frequencia > r->frequencia);
    }
};

void imprimirFrequencias(const std::string& texto) {
    std::map<char, int> frequencias;

    for (char c : texto) {
        frequencias[c]++;
    }

    for (const auto& par : frequencias) {
        std::cout << "Caractere: " << par.first << ", Frequência: " << par.second << std::endl;
    }
}

void imprimirCodigos(NoHuffman* raiz, string str, map<char, string> &codigoCaracteres) {
    if (!raiz) return;

    if (raiz->caractere != ' ') {
        cout << raiz->caractere << ": " << str << "\n";
        codigoCaracteres[raiz->caractere] = str;
    }

    imprimirCodigos(raiz->esquerda, str + "0", codigoCaracteres);
    imprimirCodigos(raiz->direita, str + "1", codigoCaracteres);
}

void construirEHuffman(string texto) {
    map<char, unsigned> frequencias;
    for (char c : texto)
        frequencias[c]++;

    priority_queue<NoHuffman*, vector<NoHuffman*>, comparar> minHeap;

    for (auto par : frequencias)
        minHeap.push(new NoHuffman(par.first, par.second));

    while (minHeap.size() != 1) {
        NoHuffman *esquerda = minHeap.top(); minHeap.pop();
        NoHuffman *direita = minHeap.top(); minHeap.pop();

        NoHuffman *topo = new NoHuffman(' ', esquerda->frequencia + direita->frequencia);
        topo->esquerda = esquerda;
        topo->direita = direita;

        minHeap.push(topo);
    }

    imprimirFrequencias(texto);
    cout << "\n" << endl;

    map<char, string> codigoCaracteres;

    imprimirCodigos(minHeap.top(), "", codigoCaracteres);
    
    unsigned tamanhoOriginal = texto.length() * 8; 
    unsigned tamanhoComprimido = 0;
    for (char c : texto) {
        tamanhoComprimido += codigoCaracteres[c].length();
    }
    cout << "Taxa de compressão: " << static_cast<double>(tamanhoComprimido) / tamanhoOriginal << endl;
}

int main() {
    string texto = "exemplo de texto para compressao usando huffman";
    cout << "Texto original: " << texto << endl;
    cout << "\n" << endl;
    construirEHuffman(texto);

    return 0;
}
