/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:27 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:12:52 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
#  define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
						Cat();
						Cat(const std::string &name);
						~Cat();
						Cat(const Cat& other);
			Cat			&operator=(const Cat& other);

			void		makeSound();
};

#endif