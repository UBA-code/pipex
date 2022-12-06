/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:19:18 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/05 21:58:32 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	child_process(t_pipex pipex)
{
	int		fd;

	fd = open(pipex.file1, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	close(fd);
	ft_exec(pipex.cmd1, pipex.env);
}
