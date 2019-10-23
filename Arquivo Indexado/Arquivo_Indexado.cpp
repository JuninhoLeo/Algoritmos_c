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

void BuscaRegistro(Index[],Dados[],int);
int ExclusaoRegistro(Index[],Dados[],int);
int InclusaoRegistro(Index[],Dados[],int);
int Reorganizacao(Dados[],Index[],int);

int main() {
    int tamanho = 12, aux;
    LeituraDados(REGISTRO);
    LeituraIndice(INDICE);

    int op;
    for(int i=0; i<100; i++){

        system("cls");
        cout << "\n\n\t\t\t\t\t1- BUSCAR REGISTRO\n\n";
        cout << "\t\t\t\t\t2- INCLUSAO DO REGISTRO\n\n";
        cout << "\t\t\t\t\t3- EXCLUSAO DO REGISTRO\n\n";
        cout << "\t\t\t\t\t4- REORGANIZACAO\n\n";
        cout << "\t\t\t\t\t5- IMPRIMIR\n\n";
        cout << "\t\t\t\t\t0- SAIR\n\n";
        cout << "\t\t\t\t\t\tOPCAO: ";
        cin >> op;

        system("cls");
            switch(op){

                case 1:{
                         BuscaRegistro(INDICE,REGISTRO,tamanho);
                         break;}

                case 2:{
                         tamanho = InclusaoRegistro(INDICE,REGISTRO,tamanho);
                         break;}

                case 3:{
                         tamanho = ExclusaoRegistro(INDICE,REGISTRO,tamanho);
                         break;}

                case 4:{
                         tamanho = Reorganizacao(REGISTRO,INDICE,tamanho);
                         break;}

                case 5:{
                         Imprecao(REGISTRO,tamanho);
                         break;}

                case 0:{
                         i = 100;
                         system("cls");
                         system("pause");
                         break;}
            }
    }

return 0;
}


//-------------------------------------------------------------------------------------------------
//--------------------------BUSCA DE REGISTROS-----------------------------------------------------
//-------------------------------------------------------------------------------------------------
void BuscaRegistro(Index indc[],Dados Reg[],int tam){
    int Fim=tam, Inicio=0, Meio = (Inicio+Fim)/2, Proc;

    cout << "\nQUAL REGISTRO PROCURA: ";
    cin >> Proc;

    while((Inicio < Fim)&&(indc[Meio].Cod != Proc)){
        if(Proc > indc[Meio].Cod){
            Inicio = Meio+1;
        }
         else{
            Fim = Meio-1;
         }
        Meio = (Inicio+Fim)/2;
    }

    Meio = indc[Meio].End;

    if((Reg[Meio].Codigo == Proc)&&(Reg[Meio].status == false)){
        cout << "\n\tCodigo..: " << Reg[Meio].Codigo;
        cout << "\n\tNome....: " << Reg[Meio].Nome;
        cout << "\n\tEndereco: " << Reg[Meio].Endere;
        cout << "\n\tCidade..: " << Reg[Meio].Cidade;
        cout << "\n\tUF......: " << Reg[Meio].UF;
        cout << "\n------------------------------------";
        cout << "\n------------------------------------\n\n";
    }
     else
        cout << "\nRegistro Nao Encontrado!!!\n\n\n";
system("pause");
}

//-------------------------------------------------------------------------------------------------
//--------------------------EXCLUSÃO---------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int ExclusaoRegistro(Index indc[],Dados reg[],int tam){
    int del, Fim=tam,Inicio=0, Meio = (Inicio+Fim)/2;

    cout << "\nQUAL REGISTRO APAGAR: ";
    cin >> del;

        while((Inicio < Fim)&&(indc[Meio].Cod != del)){
            if(del > indc[Meio].Cod){
                Inicio = Meio+1;
            }
             else{
                 Fim = Meio-1;
             }
         Meio = (Inicio+Fim)/2;
        }

        Meio = indc[Meio].End;//OBTER O ENDEREÇO DO REGISTRO

        if((reg[Meio].Codigo == del)&&(reg[Meio].status == false)){
            reg[Meio].status = true;
            cout << "\n\n\t\tCONCLUIDO!!\n\n";
            system("pause");
            return tam;
        }
         else{
             cout << "REGISTRO NAO ENCONTRADO!!!" << endl;
         }
