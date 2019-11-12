#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _no arvorebin;

struct _no{
  int info;
  arvorebin *Esq;
  arvorebin *Dir;
};

void emOrdem(arvorebin);
void posOrdem(arvorebin);
void preOrdem(arvorebin);

int main(){

return 0;
}

void emOrdem(arvorebin *root){
  if(root != NULL){
    emOrdem(root->Esq);
    printf("%d", root->info);
    emOrdem(root->Dir);
  }
}

void posOrdem(arvorebin *root){
  if(root != NULL){
    posOrdem(root->Esq);
    posOrdem(root->Dir);
    printf("%d", root->info);
  }
}

void preOrdem(arvorebin *root){
  if(root != NULL){
    printf("%d", root->info);
    preOrdem(root->Esq);
    preOrdem(root->Dir);
  }
}
