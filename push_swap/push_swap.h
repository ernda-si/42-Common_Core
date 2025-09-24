/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:23:35 by kali              #+#    #+#             */
/*   Updated: 2025/09/23 19:43:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stacks
{
	int				number;
	int				index;
	int				flag;
	struct stacks	*next;
}	t_stacks;

	// t_stacks	*head = NULL;
	// t_stacks	*head_b = NULL;

t_stacks	*lstadd(int new_data, t_stacks *start);
t_stacks	*last_node(t_stacks *head);
t_stacks	*create_node(int new_data);
void		sort_handler(t_stacks **head, t_stacks **head_b);
void		rrotate_ab(t_stacks **head, t_stacks **head_b);
void		rotate_ab(t_stacks **head, t_stacks **head_b);
void		big_sort(t_stacks **head, t_stacks **head_b);
void		swap_swap(t_stacks *head, t_stacks *head_b);
void		push_b(t_stacks **head_b, t_stacks **head);
void		push_a(t_stacks **head, t_stacks **head_b);
void		sort(t_stacks **head, t_stacks **head_b);
void		free_all(t_stacks *head, char **matrix);
void		medium_sort(t_stacks **head);
void		rrotate_b(t_stacks **head_b);
void		rotate_b(t_stacks **head_b);
void		index_nums(t_stacks *head);
void		small_sort(t_stacks **head);
void		rrotate_a(t_stacks **head);
void		rotate_a(t_stacks **head);
void		swap_b(t_stacks *head_b);
void		printf_bin(unsigned int num);
void		swap_a(t_stacks *head);
int			bin_left(t_stacks *head, int exp);
int			has_num(t_stacks *head, int num);
int			lst_size(t_stacks *head);
int			verify(t_stacks *head);
int			min_n(t_stacks *head);
int			max_n(t_stacks *head);
int			ft_strlen(const char *str);
int			str_checker(char *str);
int			bin_count(int num);
void		error_all(t_stacks *head, char **matrix);
char		*ft_strjoin(char const *s1, char *s2);
char		**ft_split(char const *s, char c);
void		args_parse(int ac, char *arr[]);
void		str_parse(int ac, char *arr[]);
void		error(t_stacks *head);
void		free_lst(t_stacks *head);
int			check_num(char *str);
int			ft_atoi(char const *str);
int			num_valid(char const *str);

#endif