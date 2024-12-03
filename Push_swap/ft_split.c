/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:25:56 by ernda-si          #+#    #+#             */
/*   Updated: 2024/11/19 15:26:37 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest [i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_safe_malloc(char **str, int position, size_t len)
{
	int	i;

	i = 0;
	str[position] = malloc(len + 1);
	if (str[position] == NULL)
	{
		while (i < position)
			free(str[i++]);
		free(str);
		return (1);
	}
	return (0);
}

static int	ft_wordcpy(char **str, char const *s, char d)
{
	int	len;
	int	token;

	token = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == d)
			s++;
		while (*s && *s != d)
		{
			s++;
			len++;
		}
		if (len != 0)
		{
			if (ft_safe_malloc(str, token, len))
				return (1);
			ft_strncpy(str[token], s - len, len);
			token++;
		}
	}
	return (0);
}

static size_t	ft_count_words(char const *s, char d)
{
	int	j;
	int	i;
	int	signal;

	signal = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == d)
			i++;
		while (s[i] && s[i] != d)
		{
			if (!signal)
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

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	str[words] = NULL;
	if (ft_wordcpy(str, s, c))
		return (NULL);
	return (str);
}