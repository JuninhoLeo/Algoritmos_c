#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _no arvorebin;

struct _no{
  int info;
  arvorebin *Esq;
  arvorebin *Dir;
};

arvorebin buscaNo(arvorebin, int);

int main(){

return 0;
}

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
