/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:26 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:13:31 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP
#  define WRONGCAT_HPP

# include "Animal.hpp"

class WrongCat : public Animal
{
	public:
						WrongCat();
						WrongCat(const std::string &name);
						~WrongCat();
						WrongCat(const WrongCat& other);
			WrongCat	&operator=(const WrongCat& other);

			void		makeSound();
};

#endif