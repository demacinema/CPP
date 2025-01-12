/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:27 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/12 00:18:15 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
#  define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
			Brain		*_brain;

	public:
						Cat();
						Cat(const std::string &name);
						~Cat();
						Cat(const Cat& other);
			Cat			&operator=(const Cat& other);

			void		makeSound() const;
};

#endif