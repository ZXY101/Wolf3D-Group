/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:04:57 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/31 18:29:41 by rcoetzer         ###   ########.fr       */
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
# elif __linux__
#  define MLX_A			'a'
#  define MLX_S			's'
#  define MLX_D			'd'
#  define MLX_W			'w'
#  define MLX_ESC		0xff1b
#  define MLX_ARROWUP	0xff52
#  define MLX_ARROWDOWN	0xff54
# endif
#endif
