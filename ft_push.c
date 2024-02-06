/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:29:49 by javellis          #+#    #+#             */
/*   Updated: 2023/01/30 15:43:29 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack		*top;

	if (*a || *b)
	{
		top = *a;
		*a = (*a)->next;
		if (!(*b))
		{
			top->next = NULL;
			*b = top;
		}
		else
		{
			top->next = *b;
			*b = top;
		}
	}
}