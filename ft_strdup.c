/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:47:08 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/05 22:03:47 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "./pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (s1[i])
	{
	dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
