/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:42:02 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:42:03 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _inventory[4];
public:
    MateriaSource();
    ~MateriaSource();

    MateriaSource(const MateriaSource& copy_const);
    MateriaSource& operator=(const MateriaSource& assign_op);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};


#endif