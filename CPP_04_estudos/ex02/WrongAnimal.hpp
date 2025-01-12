/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:20 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 01:15:48 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
#  define WRONGANIMAL_HPP

// #include "Animal.hpp"
#include <iostream>

// class WrongAnimal : public Animal
class WrongAnimal
{
	public:
							WrongAnimal();
							WrongAnimal(const std::string &name);
			virtual			~WrongAnimal();
							WrongAnimal(const WrongAnimal& other);
			WrongAnimal		&operator=(const WrongAnimal& other);

			void 			setType(std::string type);
			std::string		getType() const;

			virtual void	makeSound() const;

	protected:
		std::string 		_type;
};

#endif