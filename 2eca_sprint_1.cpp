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
    int cont, cont_juror, equal_averages, winner;
    char cpfs[n_projects][n_cpf];
    char urls[n_projects][50]; // Implementar alocação dinamica
    float judge1[n_projects];
    float judge2[n_projects];
    float judge3[n_projects];
    float average[n_projects];
    float high_average;

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

    // Displays the overall result of all projects
    cout << "\nOverall result of the projects:" << endl;
    for (cont = 0; cont <= n_projects - 1; cont++)
    {
        cout << "\nProject " << cont + 1 << ":" << endl;
        cout << "Avarage: " << average[cont] << endl;
        cout << "Cpf: " << cpfs[cont] << endl;
        cout << "Url: " << urls[cont] << endl;
    }

    // Check if there was a tie
    equal_averages = 0;
    for (cont = 0; cont <= n_projects - 1; cont++)
    {
        if (average[cont] == high_average)
        {
            equal_averages++;
        }
    }

    // Display winner data
    if (equal_averages > 1)
    {
        cout << "\nIt was a draw! " << equal_averages << " projects scored " << high_average << endl;
        for (cont = 0; cont <= n_projects - 1; cont++)
        {
            if (average[cont] == high_average)
            {
                cout << "\nProject " << cont + 1 << ":" << endl;
                cout << "Cpf: " << cpfs[cont] << endl;
                cout << "Url: " << urls[cont] << endl;
            }
        }
        cout << "Gentlemen judges, enter the number of the winning project." << endl;
        cin >> winner;
        cout << "\nThe winning project was the " << winner << "!" << endl;
        cout << "\nProject " << winner << ":" << endl;
        cout << "Cpf: " << cpfs[(winner - 1)] << endl;
        cout << "Url: " << urls[(winner - 1)] << endl;
    }
    else
    {
        for (cont = 0; cont <= n_projects - 1; cont++)
        {
            if (average[cont] == high_average)
            {
                cout << "the winning project was the " << cont << endl;
                cout << "\nProject " << cont + 1 << ":" << endl;
                cout << "Cpf: " << cpfs[cont] << endl;
                cout << "Url: " << urls[cont] << endl;
            }
        }
    }
}
