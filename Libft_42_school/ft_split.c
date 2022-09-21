/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:12:28 by ivda-cru          #+#    #+#             */
/*   Updated: 2021/12/10 18:27:58 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_tokens(char const *s, char delimeter)
{
	int	i;
	int	j;
	int	len;
	int	token_count;

	i = 0;
	j = 0;
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

static char	*token(const char *s, int columns, int index)
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
}
/* int main (int argc, char **argv)
{
    //"      split       this for   me  !       "; os dois inputs que nao dao
    //"                  olol"
    char *str = "1-2-3-4-5-6-7-8--8-8--8-4------4--4";
    char delimeter = '-';
    

    printf("\n%d\n", nbr_tokens(str, delimeter));


    int i = 0;
    char **test = ft_split(str, delimeter);
      while (test[i])
    {
        printf("\n$%s$\n\n", test[i]);
        i++;
    }  

    printf("\n$%s$\n\n", test[0]);
    printf("\n$%s$\n\n", test[1]);
    return (0);
} */
