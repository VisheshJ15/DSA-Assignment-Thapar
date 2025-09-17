#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even" << endl;
        return;
    }

    int halfSize = n / 2;
    queue<int> firstHalf, secondHalf;

    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(secondHalf.front());
        secondHalf.pop();
    }
}

void show(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 8; i++) {
        q.push(i);
    }

    cout << "Original Queue: ";
    show(q);

    interleave(q);

    cout << "Interleaved Queue: ";
    show(q);

    return 0;
}