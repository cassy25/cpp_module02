/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:29:00 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/11/30 16:29:01 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}
 
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->number = value << 8;

    return ;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(value * (1 << 8));
    return ;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &copy)
        this->number = copy.number;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number);
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

float Fixed::toFloat(void) const
{
    float num;
    num = static_cast<float>(number) / (1 << 8);
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