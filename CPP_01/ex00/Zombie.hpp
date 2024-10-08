/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:21:44 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/09 00:51:13 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
// # include <string>

class	Zombie
{
	private:
		std::string		_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void		announce( void ) const;
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif