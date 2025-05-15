#include <bits/stdc++.h>
using namespace std;

int dateToDayOfYear(const string &date)
{
    static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int total = day;
    for (int i = 1; i < month; ++i)
        total += daysInMonth[i];
    return total;
}

pair<int, int> parsePeriod(string line)
{
    return {
        dateToDayOfYear(line.substr(0, 5)),
        dateToDayOfYear(line.substr(6, 5))};
}

void solve(int collegues)
{
    vector<pair<int, int>> feriasColegas;
    string line;
    getline(cin, line);

    for (int i = 0; i < collegues; i++)
    {
        getline(cin, line);
        feriasColegas.push_back(parsePeriod(line));
    }

    getline(cin, line);
    auto minhasFerias = parsePeriod(line);

    for (auto [ini, fim] : feriasColegas)
    {
        if (!(minhasFerias.second < ini || minhasFerias.first > fim))
        {
            cout << "Nao\n";
            return;
        }
    }
    cout << "Sim\n";
}

int main()
{
    int t = 1;
    cin >> t;
    solve(t);
    return 0;
}