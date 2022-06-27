/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:11 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:21:25 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = 11;
		return (len);
	}
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_str_fill(char *str, int n, int pos)
{
	int	i;

	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	i = n;
	str[pos] = 0;
	pos--;
	while (n > 0)
	{
		i = n % 10;
		str[pos] = i + '0';
		n = n / 10;
		pos--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{		
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	else if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	ft_str_fill(str, n, len);
	return (str);
}
