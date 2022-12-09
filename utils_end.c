/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:24:01 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/08 23:26:47 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_simple(char *s1, char *s2)
{
	char	*final_str;
	int		total_len;
	int		i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	final_str = malloc(sizeof(char) * (total_len + 1));
	if (!final_str)
		return (0);
	ft_strcpy(final_str, s1);
	i = ft_strlen(final_str);
	ft_strcpy(final_str + i, s2);
	return (final_str);
}
