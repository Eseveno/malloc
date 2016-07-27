/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:31:20 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:49 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;
	char	*p;

	i = 0;
	a = (char)c;
	p = (char *)s;
	while (p[i] != '\0')
		i++;
	if (a == '\0')
		return (&p[i]);
	while (i >= 0)
	{
		if (p[i] == a)
			return (&p[i]);
		i--;
	}
	return (0);
}
