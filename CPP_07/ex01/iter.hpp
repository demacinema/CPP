/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:40:00 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:40:02 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
#define __ITER_H__

template<typename T>
void iter(T *arr, int lenght, void (*f)(T const &)) {
	for (int i = 0; i < lenght; i++) {
		f(arr[i]);
	}
}

#endif // __ITER_H__