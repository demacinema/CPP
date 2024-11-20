/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:34:16 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:34:17 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
							Fixed();
							Fixed(const int value);
							Fixed(const float value);
							~Fixed();
							Fixed(const Fixed& other);
		Fixed				&operator=(const Fixed& other);
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;
		Fixed				operator++(void);
		Fixed				operator++(int);
		Fixed				operator--(void);
		Fixed				operator--(int);
		bool				operator>(const Fixed &other) const;
		bool				operator<(const Fixed &other) const;
		bool				operator<=(const Fixed &other) const;
		bool				operator>=(const Fixed &other) const;
		bool				operator==(const Fixed &other) const;
		bool				operator!=(const Fixed &other) const;
		int					getRawBits(void) const;
		void				setRawBits(int value);
		float				toFloat(void) const;
		int					toInt(void) const;
		static const Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		friend std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);
	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

#endif