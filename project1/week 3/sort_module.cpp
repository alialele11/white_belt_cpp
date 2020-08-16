#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool Modul(vector<int>& x) {
    for (auto& item : x) {
        if (item <= 0) {
            item = -item;
        }
    }
}
int main() {
    int N;
    cin >> N;
    vector<int> number(N);
    for (int i = 0; i < N; ++i) {
        cin >> number[i];
    }
    sort(begin(number), end(number), Modul);
    for (const auto& item : number) {
        cout << item << " ";
    }
    return 0;
}