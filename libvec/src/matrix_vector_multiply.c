/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_multiply.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:17:45 by stenner           #+#    #+#             */
/*   Updated: 2019/08/03 09:45:56 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vector	matrix_vector_multiply(t_vector v, t_matrix m)
{
	t_vector ret;

	ret.x = v.x * m.m[0][0] + v.y * m.m[1][0] +
	v.z * m.m[2][0] + m.m[3][0];
	ret.y = v.x * m.m[0][1] + v.y * m.m[1][1] +
	v.z * m.m[2][1] + m.m[3][1];
	ret.z = v.x * m.m[0][2] + v.y * m.m[1][2] +
	v.z * m.m[2][2] + m.m[3][2];
	ret.w = v.x * m.m[0][3] + v.y * m.m[1][3] +
	v.z * m.m[2][3] + m.m[3][3];
	return (ret);
}
