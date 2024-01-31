/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:29:04 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/11/30 16:29:05 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    private:
        int number;
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &value);

#endif
