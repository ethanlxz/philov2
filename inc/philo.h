/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:14:25 by etlaw             #+#    #+#             */
/*   Updated: 2023/07/20 03:21:05 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

/*
2 types of state in this program

thinking = program is currently running
end = one of the philos is dead or all the philos has met the min_eat quota;
*/
# define THINKING 1;
# define END 2;

// Strings for philo activity
# define STR_FORK "has taken a fork"
# define STR_EAT "is eating"
# define STR_SLEEP "is sleeping"
# define STR_THINK "is thinking"
# define STR_DIED "died"

// info for all the program parameters
typedef struct s_info
{
	int				philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				min_eat;
	int				met_quota;
	int				state;
	pthread_t		*th;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_eat;
	int				full;
}	t_info;

// philo struct
typedef struct s_philo
{
	int				id;
	t_info			*info;
	int				last_ate;
	int				total_ate;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*m_eat;
}	t_philo;

// init.c
int		init_val(int ac, char **av, t_info *info);
int		init_mutex(t_philo *philo);

// philo.c
int		philo(t_info *info);

// philo_actions.c
void	grab_forks(t_philo *p);
void	return_forks(t_philo *p);
void	philo_eat(t_philo *p);
void	philo_sleep(t_philo *p);
void	philo_speak(t_philo *p, char *msg);

// utils.c
int		ft_atoi(const char *str);
int		get_time(void);
void	ft_usleep(int time);
void	check_state(t_info *info);

// check_philo
int		philo_meal(t_philo *p);
int		philo_dead(t_philo *p);

#endif