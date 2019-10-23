#include <iostream>
#define x 100
using namespace std;

struct Dados{
    int Codigo;
    string Nome;
    string Endere;
    string Cidade;
    string UF;
}REGISTRO[50];

void Imprecao(Dados[],int);
void LeituraDados(Dados[]);

void BuscaBinaria(Dados[],int);
void BUSCASEQUENCIAL(Dados[],int);
int ExclusaoRegistro(Dados[],int);
int InclusaoRegistro(Dados[],int);

int main(){
    int tamanho = 12;
    LeituraDados(REGISTRO);

    int op;
    for(int i=0; i<100; i++){

        system("cls");
        cout << "\n\t\t\t\t\t1- BUSCA SEQUENCIAL\n\n";
        cout << "\t\t\t\t\t2- BUSCA BINARIA\n\n";
        cout << "\t\t\t\t\t3- INCLUSAO DE REGISTRO\n\n";
        cout << "\t\t\t\t\t4- EXCLUSAO DE REGISTRO\n\n";
        cout << "\t\t\t\t\t5- IMPRECAO\n\n";
        cout << "\t\t\t\t\t0- SAIR\n\n";
        cout << "\t\t\t\t\t\tOPCAO: ";
        cin >> op;

        system("cls");
            switch(op){

                case 1:{
                         BUSCASEQUENCIAL(REGISTRO,tamanho);
                         break;}

                case 2:{
                         BuscaBinaria(REGISTRO,tamanho);
                         break;}

                case 3:{
                         tamanho = InclusaoRegistro(REGISTRO,tamanho);
                         break;}

                case 4:{
                         tamanho = ExclusaoRegistro(REGISTRO,tamanho);
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
//--------------------------BUSCA DE BINARIA-----------------------------------------------------
//-------------------------------------------------------------------------------------------------

void BuscaBinaria(Dados reg[],int tam){
    int Fim=tam, Inicio=0, Meio = (Inicio+Fim)/2, Proc;

    cout << "\tQual Registro procura: ";
    cin >> Proc;

    while(Inicio < Fim && reg[Meio].Codigo != Proc){
        if(Proc > reg[Meio].Codigo){
            Inicio = Meio+1;
        }
         else{
            Fim = Meio-1;
         }
    Meio = (Inicio+Fim)/2;
    }

    if(Proc == reg[Meio].Codigo){
        cout << "\nCodigo..: " << reg[Meio].Codigo;
        cout << "\nNome....: " << reg[Meio].Nome;
        cout << "\nEndereco: " << reg[Meio].Endere;
        cout << "\nCidade..: " << reg[Meio].Cidade;
        cout << "\nUF......: " << reg[Meio].UF;
        cout << "\n\n";
    }
     else {
         cout << "\n\n\tRegistro N:" << Proc << " nao Encontrado!!\n\n";
        }
system("pause");
}

//----------------------------------------------------------------------------------------------------
//----------------------BUSCA SEQUENCIAL--------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

void BUSCASEQUENCIAL(Dados reg[],int fim){
    int Proc,i=0;

    cout << "\tQual Registro procura: ";
    cin >> Proc;

    while(reg[i].Codigo < Proc){
     i++;
    }

    if(reg[i].Codigo == Proc){
        cout << "\nCodigo..: " << reg[i].Codigo;
        cout << "\nNome....: " << reg[i].Nome;
        cout << "\nEndereco: " << reg[i].Endere;
        cout << "\nCidade..: " << reg[i].Cidade;
        cout << "\nUF......: " << reg[i].UF;
        cout << "\n------------------------------------\n";

    }
    else{
        cout << "\n\n\tRegistro:" << Proc << " nao Encontrado!!\n\n";
    }
system("pause");
}

//-------------------------------------------------------------------------------------------------
//--------------------------INCLUSÃO --------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

int InclusaoRegistro(Dados ArqS[x],int tam){

    Dados ArqT[x];
    int qtde;
    cout << "\n\n\tINFORME A QUANTIDADE DE REGISTROS QUE SERA INSERIDOS\n\n";
    cin >> qtde;

    for(int i=0; i<qtde; i++){
        system("cls");
        cout << "\n\tCodigo..: ";
        cin >> ArqT[i].Codigo;
        cout << "\n\tNome....: ";
        cin >> ArqT[i].Nome;
        cout << "\n\tEndereco: ";
        cin >> ArqT[i].Endere;
        cout << "\n\tCidade..: ";
        cin >> ArqT[i].Cidade;
        cout << "\n\tUF......: " ;
        cin >> ArqT[i].UF;
        cout << endl;
    }

    Dados ArqA[x];
    int indS=0,indT=0,indA=0;

        while((indS <= tam)&&(indT<qtde)){
            if(ArqT[indT].Codigo < ArqS[indS].Codigo){

                ArqA[indA].Codigo = ArqT[indT].Codigo;
                ArqA[indA].Nome = ArqT[indT].Nome;
                ArqA[indA].Endere = ArqT[indT].Endere;
                ArqA[indA].UF = ArqT[indT].UF;
                indT++;
            }
            else{
                ArqA[indA].Codigo = ArqS[indS].Codigo;
                ArqA[indA].Nome = ArqS[indS].Nome;
                ArqA[indA].Endere = ArqS[indS].Endere;
                ArqA[indA].UF = ArqS[indS].UF;
                indS++;
            }
         indA++;
        }

    while(indT < qtde){
        ArqA[indA].Codigo = ArqT[indT].Codigo;
        ArqA[indA].Nome = ArqT[indT].Nome;
        ArqA[indA].Endere = ArqT[indT].Endere;
        ArqA[indA].UF = ArqT[indT].UF;
     indA++;
     indT++;
    }

    while(indS <= tam){
        ArqA[indA].Codigo = ArqS[indS].Codigo;
        ArqA[indA].Nome = ArqS[indS].Nome;
        ArqA[indA].Endere = ArqS[indS].Endere;
        ArqA[indA].UF = ArqS[indS].UF;
     indA++;
     indS++;
    }

    for(int i=0;i<=indA;i++){
        ArqS[i].Codigo = ArqA[i].Codigo;
        ArqS[i].Nome = ArqA[i].Nome;
        ArqS[i].Endere = ArqA[i].Endere;
        ArqS[i].UF = ArqA[i].UF;
    }

return indA-1;
system("pause");
}

//-------------------------------------------------------------------------------------------------
//--------------------------EXCLUSÃO---------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

int ExclusaoRegistro(Dados ArqS[],int tam){

    Dados ArqT[x];
    int qtde;
    cout << "\n\n\tINFORME A QUANTIDADE DE REGISTROS QUE SERA EXCLUIDOS\n\n";
    cin >> qtde;

    for(int i=0; i<qtde; i++){
        int aux=0,codigo;
        system("cls");
        cout << "\n\tCodigo..: ";
        cin >> codigo;
        while((aux <= tam)&&(codigo != ArqS[aux].Codigo)){
            aux++;
        }
        if((ArqS[aux].Codigo == codigo)&&(codigo <= ArqS[tam].Codigo)){
            ArqT[i].Codigo = codigo;
        }
         else{ cout << "\n\n\tARQUIVO NAO EXISTENTE TENTE OUTRO\n\n";
                i--;
               system("pause");
         }
    }

    Dados ArqA[x];
    int indS=0,indT=0,indA=0;

        while(indT<qtde){
            if(ArqT[indT].Codigo == ArqS[indS].Codigo){
             indT++;
             indS++;
            }
            else{
                ArqA[indA].Codigo = ArqS[indS].Codigo;
                ArqA[indA].Nome = ArqS[indS].Nome;
                ArqA[indA].Endere = ArqS[indS].Endere;
                ArqA[indA].UF = ArqS[indS].UF;
             indS++;
             indA++;
            }
        }

    while(indS <= tam){
        ArqA[indA].Codigo = ArqS[indS].Codigo;
        ArqA[indA].Nome = ArqS[indS].Nome;
        ArqA[indA].Endere = ArqS[indS].Endere;
        ArqA[indA].UF = ArqS[indS].UF;
     indA++;
     indS++;
    }

    for(int i=0;i<=indA;i++){
        ArqS[i].Codigo = ArqA[i].Codigo;
        ArqS[i].Nome = ArqA[i].Nome;
        ArqS[i].Endere = ArqA[i].Endere;
        ArqS[i].UF = ArqA[i].UF;
    }

return indA-1;
system("pause");
}

void LeituraDados(Dados VAR1[]){
    VAR1[ 0].Codigo = {11}; VAR1[ 0].Nome = {"Maria"};   VAR1[ 0].Endere = {"A"}; VAR1[ 0].Cidade = {"Assis"};       VAR1[ 0].UF = {"SP"};
    VAR1[ 1].Codigo = {14}; VAR1[ 1].Nome = {"Antonia"}; VAR1[ 1].Endere = {"J"}; VAR1[ 1].Cidade = {"Paraguacu"};   VAR1[ 1].UF = {"SP"};
    VAR1[ 2].Codigo = {15}; VAR1[ 2].Nome = {"Pedro"};   VAR1[ 2].Endere = {"D"}; VAR1[ 2].Cidade = {"Sao Paulo"};   VAR1[ 2].UF = {"SP"};
    VAR1[ 3].Codigo = {16}; VAR1[ 3].Nome = {"Fabio"};   VAR1[ 3].Endere = {"J"}; VAR1[ 3].Cidade = {"Assis"};       VAR1[ 3].UF = {"SP"};
    VAR1[ 4].Codigo = {18}; VAR1[ 4].Nome = {"Joao"};    VAR1[ 4].Endere = {"S"}; VAR1[ 4].Cidade = {"Ponta Grossa"};VAR1[ 4].UF = {"PR"};
    VAR1[ 5].Codigo = {20}; VAR1[ 5].Nome = {"Paulo"};   VAR1[ 5].Endere = {"G"}; VAR1[ 5].Cidade = {"Sao Paulo"};   VAR1[ 5].UF = {"SP"};
    VAR1[ 6].Codigo = {21}; VAR1[ 6].Nome = {"Luciana"}; VAR1[ 6].Endere = {"J"}; VAR1[ 6].Cidade = {"Assis"}     ;  VAR1[ 6].UF = {"SP"};
    VAR1[ 7].Codigo = {27}; VAR1[ 7].Nome = {"Julia"};   VAR1[ 7].Endere = {"K"}; VAR1[ 7].Cidade = {"Candido Mota"};VAR1[ 7].UF = {"SP"};
    VAR1[ 8].Codigo = {29}; VAR1[ 8].Nome = {"Silvia"};  VAR1[ 8].Endere = {"W"}; VAR1[ 8].Cidade = {"Assis"};       VAR1[ 8].UF = {"SP"};
    VAR1[ 9].Codigo = {32}; VAR1[ 9].Nome = {"Cristina"};VAR1[ 9].Endere = {"I"}; VAR1[ 9].Cidade = {"Assis"};       VAR1[ 9].UF = {"SP"};
    VAR1[10].Codigo = {39}; VAR1[10].Nome = {"Denis"};   VAR1[10].Endere = {"F"}; VAR1[10].Cidade = {"Curitiba"};    VAR1[10].UF = {"PR"};
    VAR1[11].Codigo = {43}; VAR1[11].Nome = {"Jose"};    VAR1[11].Endere = {"W"}; VAR1[11].Cidade = {"Paraguacu"};   VAR1[11].UF = {"SP"};
    VAR1[12].Codigo = {47}; VAR1[12].Nome = {"Joaquim"}; VAR1[12].Endere = {"U"}; VAR1[12].Cidade = {"Sao Paulo"};   VAR1[12].UF = {"SP"};
}

void Imprecao(Dados Reg[],int tam){

    for(int i=0;i<=tam;i++){
        cout << "\t" << REGISTRO[i].Codigo;
        cout << "\t" << REGISTRO[i].Nome;
        //cout << "\n\tEndereco: " << REGISTRO[i].Endere;
        //cout << "\n\tCidade..: " << REGISTRO[i].Cidade;
        //cout << "\n\tUF......: " << REGISTRO[i].UF;
       // cout << "\n------------------------------------";
        cout << "\n------------------------------------\n";

    }
cout << endl << endl << endl;
system("pause");
}
