#include <iostream>

using namespace std;
#define tam 7
int main() {

int SELECT[tam]={28,19,32,14,26,17,25};
int i=0;
int Aux;
int j=0;
int cont;


    cout << "\t\t\tOrdenacao de Arquivos Selection Sort\n ";

      cout << "\t\t\tSort ={ ";
        for(int val=0; val<tam; val++){
          cout << "[" << SELECT[val] << "]";
        }cout << " }\n\n\n";


      while(i<tam){
        j=i;
        Aux = SELECT[j];
        cont = j;
        while(j<tam){
          if(SELECT[cont] > SELECT[j]){
            cont = j;
          }
        j++;
        }
        SELECT[i] = SELECT[cont];
        SELECT[cont] = Aux;
      i++;
      }

    cout << "\t\t\tSort ={ ";
      for(int val=0; val<tam; val++){
        cout << "[" << SELECT[val] << "]";
      }cout << " }\n\n\n";

return 0;
}
