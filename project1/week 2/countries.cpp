#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, string> Reversed(map<string, string>& country_capital){
    map<string, string> result;
    for (auto s : country_capital) {
        result[s.second] = s.first;
    }
    return result;
}
void CHANGE_CAPITAL(map<string, string>& country_capital, string& country, string& new_capital) {
    if (country_capital.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    }
    else if (country_capital[country] == new_capital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    }
    else {
        cout << "Country " << country << " has changed its capital from " << country_capital[country] << " to " << new_capital << endl;
    }
    country_capital[country] = new_capital;
}
void RENAME(map<string, string>& country_capital, string& old_country_name, string& new_country_name) {
    if (old_country_name == new_country_name || country_capital.count(old_country_name) == 0 || country_capital.count(new_country_name)) {
        cout << "Incorrect rename, skip" << endl;
    }
    else {
        string name;
        name = country_capital[old_country_name];
        country_capital = Reversed(country_capital);
        country_capital[name] = new_country_name;
        country_capital = Reversed(country_capital);
        cout << "Country " << old_country_name << " with capital " << name << " has been renamed to " << new_country_name << endl;
    }
}
void ABOUT(map<string, string>& country_capital, string& country) {
    if (country_capital.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else {
        cout << "Country " << country << " has capital " << country_capital[country] << endl;
    }
}
void DUMP(map<string, string>& country_capital) {
    if (country_capital.size() == 0) {
        cout << "There are no countries in the world" << endl;
    }
    else {
        for (auto item : country_capital) {
            cout << item.first << "/" << item.second << endl;
        }
    }
}
 
int main(){
    map<string, string> country_capital;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            CHANGE_CAPITAL(country_capital, country, new_capital);
        }
        if (command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            RENAME(country_capital, old_country_name, new_country_name);
        }
        if (command == "ABOUT") { 
            string country;
            cin >> country;
            ABOUT(country_capital, country);
        }
        if (command == "DUMP") {
            DUMP(country_capital);
        }
    }
    return 0;
}