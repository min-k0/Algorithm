#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, sum = 0;
    cin >> n >> m;

    vector<string> dna(n);
    vector<char> res;

    for (int i = 0; i < n; i++)
        cin >> dna[i];

    for (int idx = 0; idx < m; idx++)
    {
        vector<int> num(4, 0); // A,C,G,T 순

        for (int i = 0; i < n; i++)
        {
            if (dna[i][idx] == 'A') num[0]++;
            else if (dna[i][idx] == 'C') num[1]++;
            else if (dna[i][idx] == 'G') num[2]++;
            else if (dna[i][idx] == 'T') num[3]++;
        }

        int maxIdx = max_element(num.begin(), num.end()) - num.begin();

        if (maxIdx == 0) res.push_back('A');
        else if (maxIdx == 1) res.push_back('C');
        else if (maxIdx == 2) res.push_back('G');
        else if (maxIdx == 3) res.push_back('T');
    }

    
    for (int i = 0; i < n; i++)
        for (int idx = 0; idx < m; idx++)
        {
            if (dna[i][idx] != res[idx]) sum++;
        }

    for (int i = 0; i < m; i++)
        cout << res[i];
    cout << "\n" << sum;

    return 0;
}
