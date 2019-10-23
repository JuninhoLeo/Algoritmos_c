#include <iostream>
#include <stdlib.h>
#define tam 10
using namespace std;

int main() {

int SHELL[tam]={9,8,7,6,5,4,3,2,1,0},
    H[3] = {1,3,6},
    i,j,k,h,aux,inicio,incremento;

    for(i=2; i>=0; i--){
      incremento = H[i];
      inicio =0;
      while(inicio < incremento){
        j=inicio;
        while((j+incremento) < tam){
          k = j+incremento;
          aux = SHELL[k];
          while((k-incremento) >= 0 && aux < SHELL[k-incremento]){
            SHELL[k] = SHELL[k-incremento];
            k = k-incremento;
          }
          SHELL[k] = aux;
          j=j+incremento;
        }
        inicio++;
      }
    }

    for(int a=0;a<tam;a++){
      cout << "[" << SHELL[a] << "] ";
    }
    cout << endl;



return 0;
}
