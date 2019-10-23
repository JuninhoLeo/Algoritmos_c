#include <iostream>
#include <stdlib.h>
#define tam 10
using namespace std;

int main() {

int SHELL[tam]={9,8,7,6,5,4,3,2,1,0},
    i=0,
    j,
    h=1,
    aux,
    cont=tam,
    H[tam];


    while(h<tam)
    {
      H[i] = h;
      h = h*3+1;
      i++;
    }

    h=i;
    i=0;
    j=0;

    while(H[h] >= 1){
      cont = H[h];
        while(i+cont < tam){
          if(SHELL[i] > SHELL[i+1]){
            aux = SHELL[i+1];
            SHELL[i+1] = SHELL[i];
            SHELL[i] = aux;
            j=i;
            while(SHELL[j]< SHELL[j-1] && j>0){
              aux = SHELL[j];
              SHELL[j] = SHELL[j-1];
              SHELL[j-1] = aux;
              j--;
            }
          }
         i++;
        }
    h--;
    }

    for(int a=0;a<tam;a++){
      cout << "[" << H[a] << "] ";
    }
    cout << endl;


return 0;
}
