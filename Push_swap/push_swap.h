/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:23:35 by kali              #+#    #+#             */
/*   Updated: 2024/12/11 16:48:02 by ernda-si         ###   ########.fr       */
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
	int				index;
	int				flag;
	struct Stacks	*next;
}	t_Stacks;

	// struct Stacks	*head = NULL;
	// struct Stacks	*head_b = NULL;

struct Stacks	*lstadd(int new_data, struct Stacks *start);
struct Stacks	*last_node(struct Stacks *head);
struct Stacks	*create_node(int new_data);
void			sort_handler(struct Stacks **head, struct Stacks **head_b);
void			rrotate_ab(struct Stacks **head, struct Stacks **head_b);
void			rotate_ab(struct Stacks **head, struct Stacks **head_b);
void			big_sort(struct Stacks **head, struct Stacks **head_b);
void			swap_swap(struct Stacks *head, struct Stacks *head_b);
void			push_b(struct Stacks **head_b, struct Stacks **head);
void			push_a(struct Stacks **head, struct Stacks **head_b);
void			sort(struct Stacks **head, struct Stacks **head_b);
void			medium_sort(struct Stacks **head);
void			rrotate_b(struct Stacks **head_b);
void			rotate_b(struct Stacks **head_b);
void			small_sort(struct Stacks **head);
void			rrotate_a(struct Stacks **head);
void			index_num(struct Stacks **head);
void			print_list(struct Stacks *head);
void			push_swap(int ac, char *arr[]);
void			rotate_a(struct Stacks **head);
void			swap_b(struct Stacks *head_b);
void			free_lst(struct Stacks *head, char **matrix, char *str);
void			printf_bin(unsigned int num);
void			swap_a(struct Stacks *head);
int				bin_left(struct Stacks *head, int exp);
int				has_num(struct Stacks *head, int num);
int				lst_size(struct Stacks *head);
int				verify(struct Stacks *head);
int				min_n(struct Stacks *head);
int				max_n(struct Stacks *head);
int				ft_strlen(const char *str);
int				ft_atoi(char const *str);
int				str_checker(char *str);
int				bin_count(int num);
void			error(struct Stacks *head, char **matrix, char *str);
char			*ft_strjoin(char const *s1, char *s2);
char			**ft_split(char const *s, char c);

#endif