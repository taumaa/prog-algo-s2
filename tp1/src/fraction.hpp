#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();

    Fraction operator+(Fraction const& f) const;
    Fraction operator-(Fraction const& f) const;
    Fraction operator*(Fraction const& f) const;
    Fraction operator/(Fraction const& f) const;

    bool operator==(Fraction const& f) const;
    bool operator!=(Fraction const& f) const;

    bool operator<(Fraction const& f) const;
    bool operator>(Fraction const& f) const;
    bool operator<=(Fraction const& f) const;
    bool operator>=(Fraction const& f) const;

    Fraction& operator*= (Fraction const& f);
    Fraction& operator/= (Fraction const& f);
    Fraction& operator+= (Fraction const& f);
    Fraction& operator-= (Fraction const& f);

    float to_float() const;
    operator float() const;
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);