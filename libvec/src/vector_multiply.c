/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:47:07 by stenner           #+#    #+#             */
/*   Updated: 2019/08/03 09:46:40 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vector	vector_multiply(t_vector v, double k)
{
	t_vector ret;

	ret.x = v.x * k;
	ret.y = v.y * k;
	ret.z = v.z * k;
	return (ret);
}
