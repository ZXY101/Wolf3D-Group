/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:04:57 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/02 15:35:15 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYDEF_H
# define KEYDEF_H

# if __APPLE__
#  define MLX_A			0
#  define MLX_S			1
#  define MLX_D			2
#  define MLX_W			13
#  define MLX_ESC		53
#  define MLX_ARROWUP	126
#  define MLX_ARROWDOWN	125
#  define MLX_SHIFT		257
#  define MLX_ARROWL	123
#  define MLX_ARROWR	124
#  define MLX_SPACE		32
# elif __linux__
#  define MLX_A			'a'
#  define MLX_S			's'
#  define MLX_D			'd'
#  define MLX_W			'w'
#  define MLX_ESC		0xff1b
#  define MLX_ARROWUP	0xff52
#  define MLX_ARROWDOWN	0xff54
#  define MLX_SHIFT		65505
#  define MLX_ARROWL	65361
#  define MLX_ARROWR	65363
#  define MLX_SPACE		32
# endif
#endif
