/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:48:42 by javellis          #+#    #+#             */
/*   Updated: 2023/02/03 16:43:55 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>

char		*ft_strjoin(char *s1, char *s2);
int			ft_vaidate_sort(t_stack **a, t_stack **b, char *str);
char		*ft_read_instructions(int *count);
int			ft_main2(int *count, t_stack **a, t_stack **b);
#endif