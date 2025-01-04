/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:20 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:13:21 by demrodri         ###   ########.fr       */
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

			void		makeSound();
};

#endif