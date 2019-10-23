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

struct Index{
    int Cod;
    int End;

}INDICE[50];

void Imprecao(Dados[],int);
void LeituraDados(Dados[]);
void LeituraIndice(Index[]);
int Reorganizacao(Dados[],Index[],int);

int main(){
    int tamanho = 12;
    LeituraDados(REGISTRO);
    LeituraIndice(INDICE);
    cout << "\t\t Antes da organizacao!!!\n\n";
    Imprecao(REGISTRO,tamanho);
    tamanho = Reorganizacao(REGISTRO,INDICE,tamanho);
    cout << "----------------------------------------------------\n";
    cout << "\t\t Depois da organizacao!!!\n\n";
    Imprecao(REGISTRO,tamanho);


return 0;
}

//-------------------------------------------------------------------------------------------------
//--------------------------REORGANIZAÇÃO DO ARQUIVO------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int Reorganizacao(Dados Reg[],Index Indc[],int tam){
int i=0,End=0,Aux;
Dados N_Reg[tam];
Index N_ind[tam];

    while(i<=tam){
        Aux = Indc[i].End;

        if(Reg[Aux].status == false){ // TRUE SERÁ QUANDO EXCLUIDO
            N_Reg[End] = Reg[Aux];
            N_ind[End].Cod = N_Reg[End].Codigo;
            N_ind[End].End = End;
            End++;
        }
    i++;
    }
    for(int i=0; i<End;i++)
    Reg[i] = N_Reg[i];

    for(int i=0; i<End;i++)
    Indc[i] = N_ind[i];

return End-1;
}


void LeituraDados(Dados VAR1[]){
    VAR1[ 0].Codigo = {21}; VAR1[ 0].Nome = {"Maria"};   VAR1[ 0].Endere = {"A"}; VAR1[ 0].Cidade = {"Assis"};       VAR1[ 0].UF = {"SP"}; VAR1[ 0].status = {false};
    VAR1[ 1].Codigo = {14}; VAR1[ 1].Nome = {"Antonia"}; VAR1[ 1].Endere = {"J"}; VAR1[ 1].Cidade = {"Paraguacu"};   VAR1[ 1].UF = {"SP"}; VAR1[ 1].status = {true};
    VAR1[ 2].Codigo = {32}; VAR1[ 2].Nome = {"Pedro"};   VAR1[ 2].Endere = {"D"}; VAR1[ 2].Cidade = {"Sao Paulo"};   VAR1[ 2].UF = {"SP"}; VAR1[ 2].status = {true};
    VAR1[ 3].Codigo = {39}; VAR1[ 3].Nome = {"Fabio"};   VAR1[ 3].Endere = {"J"}; VAR1[ 3].Cidade = {"Assis"};       VAR1[ 3].UF = {"SP"}; VAR1[ 3].status = {false};
    VAR1[ 4].Codigo = {18}; VAR1[ 4].Nome = {"Joao"};    VAR1[ 4].Endere = {"S"}; VAR1[ 4].Cidade = {"Ponta Grossa"};VAR1[ 4].UF = {"PR"}; VAR1[ 4].status = {true};
    VAR1[ 5].Codigo = {11}; VAR1[ 5].Nome = {"Paulo"};   VAR1[ 5].Endere = {"G"}; VAR1[ 5].Cidade = {"Sao Paulo"};   VAR1[ 5].UF = {"SP"}; VAR1[ 5].status = {true};
    VAR1[ 6].Codigo = {43}; VAR1[ 6].Nome = {"Luciana"}; VAR1[ 6].Endere = {"J"}; VAR1[ 6].Cidade = {"Assis"}     ;  VAR1[ 6].UF = {"SP"}; VAR1[ 6].status = {false};
    VAR1[ 7].Codigo = {27}; VAR1[ 7].Nome = {"Julia"};   VAR1[ 7].Endere = {"K"}; VAR1[ 7].Cidade = {"Candido Mota"};VAR1[ 7].UF = {"SP"}; VAR1[ 7].status = {true};
    VAR1[ 8].Codigo = {16}; VAR1[ 8].Nome = {"Silvia"};  VAR1[ 8].Endere = {"W"}; VAR1[ 8].Cidade = {"Assis"};       VAR1[ 8].UF = {"SP"}; VAR1[ 8].status = {true};
    VAR1[ 9].Codigo = {47}; VAR1[ 9].Nome = {"Cristina"};VAR1[ 9].Endere = {"I"}; VAR1[ 9].Cidade = {"Assis"};       VAR1[ 9].UF = {"SP"}; VAR1 [9].status = {true};
    VAR1[10].Codigo = {29}; VAR1[10].Nome = {"Denis"};   VAR1[10].Endere = {"F"}; VAR1[10].Cidade = {"Curitiba"};    VAR1[10].UF = {"PR"}; VAR1[10].status = {true};
    VAR1[11].Codigo = {15}; VAR1[11].Nome = {"Jose"};    VAR1[11].Endere = {"W"}; VAR1[11].Cidade = {"Paraguacu"};   VAR1[11].UF = {"SP"}; VAR1[11].status = {true};
    VAR1[12].Codigo = {20}; VAR1[12].Nome = {"Joaquim"}; VAR1[12].Endere = {"U"}; VAR1[12].Cidade = {"Sao Paulo"};   VAR1[12].UF = {"SP"}; VAR1[12].status = {false};
}

void LeituraIndice(Index VAR2[]){
    VAR2[ 0].Cod = {11}; VAR2[ 0].End = { 5};
    VAR2[ 1].Cod = {14}; VAR2[ 1].End = { 1};
    VAR2[ 2].Cod = {15}; VAR2[ 2].End = {11};
    VAR2[ 3].Cod = {16}; VAR2[ 3].End = { 8};
    VAR2[ 4].Cod = {18}; VAR2[ 4].End = { 4};
    VAR2[ 5].Cod = {20}; VAR2[ 5].End = {12};
    VAR2[ 6].Cod = {21}; VAR2[ 6].End = { 0};
    VAR2[ 7].Cod = {27}; VAR2[ 7].End = { 7};
    VAR2[ 8].Cod = {29}; VAR2[ 8].End = {10};
    VAR2[ 9].Cod = {32}; VAR2[ 9].End = { 2};
    VAR2[10].Cod = {39}; VAR2[10].End = { 3};
    VAR2[11].Cod = {43}; VAR2[11].End = { 6};
    VAR2[12].Cod = {47}; VAR2[12].End = { 9};
}

void Imprecao(Dados Reg[],int tam){

    for(int i=0;i<=tam;i++){
        if(Reg[i].status == false){
            cout << "\n\tCodigo..: " << Reg[i].Codigo;
            cout << "\n\tNome....: " << Reg[i].Nome;
            cout << "\n\tEndereco: " << Reg[i].Endere;
            cout << "\n\tCidade..: " << Reg[i].Cidade;
            cout << "\n\tUF......: " << Reg[i].UF;
            cout << "\n------------------------------------";
            cout << "\n------------------------------------";
        }
    }
}

