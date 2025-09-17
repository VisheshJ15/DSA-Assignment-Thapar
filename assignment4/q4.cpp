#include <iostream>
#include <queue>
#include <string>
using namespace std;

char firstNonRepeating(string s) {
    queue<char> q;
    int freq[256] = {0};

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
    }

    if (!q.empty())
        return q.front();
    return '#';
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char result = firstNonRepeating(s);

    if (result != '#')
        cout << "First non-repeating character: " << result << endl;
    else
        cout << "No non-repeating character found" << endl;

    return 0;
}