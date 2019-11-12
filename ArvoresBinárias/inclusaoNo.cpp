#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _no arvorebin;

struct _no{
  int info;
  arvorebin *Esq;
  arvorebin *Dir;
};

arvorebin inclusaoNo(arvorebin, int);

int main(){

return 0;
}

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
