/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:14 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/06 18:47:46 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_line(char *buffer)
{
char *line;
int 	i;

i = 0;
if (!buffer[i])
	return (NULL);
while (buffer[i])
	i++;
	line = malloc(sizeof(char) * i + 2);
	i = 0;
while (buffer[i])
{
	line[i] = buffer[i];
	i++;
}
if	(buffer[i] && buffer[i])
	line[i++] = '\n';
	return (line);
}

char	*ft_file_reader(int fd, char *result)
{
	char *buffer; 
	int	byte_read;

	byte_read = 1;
	if(!result)
		result = (char *)malloc(sizeof(1));
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);

	while(byte_read > 0)
	{
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if(byte_read == -1)
	{
		free(buffer);
		return(NULL);
	}
	buffer[byte_read] = 0;
	result = ft_free(result, buffer);
	if (ft_strchr(buffer, '\n'))
		break;
	}
	free(buffer);
// printf("%s\n", result);	
return(result);

}	

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	line = NULL;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	return (NULL);
	// BUFFER_SIZE = valeur donnee par l'utilisateur
// ssize_t read(int fildes, void *buf, size_t nbyte)

	buffer = ft_file_reader(fd, buffer);	
	if(!buffer)
		return(NULL);
	line = ft_line(buffer);
	printf("ligne: %s\n", line);
//	buffer = ft_next(buffer);
return (line);
}
