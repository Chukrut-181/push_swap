/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:28:23 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/23 08:03:47 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_freeall(char **frags, unsigned int k)
{
	unsigned int	i;

	i = 0;
	while (i < k && frags[i])
	{
		free (frags[i]);
		i++;
	}
	free (frags);
	return (NULL);
}

size_t	ft_wordlen(const char *word, char c)
{
	size_t	len;

	len = 0;
	while (word[len] && word[len] != c)
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!len || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len +1);
	return (substr);
}

unsigned int	ft_count_frags(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**frags;
	unsigned int	index;
	unsigned int	k;

	if (!s)
		return (NULL);
	frags = malloc((ft_count_frags(s, c) + 1) * sizeof(char *));
	if (!frags)
		return (NULL);
	index = 0;
	k = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index])
	{
		frags[k] = ft_substr(s, index, ft_wordlen(s + index, c));
		if (!frags[k])
			return (ft_freeall(frags, k));
		k++;
		index = index + ft_wordlen(s + index, c);
		while (s[index] && s[index] == c)
			index++;
	}
	frags[k] = NULL;
	return (frags);
}
