#include <iostream>
#include <vector>
#include <string>
using namespace std;
void ADD(vector<vector<string>>& diary, int& number, string& task){
    diary[number-1].push_back(task);
}
void DUMP(vector<vector<string>>& diary, int& number){
    int sum;
    sum = diary[number - 1].size();
    cout << sum << " ";
    for (auto task : diary[number - 1]){
        cout << task << " ";
    }
    cout << endl;
}


int main(){
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currently_month = 0;
    vector<vector<string>> diary(months[currently_month]);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;
        if (command == "NEXT"){
            ++currently_month;
            if (currently_month == 12) {
                currently_month = 0;
            }
            if (months[currently_month] >= months[currently_month - 1]) {
                diary.resize(months[currently_month]);
            }
            else {
                vector<vector<string>> temp(months[currently_month]);
                for (int i = 0; i < months[currently_month]; ++i) {
                    temp[i] = diary[i];
                }
                for (int i = months[currently_month]; i < months[currently_month - 1]; ++i) {
                    for (auto s : diary[i]) {
                        temp[months[currently_month] - 1].push_back(s);
                    }
                }
                diary = temp;
            }
        }
        if (command == "ADD"){
            int number;
            cin >> number;
            string task;
            cin >> task;
            ADD(diary, number, task);
        }
        if (command == "DUMP"){
            int number;
            cin >> number;
            DUMP(diary, number);
        }
    }
    return 0;
}