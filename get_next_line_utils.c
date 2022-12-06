/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:38:26 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/06 18:47:50 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char *temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return(temp);
}


int ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;
	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return((char *)s + i);
		i++;			
	}	
	if (s[i] == (const char)c)
		return ((char *)s + i);	
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*soutput;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	soutput = (char *)malloc(sizeof(*s1) *(ft_strlen(s1) + ft_strlen(s2) + 1));
			if(!soutput)
				return(NULL);
				while (s1[i])
				{
				soutput[j] = s2[i];
				i++;
				j++;
				}
				i = 0;
				while(s2[i])
				{
				soutput[j] = s2[i];
				i++;
				j++;
				}
				soutput[j] = '\0';
				return(soutput);
}
