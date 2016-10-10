#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void) {
	contaVertices();
	printf("VERTICES = %d\n", VERTICES);
	contaArestas();
	int menu = -1;
	int **matriz;
	int v = 0;

	while (1) {
		printf("1.\tMostrar matriz.\n2.\tMostrar matriz Adjacencia do");
		printf(" complemento de G\n3.\tMostrar grau do vértice\n");
		printf("4.\tInserir vértice\n5.\tExcluir vértice\n6.\tLiberar matriz\n");
		printf("7.\tDijkstra\n");
		printf("0.\tSair\n\n");
		scanf("%i", &menu);
		switch(menu) {
			case 1:
				printf("\n1.\tIncidência\n2.\tAdjacência\n\n");
				int tipo = 0;
				scanf("%i", &tipo);
				TIPO = tipo;

				int d;
				switch(tipo) {
					case 1: /* Incidencia */

						/* Alocando a matriz */
						contaArestas();
						contaVertices();
						matriz = alocaMatriz(ARESTAS, VERTICES);

						printf("ARESTAS = %d\n", ARESTAS);
						int d = 0;
						printf("\n1.\tDirecionado\n2.\tNão direcionado\n\n");
						scanf("%d", &d);
						DIRECIONADO = d;
						openFileGrafoId(matriz, d);
						mostrarMatrizId(matriz);
						break;
					case 2:	/* Adjacencia */
						contaVertices();
						matriz = alocaMatriz(VERTICES, VERTICES);
						do {

							printf("\n1.\tDirecionado\n2.\tNão direcionado.\n\n");
							scanf("%i", &d);
							DIRECIONADO = d;



							if(d == 2 || d == 1) {
								openFileGrafoAd(matriz, d);
								printf("TAMANHO: %i\n", VERTICES);

								mostrarMatrizAd(matriz);

							} else {
								printf("Invalido.\n");
							}
						} while(d != 2 && d != 1);
						break;


					default:
						printf("Opção inválida.\n");
						break;
				}
				break;

				case 2: /* Mostrar matriz adjacencia do Complemento de G */
					if (DIRECIONADO == 2 && TIPO == 2 && matriz != NULL) matrAdjComplemento(matriz);
					/* Só mostra a matriz Adj. caso seja não-direcionado, adjacencia e a matriz não seja nula. */
					break;
				case 3:
					printf("\nEscolha um vértice.\n");
					scanf("%i", &v);
					printf("\nGrau do vértice %i = %i\n", v, calculaGrau(v, matriz));
					break;
				case 4:
					if (TIPO == 1 && matriz != NULL) insercaoId(matriz, DIRECIONADO);
					if (TIPO == 2 && matriz != NULL) insercaoAd(matriz, DIRECIONADO);
					break;
				case 5:
					if (TIPO == 1 && matriz != NULL) exclusaoId(matriz, DIRECIONADO);
					if (TIPO == 2 && matriz != NULL) exclusaoAd(matriz, DIRECIONADO);
					break;
				case 6:
					if (matriz != NULL) matriz = liberaMatriz(matriz);
					break;
				case 7:
					printf("Selecione um vértice de origem.\n");

					int *dij = NULL;
					scanf("%i", &v);
					if (matriz != NULL) dij = dijkstra(matriz, v);
					int j = 0;
					for (; j < VERTICES; j++) printf("%d\n", dij[j]);
					free(dij);
					break;
				case 0:
					return 0;
				default:
					printf("Opção inválida.\n");
		}
	}


	return 0;
}
