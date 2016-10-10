#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa_lista(Lista *l, int t){
    l->tamInfo = t;
    l->cabeca = NULL;
}
int lista_vazia(Lista l){
    return l.cabeca == NULL;
}
int insereNoInicio(Lista *l, void * x){
    Elemento *e = aloca_elemento(l->tamInfo,x);
    if(e==NULL){
        return 0;//FRACASSO
    }
    e->proximo = l->cabeca;
    l->cabeca = e;
    return 1;
}
int insereNoFim(Lista *l, void * x){
    if(lista_vazia(*l)){
        return insereNoInicio(l,x);
    }
    Elemento *e = aloca_elemento(l->tamInfo,x);
    if(e==NULL){
        return 0;//FRACASSO
    }
    Elemento* e1 = l->cabeca;
    while(e1->proximo != NULL){
        e1 = e1->proximo;
    }
    e1->proximo = e;
    e->proximo = NULL;
    return 1;
}
Elemento* aloca_elemento(int tamInfo, void *info){
    Elemento *e=malloc(sizeof(Elemento));
    if(e == NULL){
        return NULL;
    }
    e->info = malloc(tamInfo);
    if(e->info == NULL){
        free(e);
        return NULL;
    }
    memcpy(e->info,info,tamInfo);
    return e;
}
int removeDoInicio(Lista *l,void *info){
    if(lista_vazia(*l)){
        return ERRO_LISTA_VAZIA;
    }
    Elemento *e1 = l->cabeca;
    memcpy(info,e1->info,l->tamInfo);
    l->cabeca = e1->proximo;
    free(e1->info);
    free(e1);
    return 1;
}
int removeDoFim(Lista *l,void *info){
    if(lista_vazia(*l)){
        return ERRO_LISTA_VAZIA;
    }
    if(l->cabeca->proximo == NULL){
        return removeDoInicio(l,info); //Apenas 1 elemento
    }
    Elemento *e = l->cabeca;
    memcpy(info,e->info,l->tamInfo);
    l->cabeca = e->proximo;
    free(e->info);
    free(e);
    return 1;
}
void mostraLista(Lista l, void (*mostra_info)(void*)){
    if(lista_vazia(l)){
       printf("Lista vazia\n");
    }else{
        Elemento* e = l.cabeca;
        while(e != NULL){
            mostra_info(e->info);
            e = e->proximo;
        }
        printf("\n");
    }
}

int insereNaPosicao(Lista *l, void *info, int pos) {
    if(pos < 0) return ERRO_POSICAOINVALIDA;
    if (pos == 0) {  
      return insereNoInicio(l, info);  
    }
    if (lista_vazia(*l)) return ERRO_POSICAOINVALIDA; 
    Elemento *p = l->cabeca;
    int cont = 0;
    while (cont < pos-1 && p->proximo != NULL) {
        p = p->proximo;
        cont++;
    }
    if (cont != pos-1) return ERRO_POSICAOINVALIDA;
    Elemento *novo = aloca_elemento(l->tamInfo, info);
    if (novo == NULL) return 0; // Fracasso
    novo->proximo = p->proximo;
    p->proximo = novo;
    return 1; // Sucesso
}

int removeDaPosicao(Lista *l, void *info, int pos);

int insereEmOrdem(Lista *l, void *info, int (*compara)(void*, void*)) {
    int cont = 0;
    Elemento *p = l->cabeca;
    while (p != NULL && compara(info, p->info) > 0) {
        cont++;
        p = p->proximo;
    }
    return insereNaPosicao(l, info, cont);
}

int retorna_pos(Lista l, void *info, int (*compara)(void*, void*)) { // ARRUMAR
    int cont = 0;
    Elemento *p = l.cabeca;
    while (p != NULL) {
        if (compara(info, p->info)) {
            break;
        }
        cont++;
        p = p->proximo;
    }
    return cont-1;
}
