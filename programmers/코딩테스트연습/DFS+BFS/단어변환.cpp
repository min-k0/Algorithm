#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int dist[51];
int arr[51][51];
int wordsSize;

bool check(string a, string b)
{
    int cnt = 0;
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b[i]) cnt++;
    if (cnt == a.size() - 1)
        return true;
    else return false;
}

bool bfs(int beginIdx, int targetIdx)
{
    queue<int> q;
    q.push(beginIdx);
    dist[beginIdx] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        //cout << cur << ", dist = " << dist[cur] << "\n";
        if (cur == targetIdx)
            return true;
        q.pop();

        for (int i = 0; i < wordsSize; i++)
        {
            if (arr[cur][i] == 1 && dist[i] == 0)
            {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int beginIdx, targetIdx = -1;

    words.push_back(begin);
    wordsSize = words.size();

    for (int i = 0; i < wordsSize; i++)
    {
        if (begin == words[i])
            beginIdx = i;
        if (target == words[i])
            targetIdx = i;
        for (int j = i + 1; j < wordsSize; j++)
            if (check(words[i], words[j]))
            {
                arr[i][j] = 1;
                arr[j][i] = 1;
            }
    }
    if (targetIdx == -1)
        return 0;

    if (bfs(beginIdx, targetIdx))
        answer = dist[targetIdx];
    else
        answer = 0;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> word;
    word = { "hot", "dot", "dog", "lot", "log"};

    cout << solution("hit", "cog", word);

    return 0;
}
