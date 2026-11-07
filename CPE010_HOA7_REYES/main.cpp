#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxSize = 100;

// =============================
// FIND SMALLEST
// =============================
template <typename T>
int routineSmallest(T arr[], int K, int maxSize){
    int small = K;
    for (int i = K + 1; i < maxSize; i++){
        if (arr[i] < arr[small])
            small = i;
    }
    return small;
}

// =============================
// SELECTION SORT
// =============================
template <typename T>
void selectionSort(T arr[], int maxSize){
    for (int i = 0; i < maxSize - 1; i++){
        int small = routineSmallest(arr, i, maxSize);
        T temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

// =============================
// COUNT VOTES
// =============================
template <typename T>
int CountVotes(T arr[], int maxSize, T candidate){
    int count = 0;
    for (int i = 0; i < maxSize; i++){
        if (arr[i] == candidate)
            count++;
    }
    return count;
}

// =============================
// MAIN
// =============================
int main(){
    int arr[maxSize];

    string candidates[5] =
    {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(time(0));
    // Generate random votes from 1 to 5
    for (int i = 0; i < maxSize; i++)
        arr[i] = (rand() % 5) + 1;


    // Sort array
    selectionSort(arr, maxSize);

    // Display sorted array
    cout << "SORTED ARRAY:" << endl;

    for (int i = 0; i < maxSize; i++){
        cout << arr[i] << " ";
        if ((i + 1) % 20 == 0)
            cout << endl;
    }


    // Count votes
    int votes[5];
    cout << endl;
    cout << "VOTE RESULTS:" << endl;

    for (int i = 0; i < 5; i++){
        votes[i] = CountVotes(arr, maxSize, i + 1);
        cout << "Candidate " << i + 1
             << " - " << candidates[i]
             << ": " << votes[i]
             << " votes" << endl;
    }

    // Find winner
    int winner = 0;
    for (int i = 1; i < 5; i++){
        if (votes[i] > votes[winner])
            winner = i;
    }

    // Display winner
    cout << endl;
    cout << "==============================" << endl;
    cout << "WINNING CANDIDATE" << endl;
    cout << "==============================" << endl;
    cout << "Candidate " << winner + 1
         << ": " << candidates[winner] << endl;
    cout << "Total Votes: "
         << votes[winner] << endl;

    return 0;
}
