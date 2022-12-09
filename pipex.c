/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:37:20 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/08 18:45:58 by ybel-hac         ###   ########.fr       */
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
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		id1;

	if (argc != 5 || !check_args(argv))
		return (ft_print_error("Please Check Arguments\n"));
	if (!check_files(argv[1], argv[4]))
		return (0);
	if (pipe(pipex.fd) == -1)
		return (0);
	pipex.env = env;
	pipex.file1 = argv[1];
	pipex.file2 = argv[4];
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	id1 = fork();
	if (id1 == -1)
		return (error_file("failed to fork"));
	if (id1 == 0)
		child_process(pipex);
	else
		parent_process(pipex);
}
