/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_subtract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:45:05 by stenner           #+#    #+#             */
/*   Updated: 2019/08/03 09:46:58 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vector	vector_subtract(t_vector v1, t_vector v2)
{
	t_vector ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return (ret);
}
