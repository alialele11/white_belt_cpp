#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;

int NOD(int& a, int& b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}
class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        numerator_rat = 0;
        denominator_rat = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        numerator_rat = numerator;
        denominator_rat = denominator;
        nod = gcd(numerator, denominator);
        if (nod > 1) {
            numerator_rat = numerator_rat / nod;
            denominator_rat = denominator_rat / nod;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        if (numerator_rat < 0 && denominator_rat < 0 || numerator_rat >= 0 && denominator_rat >= 0) {
            if (numerator_rat >= 0) {
                return numerator_rat;
            }
            else {
                return -numerator_rat;
            }
        }
        else {
            if (numerator_rat > 0) {
                return -numerator_rat;
            }
            else {
                return numerator_rat;
            }
        }

    }

    int Denominator() const {
        // Реализуйте этот метод
        if (numerator_rat == 0) {
            return  1;
        }
        else {
            if (denominator_rat < 0) {
                return -denominator_rat;
            }
            else {
                return denominator_rat;
            }
        }
    }

private:
    // Добавьте поля
    int numerator_rat;
    int denominator_rat;
    int nod;
};
Rational operator + (Rational r, Rational s) {
    Rational result;
    if (r.Denominator() == s.Denominator()) {
        result = Rational(r.Numerator() + s.Numerator(), r.Denominator());
    }
    else {
        result = Rational(r.Numerator() * s.Denominator() + s.Numerator() * r.Denominator(), r.Denominator() * s.Denominator());
    }
    return result;
}
Rational operator - (Rational r, Rational s) {
    Rational result;
    if (r.Denominator() == s.Denominator()) {
        result = Rational(r.Numerator() - s.Numerator(), r.Denominator());
    }
    else {
        result = Rational(r.Numerator() * s.Denominator() - s.Numerator() * r.Denominator(), r.Denominator() * s.Denominator());
    }
    return result;
}
bool operator==(const Rational& r, const Rational& s) {
    bool a = r.Numerator() == s.Numerator();
    bool b = r.Denominator() == s.Denominator();
    return a && b;
}
Rational operator * (Rational r, Rational s) {
    Rational result;
    result = Rational(r.Numerator() * s.Numerator(), r.Denominator() * s.Denominator());
    return result;
}
Rational operator / (Rational r, Rational s) {
    Rational result;
    result = r * Rational(s.Denominator(), s.Numerator());
    return result;
}

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& r) {
    int p;
    int q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = Rational(p, q);
    }
    return stream;
}

bool operator <(const Rational& r, const Rational& s) {
    if (r.Denominator() == s.Denominator()) {
        return r.Numerator() < s.Numerator();
    }
    else {
        return r.Numerator() * s.Denominator() < s.Numerator() * r.Denominator();
    }
}


