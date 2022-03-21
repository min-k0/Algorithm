#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int arr3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == arr1[i % 5])
            score[0]++;
        if (answers[i] == arr2[i % 8])
            score[1]++;
        if (answers[i] == arr3[i % 10])
            score[2]++;
    }

    int maxScore = *max_element(score.begin(), score.end());
    for (int i = 0; i < 3; i++) {
        if (score[i] == maxScore) answer.push_back(i + 1);
    }

    return answer;
}
