/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:56:22 by javellis          #+#    #+#             */
/*   Updated: 2023/02/02 12:32:25 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3num(t_stack **stack)
{
	if ((*stack)->val < (*stack)->next->val)
	{
		if ((*stack)->next->val > (*stack)->next->next->val)
		{
			if ((*stack)->val > (*stack)->next->next->val)
				ft_printf("rra\n");
			else
				ft_printf("sa\nra\n");
		}
	}
	else
	{
		if ((*stack)->next->val > (*stack)->next->next->val)
			ft_printf("sa\nrra\n");
		else
		{
			if ((*stack)->next->next->val > (*stack)->val)
				ft_printf("sa\n");
			else
				ft_printf("ra\n");
		}
	}
}

void	ft_sort_5num(t_stack **a, t_stack **b)
{	
	ft_min_on_top(a);
	ft_push(a, b);
	ft_printf("pb\n");
	ft_min_on_top(a);
	ft_push(a, b);
	ft_printf("pb\n");
	ft_sort_3num(a);
	ft_sort(a);
	ft_push(b, a);
	ft_printf("pa\n");
	ft_push(b, a);
	ft_printf("pa\n");
}

int	ft_min_on_top2(t_stack **stack, int min1)
{
	t_stack		*c;
	int			min_pos;
	int			pos;

	c = *stack;
	min_pos = 0;
	min1 = c->val;
	while (c)
	{
		if (min1 > c->val)
		{
			min1 = c->val;
			pos = min_pos;
		}
		min_pos++;
		c = c->next;
	}
	return (pos);
}

void	ft_min_on_top(t_stack **stack)
{
	int		min1;
	int		pos;
	t_stack	*c;

	c = *stack;
	min1 = c->val;
	pos = ft_min_on_top2(stack, min1);
	c = *stack;
	if (pos == 1)
	{
		ft_swap(&c);
		ft_printf("sa\n");
	}
	if (pos >= 2)
	{
		while (pos < ft_lstsize((t_list *)c))
		{
			ft_printf("rra\n");
			ft_reverse_rotate(&c);
			pos++;
		}
	}
	*stack = c;
}
