/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:15 by javellis          #+#    #+#             */
/*   Updated: 2023/02/01 17:23:29 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack		*last;
	t_stack		*tmp;

	if (*stack && (*stack)->next != NULL)
	{
		tmp = *stack;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
