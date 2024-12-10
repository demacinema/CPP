/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:33:47 by demacinema        #+#    #+#             */
/*   Updated: 2024/12/10 23:49:00 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
							Fixed();
							Fixed(const int value);
							Fixed(const float value);
							~Fixed();
							Fixed(const Fixed& other);
		Fixed&				operator=(const Fixed& other);
		int					getRawBits(void) const;
		void				setRawBits(int value);
		float				toFloat(void) const;
		int					toInt(void) const;
		
		float				getValueForOutput() const;		
		// friend				std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif