#define LISTA_H
#define ERRO_LISTA_VAZIA -1
#define ERRO_POSICAOINVALIDA -2
typedef struct ele{
    void *info;
    struct ele *proximo;
}Elemento;
typedef struct{
    int tamInfo;
    Elemento *cabeca;
}Lista;
void inicializa_lista(Lista *l, int t);
int lista_vazia(Lista l);
int insereNoInicio(Lista *l, void * x);
int removeDoInicio(Lista *l,void *info);
Elemento* aloca_elemento(int tamInfo, void *info);
void mostraLista(Lista l, void (*mostra_info)(void*));
int insereNoFim(Lista *l, void * x);
int removeDoFim(Lista *l,void *info);
int insereNaPosicao(Lista *l, void *info, int pos);
int removeDaPosicao(Lista *l, void *info, int pos);
int insereEmOrdem(Lista *l, void *info, int (*compara)(void*, void*));
int retorna_pos(Lista l, void *info, int (*compara)(void*, void*));

/* Fazer: removeDaPosicao(&l1, &x, 3);
 *		  modificaNaPosicao(&l1, &x, 2);
 *		  	-> p chega na posicão (e não na pos-1) e é feito um memcpy. (memcpy info -> p->info)
 *		  leNaPosicao(&l1, &x, 2);										(memcpy p->info -> info)
 *			-> p chega na posição e o valor é copiado p/ info.
 */
