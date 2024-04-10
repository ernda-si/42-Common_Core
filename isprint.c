/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:43 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/08 14:46:01 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// 32 to 126 (printable characters)
int ft_isprint(char av)
{
    return(av >= 32 && av <= 126);
}

int main(int ac, char **av)
{
    (void) ac;
    printf("%d\n", ft_isprint(av[1][0]));
}