/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:31:23 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 02:39:34 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	while (s2[i])
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
}

char	*ft_strjoin_pipex(char *s1, char *s2)
{
	char	*final_str;
	int		len;

	final_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!final_str)
		return (0);
	ft_strcat(final_str, s1);
	len = ft_strlen(final_str);
	final_str[len] = '/';
	final_str[len + 1] = '\0';
	ft_strcat(final_str, s2);
	return (final_str);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
