/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:32:32 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/25 13:41:12 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// 1 2 4 8 16 32 64 128 256
// right shifting: a=a/(2^2)
// left shifting: a=a*(2^2)
// 00000000 (8 per block)

//binary operators for sorting algorithms: 

int	main(void)
{
	int	a;
	int	b;

	a = 5; // 00000101
	b = 2;

	a = a << b; // a == 00000101 | a << 2 or == 00010100 (20) | a >> 2 == 00000001 (1)
	printf("a: %d\n", a);
	printf("b: %d\n", b);

	return (1);
}