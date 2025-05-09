#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int acharPai(int filho, int pais[])
{
    if (pais[filho] == filho)
        return filho;

    pais[filho] = acharPai(pais[filho], pais);

    return pais[filho];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> inputs;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> teste = {a, b, c};
        inputs.push_back(teste);
    }

    sort(inputs.begin(), inputs.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    int pais[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        pais[i] = i;
    }

    int soma = 0;

    for (vector<int> el : inputs)
    {
        int pai1 = acharPai(el[0], pais);
        int pai2 = acharPai(el[1], pais);

        if (pai1 == pai2)
            continue;

        pais[pai1] = pais[pai2];
        soma += el[2];
    }

    cout << endl
         << soma;

    return 0;
}