/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:26 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 00:42:43 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP
#  define WRONGCAT_HPP

// # include "Animal.hpp"
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
						WrongCat();
						WrongCat(const std::string &name);
						~WrongCat();
						WrongCat(const WrongCat& other);
			WrongCat	&operator=(const WrongCat& other);

			void		makeSound() const;
};

#endif