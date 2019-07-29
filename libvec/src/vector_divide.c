/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:50:12 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 13:04:23 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_vector	vector_divide(t_vector v, double k)
{
	t_vector ret;

	ret.x = v.x / k;
	ret.y = v.y / k;
	ret.z = v.z / k;
	return (ret);
}
