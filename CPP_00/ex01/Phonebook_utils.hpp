/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:14:29 by demrodri          #+#    #+#             */
/*   Updated: 2024/09/24 01:42:54 by demrodri         ###   ########.fr       */
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