#include <iostream>
#include <algorithm>
using namespace std;

struct Project
{
    int id;
    string name;
    float budget;
    float impact;
    float ratio;
};

bool compare(Project a, Project b)
{
    return a.ratio > b.ratio;
}

int main()
{
    Project p[100];

    int n;
    float totalBudget;

    cout << "=============================================\n";
    cout << " RESEARCH GRANT ALLOCATION OPTIMIZER\n";
    cout << " Fractional Knapsack Algorithm\n";
    cout << "=============================================\n\n";

    cout << "Enter Total Research Budget (in Lakh): ";
    cin >> totalBudget;

    cout << "Enter Number of Research Projects: ";
    cin >> n;

    cin.ignore();

    for(int i=0;i<n;i++)
    {
        cout << "\nProject " << i+1 << endl;

        p[i].id=i+1;

        cout << "Project Name : ";
        getline(cin,p[i].name);

        cout << "Budget Required (Lakh): ";
        cin >> p[i].budget;

        cout << "Impact Score : ";
        cin >> p[i].impact;

        p[i].ratio = p[i].impact / p[i].budget;

        cin.ignore();
    }

    sort(p,p+n,compare);

    float remainingBudget = totalBudget;
    float totalImpact = 0;

    cout << "\n\n============== Grant Allocation ==============\n";

    cout << "---------------------------------------------------------------\n";
    cout << "ID\tProject\t\t\tAllocated Budget\n";
    cout << "---------------------------------------------------------------\n";

    for(int i=0;i<n;i++)
    {
        
        if(remainingBudget==0)
            break;

        if(p[i].budget<=remainingBudget)
        {
            cout << p[i].id << "\t"
                 << p[i].name << "\t\t"
                 << p[i].budget << " Lakh (Full)\n";

            remainingBudget -= p[i].budget;

            totalImpact += p[i].impact;
        }
        else
        {
            float fraction = remainingBudget / p[i].budget;

            cout << p[i].id << "\t"
                 << p[i].name << "\t\t"
                 << remainingBudget << " Lakh (Partial)\n";

            totalImpact += p[i].impact * fraction;

            remainingBudget = 0;
        }
    }

    cout << "\n=============================================\n";
    cout << "Budget Utilized : "
         << totalBudget-remainingBudget
         << " Lakh\n";

    cout << "Remaining Budget : "
         << remainingBudget
         << " Lakh\n";

    cout << "Total Research Impact : "
         << totalImpact
         << endl;

    cout << "=============================================\n";

    return 0;
}
