/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:08:34 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/07 19:27:21 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_safe_malloc(char **str, int position, size_t len)
{
	int	i;

	i = 0;
	str[position] = malloc(len);
	if (NULL == str[position])
	{
		while (i < position)
			free(str[i++]);
		free(str);
		return (1);
	}
	return (0);
}

int	ft_wordcpy(char **str, char const *s, char d)
{
	int	len;
	int	token;

	token = 0;
	while (*s)
	{
		len = 0;
		while (*s == d && *s)
			s++;
		while (*s != d && *s)
		{
			s++;
			len++;
		}
		if (len != 0)
		{
			if (ft_safe_malloc(str, token, len + 1))
				return (1);
		}
		ft_strlcpy(str[token], s - len, len + 1);
		token++;
	}
	return (0);
}

size_t	ft_count_words(char const *s, char d)
{
	int	j;
	int	i;
	int	signal;

	signal = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == d && s[i])
			i++;
		while (s[i] != d && s[i])
		{
			if (signal == 0)
			{
				j++;
				signal = 1;
			}
			i++;
		}
		signal = 0;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**str;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	str = malloc((words + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str[words] = NULL;
	if (ft_wordcpy(str, s, c))
		return (NULL);
	return (str);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("word count: %ld\n", ft_count_words(av[1], *av[2]));
	printf("split: %s\n", (char *)ft_split(av[1], *av[2]));
} */