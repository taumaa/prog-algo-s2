#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

// Surcharge operator +
Fraction Fraction::operator+(Fraction const& f) const {
    return simplify({
    numerator * f.denominator + f.numerator * denominator,
    denominator * f.denominator
    });
}

Fraction Fraction::operator-(Fraction const& f) const {
    return simplify({
        numerator * f.denominator - f.numerator * denominator,
        denominator * f.denominator
    });
}

Fraction Fraction::operator*(Fraction const& f) const {
    return simplify({
        numerator * f.numerator,
        denominator * f.denominator
    });
}

Fraction Fraction::operator/(Fraction const& f) const {
    return simplify({
        numerator * f.denominator,
        denominator * f.numerator
    });
}

bool Fraction::operator==(Fraction const& f) const {

    Fraction f1 = simplify(*this);
    Fraction f2 = simplify(f);

    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

bool Fraction::operator!=(Fraction const& f) const {
    return !(*this == f);
}






bool Fraction::operator<(Fraction const& f) const {
    // a/b < c/d <=> a*d < c*b
    return numerator * f.denominator < f.numerator * denominator;
}

bool Fraction::operator>(Fraction const& f) const {
    return f < *this;
}

bool Fraction::operator<=(Fraction const& f) const {
    return !(*this > f);
}

bool Fraction::operator>=(Fraction const& f) const {
    return !(*this < f);
}






Fraction& Fraction::operator+=(Fraction const& f) {
    *this = *this + f;
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& f) {
    *this = *this - f;
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f) {
    *this = *this * f;
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& f) {
    *this = *this / f;
    return *this;
}

float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}