/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:05:40 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 03:54:48 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_pipex pipex)
{
	int		fd;

	fd = open(pipex.file2, O_WRONLY | O_TRUNC);
	dup2(fd, STDOUT_FILENO);
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	close(fd);
	ft_exec(pipex.cmd2, pipex.env);
}

void	parent_process_doc(t_pipex pipex)
{
	int		fd;

	fd = open(pipex.file2, O_WRONLY | O_APPEND);
	dup2(fd, STDOUT_FILENO);
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	close(fd);
	ft_exec(pipex.cmd2, pipex.env);
}
