/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:35:05 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/06 18:47:43 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read, close
#include <stdlib.h>// malloc, free
#include <stdio.h> //printf, BUFFER_SIZE

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);	
char	*ft_free(char *buffer, char *buf);
char	*ft_line(char *buffer);
