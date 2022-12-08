/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:04 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/08 18:28:23 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_bonus(t_pipex pipex, int argc, char **argv)
{
	int	id1;
	int	fd;

	fd = open(pipex.file1, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	while (pipex.counter < argc - 2)
	{
		if (pipe(pipex.fd) == -1)
			return (0);
		id1 = fork();
		if (id1 == -1)
			return (0);
		if (id1 == 0)
			child_process(pipex);
		pipex.counter++;
		pipex.cmd1 = argv[pipex.counter];
		dup2(pipex.fd[0], STDIN_FILENO);
		close(pipex.fd[1]);
	}
	parent_process(pipex);
	return (1);
}

void	init_struct(t_pipex *pipex, char **argv, char **env, int argc)
{
	pipex->env = env;
	pipex->file1 = argv[1];
	pipex->file2 = argv[argc - 1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[argc - 2];
	pipex->counter = 2;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (!check_args(argv))
		return (ft_print_error("Please Check Arguments\n"));
	if (!check_files(argv[1], argv[argc - 1]))
		return (0);
	init_struct(&pipex, argv, env, argc);
	if (!pipex_bonus(pipex, argc, argv))
		return (error_file("error"));
}
