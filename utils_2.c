/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:56:55 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 03:01:36 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_file(char *file)
{
	perror(file);
	return (0);
}

int	check_files_exists(char *file1, char *file2)
{
	int	fd1;
	int	fd2;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
		return (error_file(file1));
	fd2 = open(file2, O_WRONLY | O_CREAT, 0777);
	if (fd2 == -1)
		return (error_file(file2));
	close(fd1);
	close(fd2);
	return (1);
}

int	check_files(char *file1, char *file2)
{
	if (!check_files_exists(file1, file2))
		return (0);
	return (1);
}

int	check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_print_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	return (0);
}
