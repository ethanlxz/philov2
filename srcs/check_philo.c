/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:20 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/20 01:27:01 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_meal(t_philo *p)
{
	pthread_mutex_lock(p->m_eat);
	if (p->info-> min_eat != 0 && p->info->met_quota >= p->info->philos)
	{
		p->info->state = END;
		return (1);
	}
	pthread_mutex_unlock(p->m_eat);
	return (0);
}

int	philo_dead(t_philo *p)
{
	pthread_mutex_lock(p->m_eat);
	if (get_time() - p->last_ate >= p->info->die_time)
	{
		p->info->state = END;
		return (1);
	}
	pthread_mutex_unlock(p->m_eat);
	return (0);
}
