/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:19:54 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:39 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str_super_cat(char *s1, const char *s2, int n)
{
	int		c;

	c = 0;
	while (s2[c] != '\0')
	{
		s1[n] = s2[c];
		n++;
		c++;
	}
	s1[n] = '\0';
	return (s1);
}

static int		ft_get_len(char const *s)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
		i--;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		c;
	int		n;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	n = 0;
	i = ft_get_len(s1);
	c = ft_get_len(s2);
	str = (char *)malloc(i + c + 2);
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		str = ft_str_super_cat(str, s1, n);
	while (str[n])
		n++;
	if (s2 != NULL)
		str = ft_str_super_cat(str, s2, n);
	return (str);
}
