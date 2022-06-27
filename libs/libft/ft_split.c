/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:36:07 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:04:34 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	res;
	size_t	i;
	int		word;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			word = 0;
			i++;
		}
		while (s[i] != c && s[i])
		{
			word = 1;
			i++;
		}
		if (word)
			res++;
	}	
	return (res);
}

static size_t	ft_next_word(char const *s, char c, size_t *len, size_t pos)
{
	size_t	i;

	*len = 0;
	i = 0;
	while (s[pos] == c && s[pos])
		pos++;
	i = pos;
	while (s[i] != c && s[i])
	{
		(*len)++;
		i++;
	}
	return (pos);
}

static void	*mem_clean(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free (tab[i]);
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_word;
	char	**tab;
	size_t	start;
	size_t	len;
	size_t	word;

	word = 0;
	start = 0;
	len = 0;
	if (!s)
		return (NULL);
	n_word = ft_wordcount(s, c);
	tab = (char **)malloc((sizeof (char *)) * (n_word + 1));
	if (!tab)
		return (NULL);
	while (n_word > word)
	{
		start = ft_next_word(s, c, &len, start + len);
		tab[word] = ft_substr(s, start, len);
		if (!tab[word])
			return (mem_clean(tab));
		word++;
	}
	tab[word] = NULL;
	return (tab);
}