system("pause");
}

//-------------------------------------------------------------------------------------------------
//--------------------------INCLUSÃO --------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int InclusaoRegistro(Index Indc[],Dados registro[],int tam){

    tam++;
        cout << "\ninforme o Codigo..: ";
        cin >> registro[tam].Codigo;
        cout << "\ninforme o Nome....: ";
        cin >> registro[tam].Nome;
        cout << "\ninforme o Endereco: ";
        cin >> registro[tam].Endere;
        cout << "\ninforme o Cidade..: ";
        cin >> registro[tam].Cidade;
        cout << "\ninforme o UF......: " ;
        cin >> registro[tam].UF;
        registro[tam].status = false;
        cout << endl;

    Indc[tam].Cod = registro[tam].Codigo;
    Indc[tam].End = tam;

    Index aux;

    for(int i=tam; i>=0; i--){
        if(Indc[i].Cod < Indc[i-1].Cod){
            aux = Indc[i];
            Indc[i] = Indc[i-1];
            Indc[i-1] = aux;
        }
    }
system("pause");
return tam;
}

//-------------------------------------------------------------------------------------------------
//--------------------------REORGANIZAÇÃO DO ARQUIVO------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int Reorganizacao(Dados Reg[],Index Indice[],int tam){

    int aux=0,ind,Nind=0;

    Dados N_Reg[tam];
    Index N_Ind[tam];

    while(aux <= tam){

        ind = Indice[aux].End;

        if(Reg[ind].status == false){ // TRUE É QUANDO O ARQUIVO ESTÁ EXCLUIDO
            N_Reg[Nind].Codigo = Reg[ind].Codigo;
            N_Reg[Nind].Nome = Reg[ind].Nome;
            N_Reg[Nind].Endere = Reg[ind].Endere;
            N_Reg[Nind].UF = Reg[ind].UF;
            N_Reg[Nind].status = Reg[ind].status;

            N_Ind[Nind].Cod = N_Reg[Nind].Codigo;
            N_Ind[Nind].End = Nind;
         Nind++;
        }
     aux++;
    }

    tam = Nind;

    for(int i=0; i<tam; i++){
        Reg[i].Codigo = N_Reg[i].Codigo;
        Reg[i].Nome = N_Reg[i].Nome;
        Reg[i].Endere = N_Reg[i].Endere;
        Reg[i].UF = N_Reg[i].UF;
        Reg[i].status = false;
    }

    for(int i=0; i<tam;i++){
       Indice[i].Cod = N_Ind[i].Cod;
       Indice[i].End = N_Ind[i].End;
    }


cout << "\n\nCONCLUIDO!!!\n\n";
system("pause");
return tam-1;
}

