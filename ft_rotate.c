/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:30:46 by javellis          #+#    #+#             */
/*   Updated: 2023/01/27 18:15:47 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack		*first;
	t_stack		*tmp;

	if (*stack && (*stack)->next != NULL)
	{
		first = *stack;
		*stack = (*stack)->next;
		first->next = NULL;
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = first;
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
