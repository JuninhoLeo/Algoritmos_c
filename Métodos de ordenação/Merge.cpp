#include <iostream>
using namespace std;
#define A 6
#define B 8
#define C 14

int vetA[A]={12,19,23,28,35,42},
vetB[B]={7,13,16,21,29,31,33,34},
vetC[C], vA=0, vB=0, vC=0;

int main (){

  int i=0,j=0,k=0;

        while(i<A && j<B){
          if(vetA[i] < vetB[j]){
            vetC[k]=vetA[i];
            i++;
          }else{
            vetC[k]=vetB[j];
            j++;
          }
        k++;
        }

        if(i<A){
          while(i<A){
            vetC[k] = vetA[i];
            i++;k++;
          }
        }else{
          while(j<B){
            vetC[k] = vetB[j];
            j++;k++;
          }
        }
    i=0;
    while(i<C){
      cout << "[" << vetC[i] << "]";
      i++;
    }



return 0;
}
