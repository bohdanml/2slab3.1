#pragma once

#include <iostream>
#include <stdexcept>
#include "Pair.h"

class Rational {
private:
    Pair pair;

public:
    Rational(int a, int b) : pair(a, b) {
        if (b == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
    }

    Rational operator+(const Rational& other) const {
        return Rational(pair.getFirst() * other.pair.getSecond() + pair.getSecond() * other.pair.getFirst(),
            pair.getSecond() * other.pair.getSecond());
    }

    Rational operator-(const Rational& other) const {
        return Rational(pair.getFirst() * other.pair.getSecond() - pair.getSecond() * other.pair.getFirst(),
            pair.getSecond() * other.pair.getSecond());
    }

    Rational operator/(const Rational& other) const {
        if (other.pair.getFirst() == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return Rational(pair.getFirst() * other.pair.getSecond(), pair.getSecond() * other.pair.getFirst());
    }

    int getFirst() const {
        return pair.getFirst();
    }

    int getSecond() const {
        return pair.getSecond();
    }

    void setFirst(int a) {
        pair.setFirst(a);
    }

    void setSecond(int b) {
        if (b == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        pair.setSecond(b);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
        os << rational.pair;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rational& rational) {
        is >> rational.pair;
        if (rational.pair.getSecond() == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        return is;
    }

    operator std::string() const {
        return static_cast<std::string>(pair);
    }
};