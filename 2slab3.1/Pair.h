#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class Pair {
private:
    int first;
    int second;

public:

    Pair() : first(0), second(0) {}

    Pair(int a, int b) : first(a), second(b) {}

    bool operator==(const Pair& other) const {
        return (first == other.first) && (second == other.second);
    }

    Pair operator-(const Pair& other) const {
        return Pair(first - other.first, second - other.second);
    }

    Pair operator*(const Pair& other) const {
        return Pair(first * other.first, second * other.second);
    }

    int getFirst() const {
        return first;
    }

    int getSecond() const {
        return second;
    }

    void setFirst(int a) {
        first = a;
    }

    void setSecond(int b) {
        second = b;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Pair& pair) {
        is >> pair.first >> pair.second;
        return is;
    }

    operator std::string() const {
        return "(" + std::to_string(first) + ", " + std::to_string(second) + ")";
    }
};