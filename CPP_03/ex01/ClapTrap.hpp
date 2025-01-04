/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:35:08 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/04 15:30:06 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib> //EXIT_FAILURE & EXIT_SUCCESS
# include <stdexcept> //std::runtime_error

class ClapTrap
{
	public:
					ClapTrap();
					ClapTrap(const std::string &name);
		virtual		~ClapTrap();
					ClapTrap(const ClapTrap& other);
		ClapTrap	&operator=(const ClapTrap &other);
		std::string	getName(void) const;
		int			getHp(void) const;
		int			getEp(void) const;
		int			getAd(void) const;
		void		setHp(int value);
		void		setEp(int value);
		void		setAd(int value);
		virtual		void		attack(const std::string &target);//PERMITS POLYMORPHISM
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		checkValue(int value);
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;
};

#endif