/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:20 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:13:27 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
#  define WRONGANIMAL_HPP

# include "Animal.hpp"

class WrongAnimal : public Animal
{
	public:
						WrongAnimal();
						WrongAnimal(const std::string &name);
						~WrongAnimal();
						WrongAnimal(const WrongAnimal& other);
			WrongAnimal	&operator=(const WrongAnimal& other);

			void		makeSound();
};

#endif