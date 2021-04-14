#include <iostream>
#include <cstring>
#include <locale>

#define N 100
#define Char 19
#define Char2 50

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int menu, ID[N], ID_S;
    int start=1;//variável que inicia o loop do menu
    int i=0;
    int j=0;
    char CNPJ[N][Char];
    char destino[N][Char2];
    char CNPJ_S[Char];
    char destino_S[Char2];
    int status[N];//status diz se embarcou ou não;
    char embarcar[Char2]; //embarcar armazena o destino que poderá levar contêineres
    int embarcados[N];//variável com ID de embarcados
    float valor[N];

    while (start==1){
        cout << "\n\t*******************MENU******************\n \t0.Encerrar programa\n \t1.Cadastrar novo contêiner\n \t2.Consultar contêiner por ID\n \t3.Consultar contêiner por CNPJ\n \t4.Lista de selecionados pelo porto destino\n \t5.Embarcar contêineres\n \t6.Relatório de contêineres embarcados" << endl;
        cin >> menu;
        if (menu == 0){//encerrar programa
            start = 0;
        }
        else if (menu == 1){//cadastro de novos contêineres
            cout << "\nID do contêiner: ";
            cin >> ID[i];
            cout << "\nCNPJ da empresa responsável pelo contêiner: ";
            cin >> CNPJ[i];
            cout << "\nDestino do contêiner: ";
            cin.ignore();//sem esta linha o programa não espera a entrada de Destino
            cin.getline(destino[i], Char2);
            cout << "\nValor do contêiner: R$";
            cin >> valor[i];
            status[i]=1;
            i++;
            }
        else if (menu == 2){//pesquisa por ID
            j=0;
            cout << "ID a ser pesquisado: ";
            cin >> ID_S;
            while(ID_S != ID[j] && j<N){
                j++;
                }
                cout << "************************************************************************************************"<<endl;
                cout << "ID: ";
                cout << ID[j];
                cout << "\t\tCNPJ: ";
                cout << CNPJ[j];
                cout << "\tDestino: ";
                cout << destino[j];
                cout << "\tValor do contêiner: R$";
                cout << valor[j];
                if(status[j]==1)
                    cout << "\tAguardando Embarcar"<<endl;
                else
                    cout << "\tEmbarcado"<<endl;
                cout << "************************************************************************************************"<<endl;
                }

        else if (menu == 3){//pesquisa por CNPJ
            j=0;
            cout << "CNPJ a ser pesquisado: ";
            cin.ignore();
            cin.getline(CNPJ_S, Char);
            for (j=0;j<N;j++){
                if(strcmpi(CNPJ_S, CNPJ[j])== 0 && j<N){
                    cout << "************************************************************************************************"<<endl;
                    cout << "ID: ";
                    cout << ID[j];
                    cout << "\tDestino: ";
                    cout << destino[j];
                    cout << "\tValor do contêiner: R$";
                    cout << valor[j];
                    if(status[j]==1)
                        cout << "\tAguardando Embarcar"<<endl;
                    else
                        cout << "\tEmbarcado"<<endl;
                    cout << "************************************************************************************************"<<endl;
                }

            }
        }
        else if (menu == 4){//pesquisa por destino
            j=0;
            cout << "Destino a ser pesquisado: ";
            cin.ignore();
            cin.getline(destino_S, Char2);
            cout << "\t********************************************Pesquisa por destino***********************************"<<endl;
            for (j=0;j<N;j++){
                if(strcmpi(destino_S, destino[j])== 0 && j<N){
                    cout << "ID: ";
                    cout << ID[j];
                    cout << "\tCNPJ: ";
                    cout << CNPJ[j];
                    cout << "\tValor do contêiner: R$";
                    cout << valor[j];
                    if(status[j]==1)
                        cout << "\tAguardando Embarcar"<<endl;
                    else
                        cout << "\tEmbarcado"<<endl;
                    cout << "\t***************************************************************************************************"<<endl;
                    }
                }
            }
        else if (menu == 5){//retirar contêineres
            cout << "Para qual destino deseja embarcar os contêineres: ";
            cin.ignore();
            cin.getline(embarcar, Char2);
            for(j=0;j<N;j++){
                if(strcmpi(embarcar, destino[j])==0 && j<N){
                    status[j] = 0;
                    embarcados[j]=true;
                }
            }
            cout << "Contêineres embarcados para " << embarcar << " com sucesso!" << endl;
        }
        else if (menu == 6){//relatório de embarcados
            cout << "\t***************************************Contêineres Embarcados****************************************"<<endl;
            for(j=0;j<N;j++){
                if(embarcados[j]==true){
                    cout << "ID: ";
                    cout << ID[j];
                    cout << "\tCNPJ: ";
                    cout << CNPJ[j];
                    cout << "\tEmbarcado para ";
                    cout << destino[j]<<endl;
                    cout << "\t***************************************************************************************************"<<endl;
                }
            }
            }
        }
    }



