#include <bits/stdc++.h>
using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

const int MOD = 1e9 + 7;
const int INF = 1e9;

vector<int> getStartAndEndDateAsDays(string period)
{
    vector<int> periodInDays(2, 0);
    int startDays;
    string daysStart = period.substr(0, 2);
    string monthStart = period.substr(3, 2);
    startDays = stoi(daysStart) + ((stoi(monthStart) - 1) * 31);
    periodInDays[0] = startDays;
    int endDays;
    string daysEnd = period.substr(6, 2);
    string monthEnd = period.substr(9, 2);
    endDays = stoi(daysEnd) + ((stoi(monthEnd) - 1) * 31);
    if (endDays < startDays)
    {
        endDays += startDays;
    }
    periodInDays[1] = endDays;
    return periodInDays;
}

void solve(int collegues)
{
    vector<string> feriasVec;
    string ferias;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (collegues == 0)
    {
        cout << "Sim";
        return;
    }

    for (int i = collegues; i > 0; i--)
    {
        getline(cin, ferias);
        feriasVec.push_back(ferias);
    }
    vector<vector<int>> feriasColegas;
    for (string s : feriasVec)
    {
        feriasColegas.push_back(getStartAndEndDateAsDays(s));
    }
    getline(cin, ferias);
    vector<int> minhasFerias = getStartAndEndDateAsDays(ferias);
    for (vector<int> periodos : feriasColegas)
    {
        if ((minhasFerias[0] >= periodos[0] && minhasFerias[0] <= periodos[1]) || (minhasFerias[1] >= periodos[0] && minhasFerias[1] <= periodos[1]))
        {
            cout << "Nao" << endl;
            return;
        }
    }
    cout << "Sim" << endl;
}
int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    solve(t);
    return 0;
}