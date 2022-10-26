/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:18:48 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/25 16:24:56 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_long(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_count_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		if (!(strs[j] = ft_substr(s, i, size)))
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}



 /* int	nbr_tokens(char const *s, char delimeter)
{
	int	i;
	int	len;
	int	token_count;

	i = 0;
	len = 0;
	if (!(*s))
		return (0);
	token_count = 0;
	while (s[i])
	{
		if (s[i] == delimeter)
			len = 0;
		else if (++len == 1)
			token_count++;
		i++;
	}
	return (token_count);
}

 char	*token(const char *s, int columns, int index)
{
	char	*token;
	int		i;
	int		token_pos;

	i = 0;
	token_pos = index - columns;
	token = (char *)malloc(sizeof(char) * (columns + 1));
	while (i < columns)
	{
		token[i] = s[token_pos];
		i++;
		token_pos++;
	}
	token[i] = '\0';
	return (token);
}

char	**words_divider(char const *s, char **words, char delimeter, int len)
{
	int		rows;
	int		columns;
	size_t	i;

	rows = 0;
	columns = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == delimeter)
			len = 0;
		else if (++len == 1)
		{
			while (s[i] != delimeter && s[i] != '\0')
			{
				columns++;
				i++;
			}
			words[rows++] = token(s, columns, i);
			columns = 0;
			i--;
		}
	}
	words[rows] = NULL;
	return (words);
}

char	**ft_split(char const *s, char delimeter)
{
	char	**words;
	char	**str;
	int		len;

	len = 0;
	if (!s)
		return (0);
	words = (char **)malloc(sizeof(char *) * (nbr_tokens(s, delimeter) + 1));
	if (words == NULL)
		return (NULL);
	str = words_divider(s, words, delimeter, len);
	return (str);
} */