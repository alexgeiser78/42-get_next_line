/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:45 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/06 18:47:40 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h> // open
#include <fcntl.h> // open

int main(void)
{
	char *buf;
	int fd;
	int read_result;
	char *result;

	fd = open("text.txt", O_RDONLY);
	buf = (char *) malloc(1);
	read_result = read(fd, buf, 100);
	buf[read_result] = '\0';
	printf("nombre de caracteres dans le fichier: %i\n%s", read_result, buf);

//	read_result = read(fd, buf, 100);
	result = get_next_line(fd);
	printf("%s\n", result);

	close(fd);
	return(0);
}



