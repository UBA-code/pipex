/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:19:18 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 02:41:26 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	child_process(t_pipex pipex)
{
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	ft_exec(pipex.cmd1, pipex.env);
}

void	child_process_doc(t_pipex pipex)
{
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	ft_exec(pipex.cmd1, pipex.env);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	loop_and_exit(char *limit)
{
	char	*line;

	write(2, &"heredoc> ", 10);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(limit, line, ft_strlen(limit)) == 0)
			exit(0);
		ft_putstr(line);
		free(line);
		write(2, &"heredoc> ", 10);
		line = get_next_line(0);
	}
}
