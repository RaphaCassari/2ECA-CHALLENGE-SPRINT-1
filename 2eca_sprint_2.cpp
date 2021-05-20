#include <iostream>
#include <cstring>
#include <locale>
#include <stdlib.h>

using namespace std;

#define n_projects 3     // Number os projects one less
#define n_participants 4 // Number of participants per project

struct participant
{
    char name[50];
    //char cpf[15] = "0";
    int cpf = 0;
};

struct project
{
    char name[50], url[50];
    struct participant type_participant[n_participants];
    float investment, note_1, note_2, note_3, avarage;
};

typedef struct project type_project;

int main()
{
    setlocale(LC_ALL, "");

    type_project projects[n_projects], swap_pos;
    char controller_n_projects[n_participants], controller_n_participants[n_participants];
    int cont_n_projects = 0, cont_n_participants, cont_for, cont_for_2, equal_averages = 0, winner;
    float high_avarage = 0;

    // Add the groups
    do
    {
        cont_n_participants = 0;

        cout << "\ntype the name of the project: ";
        cin.getline(projects[cont_n_projects].name, 50);
        cout << "Enter the project URL:";
        cin.getline(projects[cont_n_projects].url, 50);
        cout << "Enter the investment amount for the project:";
        cin >> projects[cont_n_projects].investment;
        cin.ignore();

        // Add the participants of the groups
        do
        {
            cout << "Name of the participant: ";
            cin.getline(projects[cont_n_participants].type_participant[cont_n_participants].name, 50);
            cout << "CPF of the participant: ";
            cin >> projects[cont_n_projects].type_participant[cont_n_participants].cpf;
            cin.ignore();
            //cin.getline(projects[cont_n_projects].type_participant[cont_n_participants].cpf, 15);
            cont_n_participants = cont_n_participants + 1;
            if (cont_n_participants < n_participants)
            {
                cout << "Type 'yes' to register another participant: ";
                cin.getline(controller_n_participants, n_participants);
            }
        } while ((strcmp(controller_n_participants, "yes") == 0) && (cont_n_participants < n_participants));

        cont_n_projects++;

        if (cont_n_projects < n_projects)
        {
            cout << "Type 'yes' to register another project: ";
            cin.getline(controller_n_projects, n_participants);
        };
    } while ((strcmp(controller_n_projects, "yes") == 0) && (cont_n_projects < n_projects));

    // Judges notes input
    for (cont_for = 0; cont_for < cont_n_projects; cont_for++)
    {
        cout << "\nJudge 1 insert the of the project " << cont_for + 1 << endl;
        cin >> projects[cont_for].note_1;
        cout << "Judge 2 insert the of the project " << cont_for + 1 << endl;
        cin >> projects[cont_for].note_2;
        cout << "Judge 3 insert the of the project " << cont_for + 1 << endl;
        cin >> projects[cont_for].note_3;
        projects[cont_for].avarage = (projects[cont_for].note_1 + projects[cont_for].note_2 + projects[cont_for].note_3) / 3;
    };

    // Displays projects with averages
    cout << " \n--- Result of projects ---" << endl;
    for (cont_for = 0; cont_for < cont_n_projects; cont_for++)
    {
        cout << "\nProject " << cont_for + 1 << ":" << endl;
        cout << "Name:" << projects[cont_for].name << endl;
        cout << "Avarage:" << projects[cont_for].avarage << endl;
    };

    // Metodo de ordenação Bubble Sort (Growing)
    for (cont_for = 0; cont_for < cont_n_projects - 1; cont_for++)
    {
        for (cont_for_2 = 0; cont_for_2 < cont_n_projects - cont_for - 1; cont_for_2++)
        {
            if (projects[cont_for_2].investment > projects[cont_for_2 + 1].investment)
            {
                swap_pos = projects[cont_for_2];
                projects[cont_for_2] = projects[cont_for_2 + 1];
                projects[cont_for_2 + 1] = swap_pos;
            }
        }
    }

    //Add 0.5 to the average of the 5 projects with the least investment
    for (cont_for = 0; cont_for <= cont_n_projects - 1; cont_for++)
    {
        projects[cont_for].avarage = projects[cont_for].avarage + 0.5;
        if (projects[cont_for].avarage > 10)
        {
            projects[cont_for].avarage = 10;
        }
    };

    // Discover the high avarage
    for (cont_for = 0; cont_for <= cont_n_projects - 1; cont_for++)
    {
        if (projects[cont_for].avarage > high_avarage)
            high_avarage = projects[cont_for].avarage;
    }

    // Check if there was a tie
    for (cont_for = 0; cont_for <= cont_n_projects - 1; cont_for++)
    {
        if (projects[cont_for].avarage == high_avarage)
            equal_averages++;
    }

    // Checks for a tie
    if (equal_averages > 1)
    {
        cout << "\nIt was a draw! " << equal_averages << " projects scored " << high_avarage << endl;
        for (cont_for = 0; cont_for <= n_projects - 1; cont_for++)
        {
            if (projects[cont_for].avarage == high_avarage)
            {
                cout << "\nProject " << cont_for + 1 << ":" << endl;
                cout << "Name: " << projects[cont_for].name << endl;
                cout << "Url: " << projects[cont_for].url << endl;
                cout << "Requested Investment: " << projects[cont_for].investment << endl;
                cout << "Avarage grade: " << projects[cont_for].avarage << endl;
            }
        }
        cout << "\nGentlemen judges, enter the number of the winning project: " << endl;
        cin >> winner;
        cout << "\nThe winning project was the " << projects[winner - 1].name << " !" << endl;
        cout << "Url: " << projects[winner - 1].url << endl;
        cout << "Requested Investment: " << projects[winner - 1].investment << endl;
        cout << "Note 1: " << projects[winner - 1].note_1 << endl;
        cout << "Note 2: " << projects[winner - 1].note_2 << endl;
        cout << "Note 3: " << projects[winner - 1].note_3 << endl;
        cout << "Avarage grade: " << projects[winner - 1].avarage << endl;
        for (cont_for = 0; cont_for <= n_projects - 1; cont_for++)
        {
            if (projects[winner - 1].type_participant[cont_for].cpf != 0)
            {
                cout << "Member " << cont_for + 1 << ":" << endl;
                cout << "Name:" << projects[winner - 1].type_participant[cont_for].name << endl;
                cout << "Cpf:" << projects[winner - 1].type_participant[cont_for].cpf << endl;
            }
        }
    }
    else
    {
        for (cont_for = 0; cont_for <= n_projects - 1; cont_for++)
        {
            if (projects[cont_for].avarage == high_avarage)
            {
                cout << "\nThe winning project was the " << projects[cont_for].name << " !" << endl;
                cout << "\nUrl: " << projects[cont_for].url << endl;
                cout << "Requested Investment: " << projects[cont_for].investment << endl;
                cout << "Note 1: " << projects[cont_for].note_1 << endl;
                cout << "Note 2: " << projects[cont_for].note_2 << endl;
                cout << "Note 3: " << projects[cont_for].note_3 << endl;
                cout << "Avarage grade: " << projects[cont_for].avarage << endl;
                for (cont_for = 0; cont_for <= n_projects - 1; cont_for++)
                {
                    if (projects[cont_for].type_participant[cont_for].cpf != 0) // strcmp(projects[cont_for].type_participant[cont_for].cpf, "0") != 0
                    {
                        cout << "\nMember " << cont_for + 1 << ":" << endl;
                        cout << "Name: " << projects[cont_for].type_participant[cont_for].name << endl;
                        cout << "Cpf: " << projects[cont_for].type_participant[cont_for].cpf << endl;
                    }
                }
            }
        }
    }
};
