/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:15 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 17:56:24 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
#  define ANIMAL_HPP

# include <iostream>
# include <string>
# include <cstdlib> //EXIT_FAILURE & EXIT_SUCCESS
# include <stdexcept> //std::runtime_error

class Animal
{
	public:
								Animal();
								Animal(const std::string &name);
			virtual				~Animal();
								Animal(const Animal& other);
			Animal				&operator=(const Animal& other);

			virtual		void	makeSound();

	protected:
			std::string			type;
};

#endif
