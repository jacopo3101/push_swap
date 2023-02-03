/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:46:55 by javellis          #+#    #+#             */
/*   Updated: 2023/02/03 16:38:59 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int argc, char **argv)
{	
	t_stack		*a;
	t_stack		*b;
	int			count;

	b = NULL;
	count = 1;
	if (argc == 2)
	{
		a = ft_stackinit(argv[1]);
		while (count != 0)
		{
			count = ft_main2(&count, &a, &b);
			if (count == 1)
				break ;
			else if (count == 0)
				return (0);
		}
		if (ft_check_sort(&a) && b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free_stack(&a);
	}
	return (0);
}

/*
	if (!ft_vaidate_sort(&a, &b, str))
	{
		ft_printf("KO\n");
		ft_free_stack(&a);
		return (0);
	}
	free(str);*/

int	ft_main2(int *count, t_stack **a, t_stack **b)
{
	char	*str;

	str = ft_read_instructions(count);
	if (str[0] == 0)
	{
		free(str);
		return (1);
	}
	if (!ft_vaidate_sort(a, b, str))
	{
		ft_printf("KO\n");
		ft_free_stack(a);
		return (0);
	}
	free(str);
	return (2);
}

char	*ft_read_instructions(int *count)
{
	char	*buf;
	char	*str;

	buf = ft_calloc(2, 1);
	str = NULL;
	while (!ft_strchr(buf, '\n') && *count != 0)
	{
		*count = read(0, buf, 1);
		buf[1] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

//./push_swap "2 6 4 8 1" | valgrind --leak-check=full ./checker "2 6 4 8 1"

int	ft_vaidate_sort(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push(b, a);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push(a, b);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_swap(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_swap(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ft_ss(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_reverse_rotate(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_reverse_rotate(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		ft_rrr(a, b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_rotate(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_rotate(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		ft_rr(a, b);
	else
		return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		size;
	int			i;
	int			j;

	i = -1;
	j = 0;
	str = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s2) + ft_strlen(s1) + 1;
	str = (char *)malloc(size);
	if (!str)
		return (NULL);
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
