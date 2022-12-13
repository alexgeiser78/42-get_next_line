/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:14 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/13 18:29:17 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i ;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) -i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
	line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

//fonction qui ecrit la ligne
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	i++;
	line = (char *)malloc(sizeof(char) *(i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
	line[i] = buffer[i];
	i++;
	}
	if (buffer[i] == '\n')
	{
	line[i] = buffer[i];
	i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_file_reader(int fd, char *result)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	byte_read = 1;
	if (!result)
		result = ft_calloc(1, 1);
	while (byte_read != 0 && !ft_strchr(result, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
	buffer[byte_read] = '\0';
	result = ft_free(result, buffer);
	}
	free(buffer);
	return (result);
}	
//nbr de byte lie au BUFFER_SIZE
//gestion d'erreur
//on ajoute la fin de chaine
//retourne l'assemblage

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}	
			return (NULL);
	}
			buffer = ft_file_reader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}


//si on a rempli le buffer avec qqch mais que le reste n'a pas fonctionne on free le buffer
//et on reinitialise le buffer
//ligne de retour
//ligne stockee temporairement
//gestion des erreurs
//BUFFER_SIZE = valeur donnee par l'utilisateur
//ssize_t read(int filde, void *buf, size_t nbytes)
//on met dans le buffer tout le fichier
//gestion d'errur si file_reader n'a pas fonctionne
//ecriture de la ligne depuis le buffer
//decalage du buffer sur la ligne suivante
