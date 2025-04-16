#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		i2;
	char	*s3;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	else if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	i2 = 0;
	s3 = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (s3 == 0)
		return (NULL);
	while (++i < len1)
		s3[i] = s1[i];
	while (i2 < len2)
		s3[i++] = s2[i2++];
	s3[i] = '\0';
	return (s3);
}

int	ft_strncmp(char const *str1, char const *str2, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = ft_strlen(str1) + ft_strlen(str2);
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < (n - 1) && str1[i] && str2[i])
	{
		if (str1[i] > 126 || str2[i] > 126 || str2[i] == '\0')
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*s2;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
