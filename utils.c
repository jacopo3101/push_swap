/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:06:24 by javellis          #+#    #+#             */
/*   Updated: 2023/02/03 16:46:38 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_stackinit2(t_stack **node, t_stack **begin, char **set)
{
	int	i;

	i = 0;
	*node = ft_new_stack(ft_atoi(set[i]));
	i++;
	*begin = *node;
	while (set[i])
	{
		(*node)->next = ft_new_stack(ft_atoi(set[i]));
		*node = (*node)->next;
		i++;
	}
}

t_stack	*ft_stackinit(char *str)
{
	char	**set;
	t_stack	*node;
	t_stack	*begin;

	set = ft_split(str, ' ');
	if (!ft_check_error(set))
	{
		ft_printf("Error\n");
		ft_free_matrix(set);
		exit(0);
	}
	if (set[0])
	{
		ft_stackinit2(&node, &begin, set);
		if (ft_check_sort(&begin))
		{
			ft_free_matrix(set);
			ft_free_stack(&begin);
			exit(0);
		}
	}
	else
		begin = NULL;
	ft_free_matrix(set);
	return (begin);
}

int	ft_check_error(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
		}
		j = i;
		while (str[++j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j])
				|| ft_long_atoi(str[j]) < -2147483647
				|| ft_long_atoi(str[j]) > 2147483647)
				return (0);
		}
	}
	return (1);
}

int	ft_check_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*ft_new_stack(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->val = content;
	return (node);
}
