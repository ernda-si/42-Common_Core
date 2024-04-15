/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpyUNF.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:14:18 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/15 15:30:13 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/* size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	
} */

int	main(void)
{
	char	*dest = "///////";
	const char	*src = "abc";

	printf ("Original: %ld\n", strlcpy(dest, src, 3));
	//printf ("%s\n", ft_strlcpy(dest, src, 7));
}
