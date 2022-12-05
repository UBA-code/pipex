/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:05:40 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/05 21:58:20 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_pipex pipex)
{
	int		fd;
	char	**cmd;

	fd = open(pipex.file2, O_WRONLY);
	cmd = ft_split(pipex.cmd2, ' ');
	dup2(fd, STDOUT_FILENO);
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	close(fd);
	ft_exec(pipex.cmd2, pipex.env);
}
