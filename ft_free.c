/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:56:10 by javellis          #+#    #+#             */
/*   Updated: 2023/01/30 16:23:38 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_matrix(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*s;

	while (*stack)
	{
		s = *stack;
		*stack = (*stack)->next;
		free(s);
	}
}
