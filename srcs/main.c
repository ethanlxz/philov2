/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:52:39 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/18 18:49:18 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	start(int ac, char **av, t_info *info)
{
	if (!init_val(ac, av, info))
	{
		printf("Invalid parameters!\n");
		return ;
	}
	if (philo(info))
	{
		printf("Error! Program not created properly.\n");
		return ;
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 5 || ac == 6)
	{
		start(ac, av, &info);
	}
	else
		printf("Too much or too less arguments! Try again.\n");
	return (0);
}
