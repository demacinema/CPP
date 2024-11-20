/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:35:08 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:35:09 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class Claptrap
{
	public:
					Claptrap();
					Claptrap(const std::string &name);
					~Claptrap();
		Claptrap	&operator=(const Claptrap &other);
		std::string	getName(void) const;
		int			getHp(void) const;
		int			getEp(void) const;
		int			getAd(void) const;
		void		setHp(int value);
		void		setEp(int value);
		void		setAd(int value);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;
};

#endif