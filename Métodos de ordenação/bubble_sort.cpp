#include <iostream>

using namespace std;
int main(){

int bubble[10]={8,9,0,1,2,3,4,5,6,7};
int i,cont=10;
bool troca = true;
int aux;

    while(troca==true){
      troca = false;
      i=0;
        while(i<cont){
          if(bubble[i] > bubble[i+1]){
            aux = bubble[i+1];
            bubble[i+1] = bubble[i];
            bubble[i] = aux;
            troca = true;
          }
         i++;
        }
     cont--;
    }

    cont = 10;
    for(int a=0;a<cont;a++){
      cout << "[" << bubble[a] << "] ";
    }

return 0;
}
