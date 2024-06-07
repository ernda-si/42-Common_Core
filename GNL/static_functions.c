/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:36:40 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/07 14:02:09 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	func(void)
{
	static int x = 0;
	int y = 0;
	y++;
	x++;
	printf("static int bm: %d\nint bm: %d\n", x, y);
	x += y;
	printf("static int am: %d\nint am: %d\n", x, y);
}
int	main(void)
{
	func();
	func();
	func();
	func();
	func();

	return 0;
}