void LeituraDados(Dados VAR1[]){
    VAR1[ 0].Codigo = {21}; VAR1[ 0].Nome = {"Maria"};   VAR1[ 0].Endere = {"A"}; VAR1[ 0].Cidade = {"Assis"};       VAR1[ 0].UF = {"SP"}; VAR1[ 0].status = {false};
    VAR1[ 1].Codigo = {15}; VAR1[ 1].Nome = {"Antonia"}; VAR1[ 1].Endere = {"J"}; VAR1[ 1].Cidade = {"Paraguacu"};   VAR1[ 1].UF = {"SP"}; VAR1[ 1].status = {false};
    VAR1[ 2].Codigo = {32}; VAR1[ 2].Nome = {"Pedro"};   VAR1[ 2].Endere = {"D"}; VAR1[ 2].Cidade = {"Sao Paulo"};   VAR1[ 2].UF = {"SP"}; VAR1[ 2].status = {false};
    VAR1[ 3].Codigo = {39}; VAR1[ 3].Nome = {"Fabio"};   VAR1[ 3].Endere = {"J"}; VAR1[ 3].Cidade = {"Assis"};       VAR1[ 3].UF = {"SP"}; VAR1[ 3].status = {false};
    VAR1[ 4].Codigo = {11}; VAR1[ 4].Nome = {"Joao"};    VAR1[ 4].Endere = {"S"}; VAR1[ 4].Cidade = {"Ponta Grossa"};VAR1[ 4].UF = {"PR"}; VAR1[ 4].status = {false};
    VAR1[ 5].Codigo = {18}; VAR1[ 5].Nome = {"Paulo"};   VAR1[ 5].Endere = {"G"}; VAR1[ 5].Cidade = {"Sao Paulo"};   VAR1[ 5].UF = {"SP"}; VAR1[ 5].status = {false};
    VAR1[ 6].Codigo = {43}; VAR1[ 6].Nome = {"Luciana"}; VAR1[ 6].Endere = {"J"}; VAR1[ 6].Cidade = {"Assis"}     ;  VAR1[ 6].UF = {"SP"}; VAR1[ 6].status = {false};
    VAR1[ 7].Codigo = {29}; VAR1[ 7].Nome = {"Julia"};   VAR1[ 7].Endere = {"K"}; VAR1[ 7].Cidade = {"Candido Mota"};VAR1[ 7].UF = {"SP"}; VAR1[ 7].status = {false};
    VAR1[ 8].Codigo = {16}; VAR1[ 8].Nome = {"Silvia"};  VAR1[ 8].Endere = {"W"}; VAR1[ 8].Cidade = {"Assis"};       VAR1[ 8].UF = {"SP"}; VAR1[ 8].status = {false};
    VAR1[ 9].Codigo = {47}; VAR1[ 9].Nome = {"Cristina"};VAR1[ 9].Endere = {"I"}; VAR1[ 9].Cidade = {"Assis"};       VAR1[ 9].UF = {"SP"}; VAR1[ 9].status = {false};
    VAR1[10].Codigo = {27}; VAR1[10].Nome = {"Denis"};   VAR1[10].Endere = {"F"}; VAR1[10].Cidade = {"Curitiba"};    VAR1[10].UF = {"PR"}; VAR1[10].status = {false};
    VAR1[11].Codigo = {14}; VAR1[11].Nome = {"Jose"};    VAR1[11].Endere = {"W"}; VAR1[11].Cidade = {"Paraguacu"};   VAR1[11].UF = {"SP"}; VAR1[11].status = {false};
    VAR1[12].Codigo = {20}; VAR1[12].Nome = {"Joaquim"}; VAR1[12].Endere = {"U"}; VAR1[12].Cidade = {"Sao Paulo"};   VAR1[12].UF = {"SP"}; VAR1[12].status = {false};
}

void LeituraIndice(Index VAR2[]){
    VAR2[ 0].Cod = {11}; VAR2[ 0].End = { 4};
    VAR2[ 1].Cod = {14}; VAR2[ 1].End = {11};
    VAR2[ 2].Cod = {15}; VAR2[ 2].End = { 1};
    VAR2[ 3].Cod = {16}; VAR2[ 3].End = { 8};
    VAR2[ 4].Cod = {18}; VAR2[ 4].End = { 5};
    VAR2[ 5].Cod = {20}; VAR2[ 5].End = {12};
    VAR2[ 6].Cod = {21}; VAR2[ 6].End = { 0};
    VAR2[ 7].Cod = {27}; VAR2[ 7].End = {10};
    VAR2[ 8].Cod = {29}; VAR2[ 8].End = { 7};
    VAR2[ 9].Cod = {32}; VAR2[ 9].End = { 2};
    VAR2[10].Cod = {39}; VAR2[10].End = { 3};
    VAR2[11].Cod = {43}; VAR2[11].End = { 6};
    VAR2[12].Cod = {47}; VAR2[12].End = { 9};
}

void Imprecao(Dados Reg[],int tam){

    for(int i=0;i<=tam;i++){
        if(Reg[i].status == false){
            cout << "\t" << REGISTRO[i].Codigo;
            cout << "\t" << REGISTRO[i].Nome;
            //cout << "\n\tEndereco: " << REGISTRO[i].Endere;
            //cout << "\tCidade..: " << REGISTRO[i].Cidade;
            //cout << "\n\tUF......: " << REGISTRO[i].UF;
            //cout << "\n------------------------------------";
            cout << "\n------------------------------------\n";
        }
    }
cout << endl;
system("pause");
}

