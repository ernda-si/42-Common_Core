/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitUNF.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:08:34 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/22 16:14:37 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str, char b)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str[0] != b)
		count = 1;
	while (str[i + 1] != '\0')
	{
		if (str[i] == b && str[i + 1] != b)
			count++;
		i++;
	}
	return(count);
}
char	**ft_substr(char const *str, char b)
{
	char	**ss;
	int	i;
	int	len;

	i = 0;
	len = ft_count_words(str, b);
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	while (len-- <= ft_count_words(str, b) && ss[i + 1] != '\0')
	{
		ss[len][i] = str[i];
		i++;
	}
	return (ss);
}

int	main(int ac, char **av)
{
	(void) ac;
	printf("str before split: %d\n", *av[1]);
	printf("str after split: %s\n", ft_split(av[1], *av[2]));
	printf("count_words test: %d\n", ft_count_words(av[1], *av[2]));
}