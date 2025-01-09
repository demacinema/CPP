/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:20 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/08 23:36:26 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
#  define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
						Dog();
						Dog(const std::string &name);
						~Dog();
						Dog(const Dog& other);
			Dog			&operator=(const Dog& other);

			void		makeSound() const;
};

#endif