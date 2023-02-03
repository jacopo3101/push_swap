/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:11:24 by javellis          #+#    #+#             */
/*   Updated: 2023/02/01 16:31:25 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}			t_stack;

t_stack		*ft_stackinit(char *str);
t_stack		*ft_new_stack(int content);
void		ft_swap(t_stack **stack);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_push(t_stack **a, t_stack **b);
void		ft_rotate(t_stack **stack);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_reverse_rotate(t_stack **stack);
void		ft_rrr(t_stack **a, t_stack **b);
int			ft_check_error(char **str);
int			ft_check_sort(t_stack **stack);
void		ft_sort(t_stack **stack);
void		ft_simplify(t_stack **stack, t_stack **sorted);
void		ft_radixsort(t_stack **a, t_stack **b);
int			ft_maxbits(int max_num);
void		ft_sort_3num(t_stack **stack);
void		ft_sort_5num(t_stack **a, t_stack **b);
void		ft_min_on_top(t_stack **stack);
void		ft_free_matrix(char **c);
void		ft_free_stack(t_stack **stack);
#endif