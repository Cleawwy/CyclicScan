#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

struct Move {
    int start;
    int finish;
    int distance;
};

int main() {
    int initialPos;
    string direction;

    cout << "Enter initial arm position (0-199): ";
    cin >> initialPos;

    cout << "Enter direction (UP/DOWN): ";
    cin >> direction;

    cin.ignore();
    cout << "Enter track requests (space separated): ";

    string line;
    getline(cin, line);

    stringstream ssCount(line);
    int temp;
    int count = 0;

    while (ssCount >> temp) count++;

    int n = count;

    int *req = new int[n];

    stringstream ssFill(line);
    int idx = 0;
    while (ssFill >> temp) {
        req[idx++] = temp;
    }

    sort(req, req + n);

    Move *moves = new Move[n + 5];
    int moveCount = 0;

    long long total = 0;
    int current = initialPos;

    for (char &c : direction) c = toupper(c);

    if (direction == "UP") {

        int *up = new int[n];
        int *down = new int[n];
        int upCount = 0, downCount = 0;

        for (int i = 0; i < n; i++) {
            if (req[i] >= initialPos) up[upCount++] = req[i];
            else down[downCount++] = req[i];
        }

        for (int i = 0; i < upCount; i++) {
            moves[moveCount++] = {current, up[i], abs(up[i] - current)};
            total += abs(up[i] - current);
            current = up[i];
        }

        if (downCount > 0) {
            if (current != 199) {
                moves[moveCount++] = {current, 199, abs(199 - current)};
                total += abs(199 - current);
                current = 199;
            }

            moves[moveCount++] = {current, 0, 199};
            total += 199;
            current = 0;

            for (int i = 0; i < downCount; i++) {
                moves[moveCount++] = {current, down[i], abs(down[i] - current)};
                total += abs(down[i] - current);
                current = down[i];
            }
        }

        delete[] up;
        delete[] down;

    } else if (direction == "DOWN") {

        int *lower = new int[n];
        int *upper = new int[n];
        int lowCount = 0, highCount = 0;

        for (int i = 0; i < n; i++) {
            if (req[i] <= initialPos) lower[lowCount++] = req[i];
            else upper[highCount++] = req[i];
        }

        for (int i = lowCount - 1; i >= 0; i--) {
            moves[moveCount++] = {current, lower[i], abs(lower[i] - current)};
            total += abs(lower[i] - current);
            current = lower[i];
        }

        if (highCount > 0) {
            if (current != 0) {
                moves[moveCount++] = {current, 0, abs(current - 0)};
                total += abs(current - 0);
                current = 0;
            }

            moves[moveCount++] = {current, 199, 199};
            total += 199;
            current = 199;

            for (int i = highCount - 1; i >= 0; i--) {
                moves[moveCount++] = {current, upper[i], abs(upper[i] - current)};
                total += abs(upper[i] - current);
                current = upper[i];
            }
        }

        delete[] lower;
        delete[] upper;

    } else {
        cout << "Invalid direction.\n";
        return 1;
    }

    cout << "\nStart\tFinish\tDistance\n";
    for (int i = 0; i < moveCount; i++) {
        cout << moves[i].start << "\t"
             << moves[i].finish << "\t"
             << moves[i].distance << "\n";
    }

    cout << "-----------------------------\n";
    cout << "Total Track Travelled: " << total << "\n";

    delete[] req;
    delete[] moves;

    return 0;
}
