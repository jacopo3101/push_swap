/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:04:27 by javellis          #+#    #+#             */
/*   Updated: 2023/01/31 16:54:19 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radixsort2(int size, int i, t_stack **top, t_stack **b)
{
	int	j;

	j = 0;
	while (j < size && *top)
	{
		if ((((*top)->val >> i) & 1) == 1)
		{
			ft_printf("ra\n");
			ft_rotate(top);
		}
		else
		{
			ft_printf("pb\n");
			ft_push(top, b);
		}
		j++;
	}
}

void	ft_radixsort(t_stack **a, t_stack **b)
{
	int		i;
	int		size;
	t_stack	*top;

	size = ft_lstsize((t_list *)*a);
	i = -1;
	top = *a;
	while (++i < ft_maxbits(size - 1))
	{
		ft_radixsort2(size, i, &top, b);
		while ((*b) != NULL)
		{
			ft_printf("pa\n");
			ft_push(b, &top);
		}
	}
	*a = top;
}
