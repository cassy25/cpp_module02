/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:12:13 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/11/29 14:12:14 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number = 0;
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
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        number = copy.number;
    getRawBits();
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