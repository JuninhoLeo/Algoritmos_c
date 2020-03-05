#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _no arvorebin;

struct _no{
  int info;
  arvorebin *Esq;
  arvorebin *Dir;
};

///-------------------------------------------
    void emOrdem(arvorebin);              ///-
    void preOrdem(arvorebin);             ///-
	void posOrdem(arvorebin);             ///-
///-------------------------------------------
    arvorebin buscaNo(arvorebin, int);    ///-
///-------------------------------------------
    arvorebin inclusaoNo(arvorebin, int); ///-
///-------------------------------------------
    void exclusaoNo(arvorebin, int);      ///-
	void del(arvorebin, arvorebin*);      ///-
///-------------------------------------------

int main(){



return 0;
}

///----------------------------------------------------------------------------------------------------------

void emOrdem(arvorebin *root){
  if(root != NULL){
    emOrdem(root->Esq);
    printf("%d", root->info);
    emOrdem(root->Dir);
  }
}

void preOrdem(arvorebin *root){
  if(root != NULL){
    printf("%d", root->info);
    preOrdem(root->Esq);
    preOrdem(root->Dir);
  }
}

void posOrdem(arvorebin *root){
  if(root != NULL){
    posOrdem(root->Esq);
    posOrdem(root->Dir);
    printf("%d", root->info);
  }
}

///----------------------------------------------------------------------------------------------------------

arvorebin buscaNo(arvorebin *root, int k){
  while (root != NULL) {
    if (k < root->info) {
      root = root->Esq;
    }else {
      if (k > root->info) {
        root = root->Dir;
      }else {
        printf("Elemento encontrado");
        return(root);
      }
    }
  }
  printf("Elemento nao encontrado");
  return(NULL);
}

///----------------------------------------------------------------------------------------------------------

arvorebin inclusaoNo(arvorebin *root, int k) {
  arvorebin *novo, *pai = NULL;

  novo = (arvorebin*)malloc(sizeof(arvorebin));
  novo->Esq = NULL;
  novo->Dir = NULL;
  novo->info = k;

  while(root != NULL) {
    pai = root;
    if(k = root->info) {
      root = root->Esq;
    }else {
      root = root->Dir;
    }
  }

  if((pai != NULL) && (k < pai->info)) {
    pai->Esq = novo;
  }else {
    pai->Dir = novo;
  }

return(novo);
}

///----------------------------------------------------------------------------------------------------------

void exclusaoNo(arvorebin *root, int chave){
  arvorebin *pai;

  if(*root == NULL) {
    result = 1;
    printf("\nElemento nao existe!");
  }else {
    if(chave < (*root)->info){
      excluir(&((*root)->Esq), chave);
    }else {
      if(chave > (*root)->info) {
        excluir(&((*root)->Dir), chave);
      }else {
        pai = *root;
        if(pai->Dir == NULL){
          *root = pai->Esq;
        }else {
          if(pai->Esq == NULL) {
            *root = pai->Dir;
          }else {
            del(&pai, &(pai->Esq));
          }
        }
      free(pai);
      }
    }
  }
  if(result == 0) {
    printf("\nO numero %d foi excluido!", chave);
  }
return;
}

void del(arvorebin *q, arvorebin *r) {
  if((*r)->Dir != NULL) {
    del(q, &((*r)->Dir));
  }else {
    (*q)->info = (*r)->info;
    (*q) = *r;
    *r = (*r->Esq);
  }
return;
}
