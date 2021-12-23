/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_giveaway.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhawk <mhawk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:07:39 by mhawk             #+#    #+#             */
/*   Updated: 2021/12/23 12:07:40 by mhawk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	forks_giveaway(t_philo *philo, t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		philo[i].left_fork = i;
		if (i == 0)
			philo[i].right_fork = table->number_of_philosophers - 1;
		else
			philo[i].right_fork = i - 1;
		i++;
	}
}
