#include <iostream>
#include <string>
#include <cmath> // for abs

using namespace std;

int main() {
    string S;
    cin >> S;

    // Create an array to store the positions of each character
    int pos[26];

    // Fill the array with positions of characters in S
    for (int i = 0; i < 26; i++) {
        pos[S[i] - 'A'] = i;
    }

    // Start from 'A'
    int total_distance = 0;
    int current_position = pos[0]; // position of 'A'

    // Calculate the distance to move to the next character
    for (char c = 'B'; c <= 'Z'; c++) {
        int next_position = pos[c - 'A'];
        total_distance += abs(next_position - current_position);
        current_position = next_position; // Move to the next character
    }

    // Output the result
    cout << total_distance << endl;

    return 0;
}
