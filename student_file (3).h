#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> reorderVector(vector<int> data, int loser, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (data[i] == loser) {
            swap(data[i], data[size - 1]);
        }
    }
    return data;
}

vector<int> Torneo(vector<int> skills, int roundsToWin, int totalRounds) {
    int size = skills.size();
    int winner = 0;
    int loser = 0;

    queue<int> playerQueue;

    for (int i = 2; i < size; i++) {
        playerQueue.push(skills[i]);
    }

    int roundsWon = 0;
    int player1 = skills[0];
    int player2 = skills[1];

    vector<int> result(2);
    while (totalRounds > 0) {
        if (player1 > player2) {
            roundsWon++;
            result = {player2, player1};
            playerQueue.push(player2);
        } else {
            roundsWon = 1;
            result = {player1, player2};
            playerQueue.push(player1);
            player1 = player2;
        }

        if (roundsWon == roundsToWin) {
            playerQueue.push(player1);
            player1 = playerQueue.front();
            playerQueue.pop();
            roundsWon = 0;
        }
        player2 = playerQueue.front();
        playerQueue.pop();

        totalRounds--;
    }

    return result;
}