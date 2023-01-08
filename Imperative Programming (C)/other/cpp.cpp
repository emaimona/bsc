#include "../../stdc++.h"
#include <iostream>

using namespace std;
/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, std::vector<int> player) {
    vector<int> res;
    for (auto p: player) {
        if (p >= ranked[0]) {
            res.push_back(1);
            continue;
        }
        int cont = 1;
        int i = 1;
        while (i < ranked.size() && p < ranked[i]) {
            if (ranked[i] != ranked[i-1])
                cont++;
            i++;
        }
        res.push_back(cont+1);
    }
    
    return res;
}

int main()
{
    vector<int> ranked;
    vector<int> player;

    int rank;
    std::cin >> rank;

    while (rank--) {
        int n;
        std::cin >> n;
        ranked.push_back(n);
    }

    std::cin >> rank;

    while (rank--) {
        int n;
        std::cin >> n;
        player.push_back(n);
    }
    

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i]<<" ";

        if (i != result.size() - 1) {
            std::cout << "\n";
        }
    }


    return 0;
}