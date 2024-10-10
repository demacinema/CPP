/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:14:29 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/10 20:48:16 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP

# define PHONEBOOK_UTILS_HPP

# include <iostream>
# include "Contact.hpp"

// STRING WITH n SPACES
std::string	add_spaces(int n);

// STRING HAS MAX CHARS, ADD . IF NEEDED
std::string	fix_width(std::string str, long unsigned max);

// PRINTS CONTACT
int			search_ui(Contact contacts[8]);

#endif
