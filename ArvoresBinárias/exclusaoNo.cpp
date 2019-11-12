#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _no arvorebin;

struct _no{
  int info;
  arvorebin *Esq;
  arvorebin *Dir;
};

void excluir(arvorebin, int);
void del(arvorebin, arvorebin*);

int main(){

return 0;
}

void excluir(arvorebin *root, int chave){
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
