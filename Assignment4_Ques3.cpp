#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even.\n";
        return;
    }

    queue<int> firstHalf;

    for (int i = 0; i < n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int x;

    cout << "Enter 6 numbers: ";
    for (int i = 0; i < 6; i++) {
        cin >> x;
        q.push(x);
    }

    interleave(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
