/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:56:55 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/05 20:16:26 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_Read_file(char *file)
{
	if (access(file, R_OK) == 0)
		return (1);
	return (0);
}

int check_Write_file(char *file)
{
	if (access(file, W_OK) == 0)
		return (1);
	return (0);
}

int error_file(char *file)
{
	perror(file);
	return (0);
}

int check_files_exists(char *file1, char *file2)
{
	int fd1;
	int fd2;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
		return (error_file(file1));
	fd2 = open(file2, O_WRONLY | O_CREAT, 0777);
	if (fd2 == -1)
		return (error_file(file2));
	return (1);
}


int check_files(char *file1, char *file2)
{
	if (!check_files_exists(file1, file2))
		return (0);
	return (1);
}