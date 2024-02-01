#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPairs(int K, vector<int>& subjectCredits, int N, vector<int>& creditLimits) {
    sort(subjectCredits.begin(), subjectCredits.end(), greater<int>());
    sort(creditLimits.begin(), creditLimits.end(), greater<int>());

    int maxPairsCount = 0;
    vector<bool> subjectTaken(K, false);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (!subjectTaken[j] && creditLimits[i] >= subjectCredits[j]) {
                subjectTaken[j] = true;
                ++maxPairsCount;
                break;
            }
        }
    }

    return maxPairsCount;
}

int main() {
    // Input
    int K, N;
    cout << "Enter the number of subjects (K): ";
    cin >> K;

    vector<int> subjectCredits(K);
    cout << "Enter the credits for each subject: ";
    for (int i = 0; i < K; ++i) {
        cin >> subjectCredits[i];
    }

    cout << "Enter the number of students (N): ";
    cin >> N;

    vector<int> creditLimits(N);
    cout << "Enter the credit limits for each student: ";
    for (int i = 0; i < N; ++i) {
        cin >> creditLimits[i];
    }

    // Calculate and output the result
    int result = maxPairs(K, subjectCredits, N, creditLimits);
    cout << "Maximum number of possible (subject, student) pairs: " << result << endl;

    return 0;
}
