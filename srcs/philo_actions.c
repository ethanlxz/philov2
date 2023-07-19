/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:21:22 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/20 03:41:47 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	grab_forks(t_philo *p)
{
	pthread_mutex_lock(p->l_fork);
	philo_speak(p, STR_FORK);
	pthread_mutex_lock(p->r_fork);
	philo_speak(p, STR_FORK);
}

void	return_forks(t_philo *p)
{
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
}

// ver 1 (safe but can't think or sleep)

void	philo_eat(t_philo *p)
{
	// if (p->info-> min_eat != 0 && p->info->met_quota >= p->info->philos)
	// 	return ;
	pthread_mutex_lock(p->m_eat);
	++p->total_ate;
	if (p->total_ate == p->info->min_eat)
		++p->info->met_quota;
	if (p->info->met_quota <= p->info->philos)
		philo_speak(p, STR_EAT);
	p->last_ate = get_time();
	ft_usleep(p->info->eat_time);
	pthread_mutex_unlock(p->m_eat);
}

// ver 2 unstable !

// void	philo_eat(t_philo *p)
// {
// 	pthread_mutex_lock(p->m_eat);
// 	++p->total_ate;
// 	// if (p->total_ate == p->info->min_eat)
// 	// 	++p->info->met_quota;
// 	// if (p->info->met_quota < p->info->philos)
// 	philo_speak(p, STR_EAT);
// 	p->last_ate = get_time();
// 	ft_usleep(p->info->eat_time);
// 	pthread_mutex_unlock(p->m_eat);
// }

void	philo_sleep(t_philo *p)
{
	if (p->info->state == 2)
		return ;
	philo_speak(p, STR_SLEEP);
	ft_usleep(p->info->sleep_time);
}

#include <string.h>

void	philo_speak(t_philo *p, char *msg)
{
	if (p->info->state == 2)
		return ;
	pthread_mutex_lock(p->m_print);
	printf("%04i %i %s\n", get_time(), p->id, msg);
	if (strcmp(msg, STR_DIED) != 0)
		pthread_mutex_unlock(p->m_print);
}
