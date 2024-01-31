#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& copy);
        ~Fixed();
        float toFloat(void) const;
        int toInt (void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        bool operator==(Fixed const &value) const;
        bool operator!=(Fixed const &value) const;
        bool operator<(Fixed const &value) const;
        bool operator>(Fixed const &value) const;
        bool operator<=(Fixed const &value) const;
        bool operator>=(Fixed const &value) const;
        Fixed operator+(Fixed const &value) const;
        Fixed operator-(Fixed const &value) const;
        Fixed operator*(Fixed const &value) const;
        Fixed operator/(Fixed const &value) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        static Fixed& min(Fixed &num1, Fixed &num2);
        static const Fixed& min(Fixed const &num1, Fixed const &num2);
        static Fixed& max(Fixed &num1, Fixed &num2);
        static const Fixed& max(Fixed const &num1, Fixed const &num2);
    private:
        int number;
        static const int nbBits = 8;
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &value);

#endif