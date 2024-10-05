#include <iostream>
#include <string>

using namespace std;

#include <iostream>

using namespace std;

int countWays(const int sum, int& withoutAllCoins, int& coin2opt, int& coin5opt, int& coin9opt) {
    int maxCount = 0;
    withoutAllCoins = 0;
    int minCoins = sum;

    for (int c9 = 0; c9 <= sum / 9; ++c9) 
    {
        for (int c5 = 0; c5 <= (sum - 9 * c9) / 5; ++c5) 
        {
            int remainSum = sum - 9 * c9 - 5 * c5;
            if (remainSum % 2 == 0) {
                int c2 = remainSum / 2;
                maxCount++;

                if (c9 == 0 || c5 == 0 || c2 == 0) {
                    withoutAllCoins++;
                }

                int totalCoins = c9 + c5 + c2;
                if (totalCoins < sum) {
                    minCoins = totalCoins;
                    coin2opt = c2;
                    coin5opt = c5;
                    coin9opt = c9;
                }
            }
        }
    }

    return maxCount;
}

int main() {
    cout << "Input sum\n";
    int sum = 0;
    cin >> sum;
    int withoutAllCoins = 0;
    int coin2opt = 0, coin5opt = 0, coin9opt = 0;

    int totalWays = countWays(sum, withoutAllCoins, coin2opt, coin5opt, coin9opt);

    cout << "1. " << totalWays << endl;
    cout << "2. " << withoutAllCoins << endl;
    cout << "3. " << coin2opt << "*2 + " << coin5opt << "*5 + " << coin9opt << "*9" << endl;

    return 0;
}
