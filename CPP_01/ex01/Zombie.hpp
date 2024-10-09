/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:56:16 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/09 22:54:46 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
// # include <stdlib.h>

class Zombie
{
	private:
		std::string		_name;
		
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		
		void		setName(std::string);
		void		announce(void) const;
	
};
Zombie	*zombieHorde(int N, std::string name);

#endif
