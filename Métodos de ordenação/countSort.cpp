#include <iostream>
#define tam 8
using namespace std;

int vet[tam] = {28, 16, 34, 21, 15, 39, 18, 23};
             //{ 5,  1,  6,  3,  0,  7,  2,  4};
int cont[tam];
int saida[tam];

int main(){
  int i,j;

  for (i=0; i<tam; i++)
    cont[i] = 0;

    j=0;

      while(j<tam){
        i=j+1;
          while(i<tam){
              if(vet[j] > vet[i])
                cont[j]++;
              else
                cont[i]++;
            i++;
          }
        saida[cont[j]] = vet[j];
      j++;
      }

    for(int a=0; a<tam; a++){
      cout << "["<< saida[a] << "]" ;
    }

return 0;
}
