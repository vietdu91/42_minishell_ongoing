/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:55:02 by emtran            #+#    #+#             */
/*   Updated: 2022/05/05 12:57:52 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_substr(char *s, int start, int len)
{
	char		*str;
	size_t		i;

	str = 0;
	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (str == 0)
			return (0);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		str = malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	else
		str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (s[start] != '\0' && len-- != 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)ch && str[i] == '\0')
		return ((char *)str + i);
	return (0);
}

char	*ft_strjoin_one_c_sans_free(char *s1, char s2)
{
	unsigned int	len_1;
	char			*str;

	if (s2 != 0)
	{
		len_1 = ft_strlen(s1);
		str = (char *)malloc(sizeof(char) * (len_1 + 1 + 1));
		if (!str)
			return (0);
		ft_memcpy(str, s1, len_1);
		ft_memcpy_with_one_char(str + len_1, s2, 1 + 1);
		str[len_1 + 1] = '\0';
		return (str);
	}
	return (s1);
}
