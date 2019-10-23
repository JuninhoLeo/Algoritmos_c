#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define Tam 12
using namespace std;

void Leitura();
void ordenar(int); // metodo que é chamado no switch
void bubble();
void Insert();
void Seletion();
void Count();
void CountDistr();
void Shell();
void MergeSort();
double T; //Variavel que armazena o tempo
int Sort[Tam];

int main() {
  int sel;

    for(int i=0; i<10;){

      //Começa chamando a função leitura e preenchendo o vetor Sort[]
      //Leitura();

      system("cls");
      cout << "\t\t\tOrdenacao de Arquivos Semestre2\n ";
      cout << "\t\t\tSelecione a opcao desejada\n\n\n";

//---------------------------------------------------------
// Mostra o vetor no menu;
      cout << "\t\t\tSort ={ ";
    	for(int i=0; i<Tam; i++){
         cout << "[" << Sort[i] << "]";
        }cout << " }\n\n\n";


		cout << "\t\t\t*Antes de Qualquer operacao tem Que Desordenar o vetor!!\n\n";
		cout << "\t\t\t1-Desordenar o vetor\n";
		cout << "\t\t\t2-Bubble Sort\n";
		cout << "\t\t\t3-Insertion sort\n";
		cout << "\t\t\t4-Selection Sort\n";
		cout << "\t\t\t5-Counting Sort\n";
		cout << "\t\t\t6-Counting and distribution Sort\n";
		cout << "\t\t\t7-Shell Sort\n";
		cout << "\t\t\t8-Merge Sort\n";
		cout << "\t\t\t0-Sair\n\n";
		cout << "\t\t\tOpcao: ";
		cin >> sel;
    	if (sel >0) {
        //  T = clock(); //Armazena a hora de inicio da chamada da função
    	ordenar(sel);// chama a função
        //T = clock() - T; //Subtrai o tempo de termino do inicio e guarda na mesma
        //  printf("\t\t\tTempo de execucao: %Lf", T/1000);// mostra na tela o tempo de execução
        //  system("pause");
	    }
		  else {
	     i=30;
	     cout << "\n\t\t\t\tFim do Programa\n\n";
	    }
    }
return 0;
}

void Leitura(){ // preenche os Numeros aleatórios no vetor para ser ordenado";
  int i=0;
    while (i < Tam) {
    	if( i % 2 == 0 ){
         Sort[i] = rand() % 100;
        }else{
         Sort[i] = rand() % 1000;
        }
     i++;
    }
}

void ordenar(int op) {
    switch (op) {
    	  case 1:{ Leitura();        break;}
        case 2:{ bubble();         break;}
        case 3:{ Insert();         break;}
        case 4:{ Seletion();       break;}
        case 5:{ Count();          break;}
        case 6:{ CountDistr();     break;}
        case 7:{ Shell();          break;}
        case 8:{ MergeSort();      break;}
    }
}

void bubble(){
  int Aux,i;
  bool troca = true;
  int cont = Tam-1;

    while(troca == true){
       troca = false;
       i=0;
		while(i < cont){
        	if(Sort[i] > Sort[i+1]){
           	  Aux = Sort[i+1];
           	  Sort[i+1] = Sort[i];
           	  Sort[i] = Aux;
           	  troca = true;
        	}
       	 i++;
        }
     cont--;
    }
}

void Insert(){
  int Aux;
  int j;
  int i=0;

    while (i < Tam) {
     Aux = Sort[i];
     j=i;
		while (Sort[j-1] > Aux && j >= 0) {
		 Sort[j] = Sort[j-1];
		 j--;
		}
     Sort[j] = Aux;
     i++;
    }
}

void Seletion(){
  int i=0;
  int Aux;
  int j;
  int cont;

	while (i < Tam){
   	 j=i;
     cont = j;
     Aux = Sort[j];
    	while (j < Tam){
    		if (Sort[cont] > Sort[j]){
             cont = j;
            }
         j++;
        }
  	 Sort[i] = Sort[cont];
  	 Sort[cont] = Aux;
  	 i++;
    }

}

