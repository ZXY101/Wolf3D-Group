/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross_product.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:15:04 by stenner           #+#    #+#             */
/*   Updated: 2019/08/03 09:46:10 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vector	vector_cross_product(t_vector v1, t_vector v2)
{
	t_vector ret;

	ret.x = (v1.y * v2.z) - (v1.z * v2.y);
	ret.y = (v1.z * v2.x) - (v1.x * v2.z);
	ret.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (ret);
}
