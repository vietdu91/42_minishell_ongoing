/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:28:57 by emtran            #+#    #+#             */
/*   Updated: 2022/02/01 23:22:42 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	while (str[i])
		i++;
	n_str = malloc(sizeof(char) * (i + 1));
	if (!n_str)
		return (NULL);
	i = -1;
	while (str[++i])
		n_str[i] = str[i];
	n_str[i] = 0;
	return (n_str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

char	*join_char(char *str, char c)
{
	int		i;
	int		len;
	char	*joined;

	i = -1;
	if (str[0] != 0)
		len = ft_strlen(str) + 1;
	else
		len = 1 + 1;
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (++i < (int)ft_strlen(str))
	{
		joined[i] = str[i];
	}
	joined[i] = c;
	i++;
	joined[i] = 0;
	return (joined);
}
