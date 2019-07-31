/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/31 13:50:55 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	del(void *node, size_t n)
{
	(void)n;
	free(node);
}

int		main(int ac, char **av)
{
	t_list	  *map;
	t_environment env;
	char	*file;
	
	if (ac > 2 || ac < 1)
		ft_error("Usage ./Wolf3d <map>");
	file = (ac > 1) ? av[1] : main_menu();
	map = map_interpreter(file, &env);
  map_int_array(map, &env);
	ft_lstdel(&map,del);
	init_env(&env);
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

void		ft_error(char *str)
{
	char	*prompt;

	prompt = ft_strjoin("\e[91m", "[ERROR]\t\t\t");
	prompt = ft_strjoin_free(prompt, str, 1, 0);
	prompt = ft_strjoin_free(prompt, "\33[m", 1, 0);
	ft_putendl_fd(prompt, 2);
	free(prompt);
	exit(-1);
}