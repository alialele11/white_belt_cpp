#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        f_n[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        l_n[year] = last_name;
    }

    string GetFullName(int& year) {
        string result = "";
        int f_min_year;
        int l_min_year;
        auto it_f = f_n.lower_bound(year);
        auto it_l = l_n.lower_bound(year);
        if (f_n.size() == 0 && l_n.size() == 0) {
            result = "Incognito";
        }
        else if (f_n.size() != 0 && l_n.size() == 0) {
            f_min_year = (--f_n.end())->first;
            if (f_min_year > year) {
                result = "Incognito";
            }
            else {
                result = it_f->second + " with unknown last name";
            }
        }
        else if (f_n.size() == 0 && l_n.size() != 0) {
            l_min_year = (--l_n.end())->first;
            if (l_min_year > year) {
                result = "Incognito";
            }
            else {
                result = it_l->second + " with unknown first name";
            }
        }
        else {
            f_min_year = (--f_n.end())->first;
            l_min_year = (--l_n.end())->first;
            if (f_min_year > year && l_min_year > year) {
                result = "Incognito";
            }
            else {
                if (f_min_year <= year && l_min_year > year) {
                    result = it_f->second + " with unknown last name";
                }
                else if (f_min_year > year && l_min_year <= year) {
                    result = it_l->second + " with unknown first name";
                }
                else {
                    result = it_f->second + " " + it_l->second;
                }
            }
        }
        return result;
    }
    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        string result = "";
        int f_min_year;
        int l_min_year;
        auto it_f = f_n.lower_bound(year);
        auto it_l = l_n.lower_bound(year);
        if (f_n.size() == 0 && l_n.size() == 0) {
            result = "Incognito";
        }
        else if (f_n.size() != 0 && l_n.size() == 0) {
            f_min_year = (--f_n.end())->first;
            if (f_min_year > year) {
                result = "Incognito";
            }
            else {
                result = it_f->second;
                bool condition = 0;
                for (auto it = next(it_f); it != f_n.end(); ++it) {
                    if (it == next(it_f)) {
                        if (it->second != result) {
                            condition = 1;
                            result = result + " (" + it->second;
                        }
                    }
                    else {
                        if (it->second != prev(it)->second) {
                            if (condition) {
                                result = result + ", " + it->second;
                            }
                            else {
                                result = result + " (" + it->second;
                                condition = 1;
                            }
                        }
                    }
                }
                if (condition) {
                    result = result + ")";
                }
                result += " with unknown last name";
            }
        }
        else if (f_n.size() == 0 && l_n.size() != 0) {
            l_min_year = (--l_n.end())->first;
            if (l_min_year > year) {
                result = "Incognito";
            }
            else {
                result = it_l->second;
                bool condition = 0;
                for (auto it = next(it_l); it != l_n.end(); ++it) {
                    if (it == next(it_l)) {
                        if (it->second != result) {
                            condition = 1;
                            result = result + " (" + it->second;
                        }
                    }
                    else {
                        if (it->second != prev(it)->second) {
                            if (condition) {
                                result = result + ", " + it->second;
                            }
                            else {
                                result = result + " (" + it->second;
                                condition = 1;
                            }
                        }
                    }

                }
                if (condition) {
                    result = result + ")";
                }
                result += " with unknown first name";
            }
        }
        else {
            f_min_year = (--f_n.end())->first;
            l_min_year = (--l_n.end())->first;
            if (f_min_year > year && l_min_year > year) {
                result = "Incognito";
            }
            else {
                if (f_min_year <= year && l_min_year > year) {
                    result = it_f->second;
                    bool condition = 0;
                    for (auto it = next(it_f); it != f_n.end(); ++it) {
                        if (it == next(it_f)) {
                            if (it->second != result) {
                                condition = 1;
                                result = result + " (" + it->second;
                            }
                        }
                        else {
                            if (it->second != prev(it)->second) {
                                if (condition) {
                                    result = result + ", " + it->second;
                                }
                                else {
                                    result = result + " (" + it->second;
                                    condition = 1;
                                }
                            }
                        }
                    }
                    if (condition) {
                        result = result + ")";
                    }
                    result += " with unknown last name";
                }
                else if (f_min_year > year && l_min_year <= year) {
                    result = it_l->second;
                    bool condition = 0;
                    for (auto it = next(it_l); it != l_n.end(); ++it) {
                        if (it == next(it_l)) {
                            if (it->second != result) {
                                condition = 1;
                                result = result + " (" + it->second;
                            }
                        }
                        else {
                            if (it->second != prev(it)->second) {
                                if (condition) {
                                    result = result + ", " + it->second;
                                }
                                else {
                                    condition = 1;
                                    result = result + " (" + it->second;
                                }
                            }
                        }
                    }
                    if (condition) {
                        result = result + ")";
                    }
                    result += " with unknown first name";
                }
                else {
                    result = it_f->second;
                    bool con = 0;
                    for (auto it = next(it_f); it != f_n.end(); ++it) {
                        if (it == next(it_f)) {
                            if (it->second != result) {
                                con = 1;
                                result = result + " (" + it->second;
                            }
                        }
                        else {
                            if (it->second != prev(it)->second) {
                                if (con) {
                                    result = result + ", " + it->second;
                                }
                                else {
                                	con = 1;
                                    result = result + " (" + it->second;
                                }
                            }
                        }
                    }
                    if (con) {
                        result = result + ")";
                    }
                    result = result + " " + it_l->second;
                    bool con_1 = 0;
                    for (auto it = next(it_l); it != l_n.end(); it++) {
                        if (it == next(it_l)) {
                            if (it->second != it_l->second) {
                                con_1 = 1;
                                result = result + " (" + it->second;
                            }
                        }
                        else {
                            if (it->second != prev(it)->second) {
                                if (con_1) {
                                    result = result + ", " + it->second;
                                }
                                else {
                                    con_1 = 1;
                                    result = result + " (" + it->second;
                                }
                            }
                        }
                    }
                    if (con_1) {
                        result = result + ")";
                    }
                }
            }
        }
        return result;
    }
private:
    map<int, string, greater<int>> f_n;
    map<int, string, greater<int>> l_n;
};

int main()
{

    return 0;
}
