#ifndef _GRAFO_H
#define _GRAFO_H
#define INF 9999999

int VERTICES;
int ARESTAS;
int TIPO;
int DIRECIONADO;

void contaVertices();

void contaArestas();

/* Abrir arquivo com as relações da matriz de adjacencia não direcionada */
void openFileGrafoAd(int **matriz, int direcionado);

void openFileGrafoId(int **matriz, int direcionado);

/* Função para calcular o grau de um vértice do grafo */
int calculaGrau(int vertice, int **vetor);
void mostrarMatrizAd(int **matriz);
void mostrarMatrizId(int **matriz);

void excluiVerticeAd(int no);

int **alocaMatriz(int linhas, int colunas);
int **liberaMatriz(int **matriz);
void insereNoAd();
void exclusaoAd(int **matriz, int d);
void insercaoAd(int **matriz, int d);
void exclusaoId(int **matriz, int d);
void insercaoId(int **matriz, int d);
void matrAdjComplemento(int **matriz);
int fleury(int **matriz, int v);
int *dijsktra(int **matriz, int origem);
int esta_no_vetor(int *vetor, int vertice);
int verifica_vetor_cheio(int *vetor);


#endif
