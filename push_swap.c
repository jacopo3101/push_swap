/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:11:22 by javellis          #+#    #+#             */
/*   Updated: 2023/02/01 17:56:45 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*tmp;
	t_stack		*b;
	int			len;

	b = NULL;
	if (argc == 2)
	{
		a = ft_stackinit(argv[1]);
		tmp = ft_stackinit(argv[1]);
		len = ft_lstsize((t_list *)a);
		if (len == 3)
			ft_sort_3num(&a);
		else if (len == 5)
			ft_sort_5num(&a, &b);
		else
		{
			ft_sort(&tmp);
			ft_simplify(&a, &tmp);
			ft_radixsort(&a, &b);
		}
		ft_free_stack(&a);
		ft_free_stack(&tmp);
	}
	return (0);
}

int	ft_maxbits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void	ft_simplify(t_stack **stack, t_stack **sorted)
{
	int			count;
	t_stack		*sta;
	t_stack		*sor;

	sta = *stack;
	sor = *sorted;
	count = 0;
	while (sor)
	{
		sta = *stack;
		while (sta)
		{
			if (sta->val == sor->val)
			{
				sta->val = count;
				count++;
				break ;
			}
			sta = sta->next;
		}
		sor = sor->next;
	}
}

void	ft_sort(t_stack **stack)
{
	t_stack		*s;
	int			flag;
	int			tmp;

	flag = 0;
	while (!flag)
	{
		flag = 1;
		s = *stack;
		while (s->next)
		{
			if (s->val > s->next->val)
			{
				tmp = s->val;
				s->val = s->next->val;
				s->next->val = tmp;
				flag = 0;
			}
			s = s->next;
		}
	}
}
