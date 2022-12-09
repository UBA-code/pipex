/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:04 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 03:54:59 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipex *pipex, char **argv, char **env, int argc)
{
	pipex->env = env;
	pipex->file1 = argv[1];
	pipex->file2 = argv[argc - 1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[argc - 2];
	pipex->counter = 2;
}

int	pipex_bonus(t_pipex pipex, int argc, char **argv)
{
	int	id1;
	int	fd;

	if (!check_files(argv[1], argv[argc - 1]))
		exit(1);
	fd = open(pipex.file1, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	while (pipex.counter < argc - 2)
	{
		if (pipe(pipex.fd) == -1)
			exit(1);
		id1 = fork();
		if (id1 == -1)
			exit(1);
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

void	here_doc(t_pipex pipex, char *limiter)
{
	int		id;

	if (pipe(pipex.fd) == -1)
		exit(1);
	dup2(pipex.fd[1], STDOUT_FILENO);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
		loop_and_exit(ft_strjoin_simple(limiter, "\n"));
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	wait(0);
}

int	pipex_bonus_here_doc(t_pipex pipex, int argc, char **argv)
{
	int	id1;
	int	fd;

	pipex.cmd1 = argv[3];
	fd = open(pipex.file2, O_WRONLY | O_CREAT);
	if (fd == -1)
		exit(1);
	close(fd);
	here_doc(pipex, argv[2]);
	while (pipex.counter + 1 < argc - 2)
	{
		if (pipe(pipex.fd) == -1)
			exit(1);
		id1 = fork();
		if (id1 == -1)
			exit(1);
		if (id1 == 0)
			child_process_doc(pipex);
		pipex.counter++;
		pipex.cmd1 = argv[pipex.counter];
		dup2(pipex.fd[0], STDIN_FILENO);
		close(pipex.fd[1]);
	}
	parent_process_doc(pipex);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (!check_args(argv))
		return (ft_print_error("Please Check Arguments\n"));
	init_struct(&pipex, argv, env, argc);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		pipex_bonus_here_doc(pipex, argc, argv);
	else if (!pipex_bonus(pipex, argc, argv))
		exit(1);
}
