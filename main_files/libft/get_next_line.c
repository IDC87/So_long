/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:18:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/30 13:52:27 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(char *line, int fd, char *buf)
{
	int		byte_read;
	char	*tmp;

	if (!line || !ft_strchr(line, '\n'))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		while (byte_read > 0)
		{
			buf[byte_read] = '\0';
			if (!line)
				line = ft_substr(buf, 0, byte_read);
			else
			{
				tmp = line;
				line = ft_strjoin(line, buf);
				free(tmp);
			}
			if (ft_strchr(line, '\n'))
				break ;
			byte_read = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
	return (line);
}

char	*free_line(char *line)
{
	free(line);
	line = 0;
	return (line);
}

char	*extract(char *line, int carrier)
{
	char	*tmp;

	tmp = line;
	line = ft_substr(ft_strchr(line, '\n'), 1, carrier - 1);
	free(tmp);
	return (line);
}

int	carrier(char *line)
{
	int	carrier;

	carrier = ft_strlen(ft_strchr(line, '\n'));
	return (carrier);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	char		*result;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || fd < 0 || BUFFER_SIZE < 1 || read(fd, line, 0) == -1)
	{
		free(buf);
		return (0);
	}
	line = read_line(line, fd, buf);
	if (!line)
		return (NULL);
	if (ft_strlen(line) == 0)
		return (free_line(line));
	if (!ft_strchr(line, '\n'))
	{
		result = ft_substr(line, 0, ft_strlen(line));
		line = free_line(line);
		return (result);
	}
	result = ft_substr(line, 0, ft_strlen(line) - carrier(line) + 1);
	line = extract(line, carrier(line));
	return (result);
}
/* int main()
{
    int fd;   
    int i = 0;
    
    fd = open("notas.txt", O_RDONLY);
    //printf("%d", fd);
    //fd = open("teste.txt", O_RDONLY);
    //fd = open("The_new_text.txt", O_RDONLY);
    while(i < 3)
    {
        //printf("BUFFER_SIZE: %d", BUFFER_SIZE);
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
} */

/* int	main()
{
	int	fd;
	fd = open("notas.txt", O_RDONLY);
    fd = open("teste.txt", O_RDONLY);
    fd = open("The_new_text.txt", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	printf("FD: %d\n", fd);
	printf("1:%s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	 printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd)); 
	return (0);
}
 */
