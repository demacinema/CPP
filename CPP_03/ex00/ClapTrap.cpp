/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:34:37 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/04 15:23:24 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("CLAP"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Default constructor called " << _name << std::endl;
};

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "String constructor called " << _name << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHp(void) const
{
	return (_hp);
}

int	ClapTrap::getEp(void) const
{
	return (_ep);
}

int	ClapTrap::getAd(void) const
{
	return (_ad);
}

// void	ClapTrap::checkValue(int value)
// {
// 	if (value < 0)
// 	{
// 		std::cout << "Value must be UNSIGNED INTEGER. Exiting program..."	<< std::endl;
// 		exit(1);	
// 	}
// }

void ClapTrap::checkValue(int value)
{
	if (value < 0)
	{
		throw std::invalid_argument(" NEGATIVE NUMBER DETECTED!!!");
	}
}

void	ClapTrap::setHp(int value)
{
	checkValue(value);
	_hp = value;
}
void	ClapTrap::setEp(int value)
{
	checkValue(value);
	_ep = value;
}
void	ClapTrap::setAd(int value)
{
	checkValue(value);
	_ad = value;
}
		
void	ClapTrap::attack(const std::string &target)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << _name <<" attacks " << target << " for " << getAd() << " points of damage!" << std::endl;
		setEp(_ep - 1);
	}
	else if (_ep == 0 && _hp > 0)
		std::cout << "No energy left for attack!" << std::endl;
	else
		std::cout << _name << " is dead D:" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{	
	checkValue(amount);
	if (static_cast<unsigned int>(_hp) > amount)
	{
		setHp(_hp - amount);
		std::cout << _name <<" takes " << amount << " points of damage!"<< std::endl;
		std::cout << _name <<" has " << getHp() << " Hp left"<< std::endl << std::endl;
	}
	else
	{
		setHp(0);
		std::cout << _name <<" takes " << amount << " points of damage!"<< std::endl;
		std::cout << _name <<" has " << getHp() << " Hp left"<< std::endl;
		std::cout << _name << " is dead D:" << std::endl << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	checkValue(amount);
	if (_ep > 0 && _hp > 0)
	{
		std::cout << _name <<" repairs itself for " << amount  << std::endl;
		setHp(_hp + amount);
		setEp(_ep - 1);
	}
	else if (_ep == 0 && _hp > 0)
		std::cout << "No energy left for repair!" << std::endl;
	else
		std::cout << "Cant do that " << _name << " is dead D:" << std::endl;
}
