#include <iostream>
#include <set>
#include <map>
#include <string>
#include <exception>
#include <iomanip>
#include <sstream>
using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    Date(const int& year_input, const int& month_input, const int& day_input) {
        if (month_input < 1 || month_input > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(month_input));
        }
        else {
            if (day_input < 1 || day_input > 31) {
                throw invalid_argument("Day value is invalid: " + to_string(day_input));
            }
            else {
                year = year_input;
                month = month_input;
                day = day_input;
            }
        }
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
            return month;

    }
    int GetDay() const {
            return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    }
    else {
        return lhs.GetYear() < rhs.GetYear();
    }
}
bool operator ==(const Date& r, const Date& s) {
    return r.GetYear() == s.GetYear() && r.GetMonth() == s.GetMonth() && r.GetDay() == s.GetDay();
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        data[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        bool result = false;
        if (data.count(date) == 1) {
            if (data.at(date).count(event)) {
                result = true;
                data.at(date).erase(event);
            }
        }
        return result;
    }
    int  DeleteDate(const Date& date) {
        int result = 0;
        if (data.count(date) == 1) {
            result = data.at(date).size();
            data.erase(date);
        }
        return result;
    }
    void Find(const Date& date) const {
        for (auto item : data) {
            if (item.first == date) {
                for (auto s : item.second) {
                    cout << s << endl;
                }
            }
        }
    }
    void Print() const {
        for (auto item : data) {
            for (auto s : item.second) {
                cout << setw(4) << setfill('0') << item.first.GetYear() << '-';
                cout << setw(2) << setfill('0') << item.first.GetMonth() << '-';
                cout << setw(2) << setfill('0') << item.first.GetDay() << " ";
                cout << s;
                cout << endl;
            }
        }
    }
private:
    map<Date, set<string>> data;
};

int main() {
    try {
        Database db;
        string command;
        while (getline(cin, command)) {
            if (command != "") {
                stringstream in(command);
                string com;
                in >> com;
                // Считайте команды с потока ввода и обработайте каждую
                if (com == "Add") {
                    string date_input;
                    in >> date_input;
                    stringstream input(date_input);
                    int year_input;
                    int month_input;
                    int day_input;
                    if (input >> year_input && input.peek() == '-' && input.ignore(1) && input >> month_input && input.peek() == '-' && input.ignore(1) && input >> day_input && input.peek() == EOF) {
                        string event;
                        in >> event;
                        if (event != "") {
                            db.AddEvent(Date(year_input, month_input, day_input), event);
                        }
                    }
                    else {
                        throw invalid_argument("Wrong date format: " + date_input);
                    }
                }
                else if (com == "Del") {
                    string date_input;
                    in >> date_input;
                    stringstream input(date_input);
                    int year_input;
                    int month_input;
                    int day_input;
                    if (input >> year_input && input.peek() == '-' && input.ignore(1) && input >> month_input && input.peek() == '-' && input.ignore(1) && input >> day_input && input.peek() == EOF) {
                        string event;
                        in >> event;
                        if (event == "") {
                            int sum;
                            sum = db.DeleteDate(Date(year_input, month_input, day_input));
                            cout << "Deleted " << sum << " events" << endl;

                        }
                        else {
                            if (db.DeleteEvent(Date(year_input, month_input, day_input), event)) {
                                cout << "Deleted successfully" << endl;
                            }
                            else {
                                cout << "Event not found" << endl;
                            }
                        }
                    }
                    else {
                        throw invalid_argument("Wrong date format: " + date_input);
                    }

                }
                else if (com == "Find") {
                    string date_input;
                    in >> date_input;
                    stringstream input(date_input);
                    int year_input;
                    int month_input;
                    int day_input;
                    if (input >> year_input && input.peek() == '-' && input.ignore(1) && input >> month_input && input.peek() == '-' && input.ignore(1) && input >> day_input && input.peek() == EOF) {
                        db.Find(Date(year_input, month_input, day_input));
                    }
                    else {
                        throw invalid_argument("Wrong date format: " + date_input);
                    }

                }
                else if (com == "Print") {
                    db.Print();
                }
                else {
                    throw invalid_argument("Unknown command: " + command);
                }
            }

        }
    }
            catch (invalid_argument& rr) {
                cout << rr.what() << endl;
            }

    return 0;
}