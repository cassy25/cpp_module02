#include "Fixed.hpp"

Fixed::Fixed()
{
    this->number = 0;
    return ;
}
 
Fixed::Fixed(const int value)
{
    this->number = value << nbBits;
    return ;
}

Fixed::Fixed(const float value)
{
    this->number = roundf(value * (1 << nbBits));
    return ;
}

Fixed::Fixed(const Fixed& copy)
{
    *this = copy;
    return ;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
        this->number = copy.number;
    return (*this);
}

Fixed::~Fixed()
{
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->number);
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

float Fixed::toFloat(void) const
{
    float num;
    num = static_cast<float>(number) / (1 << nbBits);
    return(num);
}

int Fixed::toInt(void) const
{
    int num;
    num = number >> 8;
    return (num);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &value)
{
    ostream << value.toFloat();
    return (ostream);
}

/* GESTION DES OPERATEURS DE COMPARAISONS*/

bool Fixed::operator==(Fixed const &value) const
{
    return (this->number == value.number);
}

bool Fixed::operator!=(Fixed const &value) const
{
    return !(*this == value);
}

bool Fixed::operator<(Fixed const &value) const
{
    return (this->number < value.number);
}

bool Fixed::operator>(Fixed const &value) const
{
    return value < *this;
}

bool Fixed::operator<=(Fixed const &value) const
{
    return !(value < *this);
}

bool Fixed::operator>=(Fixed const &value) const
{
    return !(*this < value);
}

/* GESTION DES OPERATEURS ARITHMETIQUES */

Fixed Fixed::operator+(Fixed const &value) const
{
    Fixed plus;
    plus.number = (this->number + value.number) >> nbBits;
    return (plus);
    //return Fixed(this->number + value.number);
}

Fixed Fixed::operator-(Fixed const &value) const
{
    Fixed sous;
    sous.number = (this->number - value.number) >> nbBits;
    return (sous);
    //return Fixed(this->number - value.number);
}

Fixed Fixed::operator*(Fixed const &value) const
{
    Fixed mult;
    mult.number = (this->number * value.number) >> nbBits;
    return (mult);
    //eturn Fixed(this->number * value.number);
}

Fixed Fixed::operator/(Fixed const &value) const
{
    Fixed div;
    div.number = (this->number / value.number) >> nbBits;
    return (div);
}

Fixed& Fixed::operator++()
{
    this->number++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->number++;
    return temp;
}

Fixed& Fixed::operator--()
{
    number -= 1 << nbBits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

/* AJOUT DES FONCTIONS MAX ET MIN*/

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
    if (num1 > num2)
        return num2;
    return num1;
}

const Fixed& Fixed::min(Fixed const &num1, Fixed const &num2)
{
    if (num1 > num2)
        return num2;
    return num1;
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
    if (num1 > num2)
        return num1;
    return num2;
}

const Fixed& Fixed::max(Fixed const &num1, Fixed const &num2)
{
    if (num1 > num2)
        return num1;
    return num2;
}