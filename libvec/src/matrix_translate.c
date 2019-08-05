/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:22:49 by stenner           #+#    #+#             */
/*   Updated: 2019/08/03 09:44:01 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>
#include <stdio.h>

t_matrix	matrix_translate(t_vector v)
{
	t_matrix m;

	init_to_zero(&m);
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	m.m[3][0] = v.x;
	m.m[3][1] = v.y;
	m.m[3][2] = v.z;
	return (m);
}
