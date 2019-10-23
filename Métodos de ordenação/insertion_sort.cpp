#include <iostream>

using namespace std;
int main() {
    int Insert[8]={26,18,21,32,14,22,16,20};
    int Aux;
    int j;

      for(int i=1; i<8; i++) {
        Aux = Insert[i];
          for(j=i; Insert[j-1] > Aux && j >= 0; j--) {
            Insert[j] = Insert[j-1];
          }
        Insert[j] = Aux;
      }

    for ( int A = 0; A < 8; A++) {
      cout << "[" << Insert[A] << "]";
    }cout << endl;

return 0;
}