void Count(){

  int cont[Tam];
  int vet[Tam];

	for (int i=0; i<Tam; i++){
     cont[i] = 0;
  //}
     //Nesta implementa��o foi preciso setar o vetor vet[]
	 //pois o Sort[] vai ficar com o vetor ordenado
     vet[i] = Sort[i];
	}

    int i,j=0;

    while(j<Tam){
     i=j+1;
      	while(i<Tam){
            if(vet[j] > vet[i]){
             cont[j]++;
            }
			else{
             cont[i]++;
            }
      	 i++;
        }
     //Saida[cont[j]] = vet[j];
     //nessa implementa��o Saida[] é o Sort[]
     Sort[cont[j]] = vet[j];
     j++;
    }
}

void CountDistr(){

//    Somente para teste com menu
//------------------------------------

  int vet[Tam];

    for(int i=0; i<Tam; i++)
    vet[i] = Sort[i];

//------------------------------------

    int a=0,
    maior = vet[a],
    menor = vet[a];

    for(int i=0; i<Tam; i++){
    	if(Sort[i] > maior)
         maior = vet[i];
    	if(Sort[i] < menor)
         menor = vet[i];
    }

  int cont[maior];

    for(int i=menor; i<=maior; i++)
     cont[i] = 0;

    for(int i=0; i<=Tam; i++)
     cont[Sort[i]]++;

    for(int i=menor+1; i<=maior; i++)
     cont[i] = cont[i] + cont[i-1];

//------------------------------------
// Neste caso o vetor saida foi
//Substituido por Sot[]

    for(int i=0; i<Tam; i++)
     Sort[cont[vet[i]]-- -1] = vet[i];

}

void Shell(){

  int H[3] = {1,3,6},
  i,j,k,h,aux,inicio,incremento;

	for(i=2; i>=0; i--){
     incremento = H[i];
     inicio =0;
	    while(inicio < incremento){
	     j=inicio;
	    	while((j+incremento) < Tam){
	         k = j+incremento;
	         aux = Sort[k];
	        	while((k-incremento) >= 0 && aux < Sort[k-incremento]){
	             Sort[k] = Sort[k-incremento];
	             k = k-incremento;
	            }
	         Sort[k] = aux;
	         j=j+incremento;
	        }
	     inicio++;
    	}
    }
}

void MergeSort(){
system("cls");
Leitura(); // caso a funçao seja chamada antes da Leitura
cout << "\t\t\tMerge Sort\n";
cout << "\t\t\tDigite 5 valores para inserir no VetorB\n";
int j=0, k=0, A=Tam, B, i, vetA[A];

  bubble();
  i=0;
  cout << "\n\n\t\t\tvetA";
	while (i<A) {
     vetA[i] = Sort[i];
     cout << "[" << vetA[i] << "]";
     i++;
    }

  cout << "\n\n\t\t\tQuantos Elementos ira inserir no vetorA\n\t\t\t";
  cin >> B;
  cout << "\n\n\t\t\tPode inserir os valores\n\t\t\tPrecisam estar ordenado!!\n\n";
  int vetB[B],
  C = A+B,
  vetC[C];
  i=0;
	while (i < B) {
     cout << "\t\t\t";
     cin >> vetB[i];
     i++;
    }

  i=0;
  cout << "\n\n\t\t\tvetB";
	while (i<B) {
     cout << "[" << vetB[i] << "]";
     i++;
    }

  i=0;
	while(i<A && j<B){
     	if(vetA[i] < vetB[j]){
     	 vetC[k]=vetA[i];
     	 i++;
    	}
		else{
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
    }
    else{
    	while(j<B){
         vetC[k] = vetB[j];
         j++;k++;
        }
    }

// Daqui para baixo somente é necessário para mostrar o resultado na tela

system("cls");

  i=0;
  cout << "\n\n\t\t\tvetA";
	while (i<A) {
     vetA[i] = Sort[i];
     cout << "[" << vetA[i] << "]";
     i++;
    }

  i=0;
  cout << "\n\n\t\t\tvetB";
	while (i<B) {
     cout << "[" << vetB[i] << "]";
     i++;
    }

  i=0;
  cout << "\n\n\t\t\tvetC";
	while(i<C){
     cout << "[" << vetC[i] << "]";
     i++;
    }
  cout << "\n\n\t\t\t";
  system("pause");
}
