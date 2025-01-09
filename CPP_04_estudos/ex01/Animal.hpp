/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:40:15 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/08 23:48:32 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
#  define ANIMAL_HPP

# include <iostream>
// # include <string>
// # include <cstdlib> //EXIT_FAILURE & EXIT_SUCCESS
// # include <stdexcept> //std::runtime_error

class Animal
{
	public:
								Animal();
								Animal(const std::string &name);
			virtual				~Animal();
								Animal(const Animal& other);
			Animal				&operator=(const Animal& other);

			std::string			getType() const;
			void				setType(const std::string& type);

			
			virtual		void	makeSound() const;

	protected:
			std::string			_type;
};

#endif
