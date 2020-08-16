#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<vector<string>, string> Reversed(map<string, vector<string>>& bus_stop) {
    map<vector<string>, string> stop_bus;
    for (auto item : bus_stop) {
        stop_bus[item.second] = item.first;
    }
    return stop_bus;
}

void NEW_BUS(map<string, vector<string>>& bus_stop, string& bus, int& stop_count) {
    for (int i = 0; i < stop_count; ++i) {
        string stop;
        cin >> stop;
        bus_stop[bus].push_back(stop);
    }
}
void BUSES_FOR_STOP(map<string, vector<string>>& bus_stop, string& stop) {
    int count = 0;
    vector <string> result;
    bus_stop = Reversed(bus_stop);
    for (auto item : bus_stop) {
        for (auto str : item.first) {
            if (str == stop) {
                ++count;
                result.push_back(item.second);
            }
        }

    }
    if (count == 0) {
        cout << "No stop";
    }
    else {
        for (auto str : result) {
            cout << str << " ";
        }
    }
    bus_stop = Reversed(bus_stop);
    cout << endl;
}

void STOPS_FOR_BUS(map<string, vector<string>>& bus_stop, string& bus) {
    for (auto st : bus_stop[bus]) {
        int count = 0;
        vector <string> result;
        cout << "Stop " << st << ": ";
        bus_stop = Reversed(bus_stop);
        for (auto item : bus_stop) {
            for (auto str : item.first) {
                if (str == st) {
                    ++count;
                    result.push_back(item.second);
                }
            }

        }
        bus_stop = Reversed(bus_stop);
        if (count <= 1) {
            cout << "no interchange" << endl;
        }
        else {
            for (auto s : result) {
                cout << s << " ";
            }
            cout << endl;
        }
    }
}

void ALL_BUSES(map<string, vector<string>>& bus_stop) {
    if (bus_stop.size() == 0) {
        cout << "No buses";
    }
    else {
        for (auto item : bus_stop) {
            cout << "Bus " << item.first << ": ";
            for (auto str : item.second) {
                cout << str << " ";
            }
        }

    }
    cout << endl;
}

int main() {
    map<string, vector<string>> bus_stop;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;
            NEW_BUS(bus_stop, bus, stop_count);
        }
        if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            BUSES_FOR_STOP(bus_stop, stop);
        }
        if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            STOPS_FOR_BUS(bus_stop, bus);
        }
        if (command == "ALL_BUSES") {
            ALL_BUSES(bus_stop);
        }
    }
    return 0;
}