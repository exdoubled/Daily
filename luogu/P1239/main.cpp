#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> counts(10, 0);

    for (int base = 1; base <= num; base *= 10) {
        int higher = num / (base * 10);
        int current = (num / base) % 10;
        int lower = num % base;

        for (int d = 0; d < 10; ++d) {
            if (d < current) {
                counts[d] += (higher + 1) * base;
            } else if (d == current) {
                counts[d] += higher * base + lower + 1;
            } else {
                counts[d] += higher * base;
            }
        }
    }

    for (int base = 1; base <= num; base *= 10) {
        counts[0] -= base;
    }

    for (int count : counts) {
        cout << count << endl;
    }

    return 0;
}