/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:12:18 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/11/29 14:12:20 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Fixed
{
    public:
        Fixed(); //Constructeur par default
        Fixed(const Fixed& copy); // Copie du constructeur
        Fixed& operator=(const Fixed& copy);
        ~Fixed(); //Destructeur
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int number;
        static const int number2 = 8;
};

#endif
