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

    // Declares variables
    int cont, cont_juror;
    char cpfs[n_projects][n_cpf];
    char urls[n_projects][50]; // Implementar alocação dinamica
    float judge1[n_projects];
    float judge2[n_projects];
    float judge3[n_projects];
    float average[n_projects];
    float high_average;
    float equal_averages[n_projects];

    // Add project data
    for (cont = 1; cont <= n_projects; cont++)
    {
        cout << "\nAdd project data number" << cont << ":" << endl;
        cout << "Project CPF: ";
        cin >> cpfs[cont - 1];
        cout << "Project URL:";
        cin.ignore();
        cin.getline(urls[cont - 1], 50);
    }

    // Add Judges' Note
    for (cont_juror = 1; cont_juror <= n_projects; cont_juror++)
    {
        cout << "\nJuror number 1 insert project note " << cont_juror << ":" << endl;
        cin >> judge1[cont_juror - 1];
    }
    for (cont_juror = 1; cont_juror <= n_projects; cont_juror++)
    {
        cout << "Juror number 2 insert project note " << cont_juror << ":" << endl;
        cin >> judge2[cont_juror - 1];
    }
    for (cont_juror = 1; cont_juror <= n_projects; cont_juror++)
    {
        cout << "Juror number 3 insert project note " << cont_juror << ":" << endl;
        cin >> judge3[cont_juror - 1];
    }
    for (cont = 0; cont <= n_projects - 1; cont++)
    {
        average[cont] = (judge1[cont] + judge2[cont] + judge3[cont]) / 3;
    }

    // See the highest average
    high_average = average[0];
    for (cont = 0; cont <= n_projects - 1; cont++)
    {
        if (average[cont] > high_average)
        {
            high_average = average[cont];
        }
    }

    // Display winner data
    cout << "\nWinner(s) with average " << high_average << " is/are:" << endl;
    for (cont = 0; cont <= n_projects - 1; cont++)
    {
        if (average[cont] == high_average)
        {
            cout << "\nProject " << cont + 1 << ":" << endl;
            cout << "Cpf: " << cpfs[cont] << endl;
            cout << "Url: " << urls[cont] << endl;
        }
    }
}
