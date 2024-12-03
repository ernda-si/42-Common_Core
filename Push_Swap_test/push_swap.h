/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:23:35 by kali              #+#    #+#             */
/*   Updated: 2024/11/20 12:38:46 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct Stacks
{
	int				number;
	struct Stacks	*next;
}	t_Stacks;

	// struct Stacks	*head = NULL;
	// struct Stacks	*head_b = NULL;

struct Stacks	*lstadd(int new_data, struct Stacks *start);
struct Stacks	*create_node(int new_data);
int				has_num(struct Stacks *head, int num);
int				find_max_num(struct Stacks *head);
int				find_min_num(struct Stacks *head);
int				get_middle(struct Stacks *head);
int				ft_strlen(const char *str);
int				ft_atoi(char const *str);
int				str_checker(char *str);
void			rrotate_ab(struct Stacks **head, struct Stacks **head_b);
void			rotate_ab(struct Stacks **head, struct Stacks **head_b);
void			big_sort(struct Stacks **head, struct Stacks **head_b);
void			swap_swap(struct Stacks *head, struct Stacks *head_b);
void			min_max(struct Stacks **head, struct Stacks **head_b);
void			push_a(struct Stacks **head, struct Stacks **head_b);
void			push_b(struct Stacks **head_b, struct Stacks **head);
void			sort(struct Stacks **head, struct Stacks **head_b);
void			rrotate_b(struct Stacks **head_b);
void			medium_sort(struct Stacks **head);
void			small_sort(struct Stacks **head);
void			rotate_b(struct Stacks **head_b);
void			print_list(struct Stacks *head);
void			rrotate_a(struct Stacks **head);
void			rotate_a(struct Stacks **head);
void			push_swap(int ac, char *arr[]);
void			swap_b(struct Stacks *head_b);
void			swap_a(struct Stacks *head);
char			**ft_split(char const *s, char c);

#endif