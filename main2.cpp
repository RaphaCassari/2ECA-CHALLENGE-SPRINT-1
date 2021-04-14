#include <iostream>
#include <cstring>
#include <locale>

#include <stdlib.h>

using namespace std;

#define n_projects 2 //Number os projects one less
#define n_cpf 12

int main()
{
    setlocale(LC_ALL, "");

    int cont, cont2, cont_juror;
    char cpfs[n_projects][n_cpf];
    char urls[n_projects][50]; // Implementar alocação dinamica
    float judge1[n_projects];
    float judge2[n_projects];
    float judge3[n_projects];
    float average[n_projects];

    for (cont = 1; cont <= n_projects; cont++)
    {
        /*
        cout << "Add project data number " << cont << endl;
        cout << "Cpf do Projeto: ";
        cin >> cpfs[(cont)];
        */

        cout << "Enter the project URL: ";
        cin.getline(urls[cont - 1], 50);
        cin.ignore();
    }
    /*
    for (cont2 = 0; cont2 <= n_projects; cont2++)
    {
        for (cont_juror = 1; cont_juror <= 3; cont_juror++)
            cout << "Juror number " << cont_juror << "insert project note" << cont2;
    }*/
}
