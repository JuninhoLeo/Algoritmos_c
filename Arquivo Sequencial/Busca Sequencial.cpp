#include <iostream>

using namespace std;

struct Dados{
    int Codigo;
    string Nome;
    string Endere;
    string Cidade;
    string UF;
    bool status;
}REGISTRO[50];

int Leitura(Dados[]);
void buscaSequencial(Dados[],int);
void Imprecao(Dados[],int);

int main(){
    int tamanho = 12;
	Leitura(REGISTRO);
	Imprecao(REGISTRO,tamanho);
	buscaSequencial(REGISTRO,tamanho);

system("pause");
}

void Imprecao(Dados teste[],int tam){

    for(int i=0;i<=tam;i++){
        cout << "\n\tCodigo..: " << REGISTRO[i].Codigo;
        cout << "\n\tNome....: " << REGISTRO[i].Nome;
        cout << "\n\tEndereco: " << REGISTRO[i].Endere;
        cout << "\n\tCidade..: " << REGISTRO[i].Cidade;
        cout << "\n\tUF......: " << REGISTRO[i].UF;
        cout << "\n------------------------------------";
    }
    cout << "\n----------------------------------------\n\n";
}

int Leitura(Dados REGISTRO[]){

	REGISTRO[ 0].Codigo = {11}; REGISTRO[ 0].Nome = {"Maria"};   REGISTRO[ 0].Endere = {"A"}; REGISTRO[ 0].Cidade = {"Assis"};       REGISTRO[ 0].UF = {"SP"};
    REGISTRO[ 1].Codigo = {14}; REGISTRO[ 1].Nome = {"Antonia"}; REGISTRO[ 1].Endere = {"J"}; REGISTRO[ 1].Cidade = {"Paraguacu"};   REGISTRO[ 1].UF = {"SP"};
    REGISTRO[ 2].Codigo = {15}; REGISTRO[ 2].Nome = {"Pedro"};   REGISTRO[ 2].Endere = {"D"}; REGISTRO[ 2].Cidade = {"Sao Paulo"};   REGISTRO[ 2].UF = {"SP"};
    REGISTRO[ 3].Codigo = {16}; REGISTRO[ 3].Nome = {"Fabio"};   REGISTRO[ 3].Endere = {"J"}; REGISTRO[ 3].Cidade = {"Assis"};       REGISTRO[ 3].UF = {"SP"};
    REGISTRO[ 4].Codigo = {18}; REGISTRO[ 4].Nome = {"Joao"};    REGISTRO[ 4].Endere = {"S"}; REGISTRO[ 4].Cidade = {"Ponta Grossa"};REGISTRO[ 4].UF = {"PR"};
    REGISTRO[ 5].Codigo = {20}; REGISTRO[ 5].Nome = {"Paulo"};   REGISTRO[ 5].Endere = {"G"}; REGISTRO[ 5].Cidade = {"Sao Paulo"};   REGISTRO[ 5].UF = {"SP"};
    REGISTRO[ 6].Codigo = {21}; REGISTRO[ 6].Nome = {"Luciana"}; REGISTRO[ 6].Endere = {"J"}; REGISTRO[ 6].Cidade = {"Assis"}     ;  REGISTRO[ 6].UF = {"SP"};
    REGISTRO[ 7].Codigo = {27}; REGISTRO[ 7].Nome = {"Julia"};   REGISTRO[ 7].Endere = {"K"}; REGISTRO[ 7].Cidade = {"Candido Mota"};REGISTRO[ 7].UF = {"SP"};
    REGISTRO[ 8].Codigo = {29}; REGISTRO[ 8].Nome = {"Silvia"};  REGISTRO[ 8].Endere = {"W"}; REGISTRO[ 8].Cidade = {"Assis"};       REGISTRO[ 8].UF = {"SP"};
    REGISTRO[ 9].Codigo = {32}; REGISTRO[ 9].Nome = {"Joana"};   REGISTRO[ 9].Endere = {"I"}; REGISTRO[ 9].Cidade = {"Assis"};       REGISTRO[ 9].UF = {"SP"};
    REGISTRO[10].Codigo = {39}; REGISTRO[10].Nome = {"Denis"};   REGISTRO[10].Endere = {"F"}; REGISTRO[10].Cidade = {"Curitiba"};    REGISTRO[10].UF = {"PR"};
    REGISTRO[11].Codigo = {43}; REGISTRO[11].Nome = {"Jose"};    REGISTRO[11].Endere = {"W"}; REGISTRO[11].Cidade = {"Paraguacu"};   REGISTRO[11].UF = {"SP"};
    REGISTRO[12].Codigo = {47}; REGISTRO[12].Nome = {"Joaquim"}; REGISTRO[12].Endere = {"U"}; REGISTRO[12].Cidade = {"Sao Paulo"};   REGISTRO[12].UF = {"SP"};

return 12;
}



//----------------------------------------------------------------------------------------------------
//----------------------BUSCA SEQUENCIAL--------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

	void buscaSequencial(Dados REGISTRO[],int fim){
	    int Proc,i=0;

	    cout << "\tQual Registro procura: ";
	    cin >> Proc;

	    while(REGISTRO[i].Codigo < Proc){
	     i++;
	    }

	    if(Proc == REGISTRO[i].Codigo){
            cout << "\nCodigo..: " << REGISTRO[i].Codigo;
            cout << "\nNome....: " << REGISTRO[i].Nome;
            cout << "\nEndereco: " << REGISTRO[i].Endere;
            cout << "\nCidade..: " << REGISTRO[i].Cidade;
            cout << "\nUF......: " << REGISTRO[i].UF;
            cout << "\n------------------------------------\n";

		}
	    else{
			cout << "\n\n\tRegistro N:" << Proc << " nao Encontrado!!\n\n";
	    }
	}

