#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int number = 1;
    map<set<string>, int> stop_number;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int N;
        cin >> N;
        set<string> stops;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
             stops.insert(s);
        }
        if (stop_number.count(stops) == 0) {
            stop_number[stops] = number;
            cout << "New bus " << number << endl;
            ++number;
        }
        else {
            cout << "Already exists for " << stop_number[stops] << endl;
        }
    }
    return 0;
}