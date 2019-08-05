/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:47:23 by stenner           #+#    #+#             */
/*   Updated: 2019/08/03 09:43:48 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_matrix	matrix_rotate(t_vector v)
{
	t_matrix m;
	t_matrix temp;

	m = matrix_rotate_x(v.x);
	temp = matrix_rotate_y(v.y);
	m = matrix_matrix_multiply(m, temp);
	temp = matrix_rotate_z(v.z);
	m = matrix_matrix_multiply(m, temp);
	return (m);
}

t_matrix	matrix_rotate_x(double theta)
{
	t_matrix m;

	theta = theta * M_PI / 180;
	init_to_zero(&m);
	m.m[0][0] = 1;
	m.m[1][1] = cos(theta);
	m.m[1][2] = sin(theta);
	m.m[2][1] = -sin(theta);
	m.m[2][2] = cos(theta);
	m.m[3][3] = 1;
	return (m);
}

t_matrix	matrix_rotate_y(double theta)
{
	t_matrix m;

	theta = theta * M_PI / 180;
	init_to_zero(&m);
	m.m[0][0] = cos(theta);
	m.m[0][2] = sin(theta);
	m.m[2][0] = -sin(theta);
	m.m[1][1] = 1;
	m.m[2][2] = cos(theta);
	m.m[3][3] = 1;
	return (m);
}

t_matrix	matrix_rotate_z(double theta)
{
	t_matrix m;

	theta = theta * M_PI / 180;
	init_to_zero(&m);
	m.m[0][0] = cos(theta);
	m.m[0][1] = sin(theta);
	m.m[1][0] = -sin(theta);
	m.m[1][1] = cos(theta);
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}
