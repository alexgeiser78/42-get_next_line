/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:35:05 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/14 14:56:08 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h> //read, close
# include <stdlib.h>// malloc, free
# include <stdio.h> //printf, BUFFER_SIZE

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);	
char	*ft_join_free(char *buffer, char *buf);
char	*ft_line_isolator(char *buffer);
char	*ft_next(char *buffer);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
