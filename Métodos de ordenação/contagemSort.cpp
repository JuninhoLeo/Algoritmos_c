#include <iostream>
#define tam 11
using namespace std;

int vet[tam] = {28, 16, 31, 21, 18, 21, 18, 23, 21, 28, 23},
    saida[tam],
    a=0;

int main(){

  int maior = vet[a],
      menor = vet[a];

    for(int i=0; i<tam; i++){
      if(vet[i] > maior)
        maior = vet[i];
      if(vet[i] < menor)
        menor = vet[i];
    }

  int cont[maior];

    for(int i=menor; i<=maior; i++)
      cont[i] = 0;

    for(int i=0; i<=tam; i++)
      cont[vet[i]]++;

    for(int i=menor+1; i<=maior; i++)
      cont[i] = cont[i] + cont[i-1];

    /*
    for(int i=0; i<tam; i++)
      saida[cont[vet[i]]-- -1] = vet[i];
        ou    */
    int aux1,
        aux2;

    for(int i=0; i<tam; i++)
    {
      aux1 = vet[i];
      aux2 = cont[aux1]--;
      aux2--;
      saida[aux2] = vet[i];
    }

      for(int i=0; i<tam; i++)
      cout << "["<< saida[i] << "]" ;

return 0;
}
