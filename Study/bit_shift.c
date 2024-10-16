/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:32:32 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/30 14:14:13 by ernda-si         ###   ########.fr       */
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
	int	max;
	int	exp;
	int	digit;
	int	digit2;
	int	arr[9] = {2, 1, 3, 4, 5, 4, 3, 2, 1};
	int	i = 0;
	a = 2; // 00000101
	b = 5; // 00000010
	max = 8;
	exp = 0;

	// a = a << b; // a == 00000101 | a << 2 or == 00010100 (20) | a >> 2 == 00000001 (1)
	printf("a: %d\n", a);
	printf("b: %d\n", b);

	// if (a | b)
	// printf("test\n");
	
	while (max > exp)
	{
		digit = (arr[1] >> exp) & 1; // 00000101 >> exp == 00000010 then 00000010 & 1 == 0
		digit2 = (arr[2] >> exp) & 1;
		printf("digit: %d\n", digit);
		printf("digit2: %d\n", digit2);
		if (digit < digit2)
		{
			arr[1] = arr[1] ^ arr[2];
			arr[2] = arr[1] ^ arr[2];
			arr[1] = arr[1] ^ arr[2];
			printf("swapped digit: %d\n", a);
			break;
		}
		exp++;
	}
	return (1);
}