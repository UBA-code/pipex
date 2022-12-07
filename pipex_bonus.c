/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:04 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/07 18:49:09 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	int id1;
	int id2;
	int cmd_count;

	cmd_count = argc - 3;
	if (!check_args(argv))
		return (ft_print_error("Please Check Arguments\n"));
	if (!check_files(argv[1], argv[argc - 1]) || pipe(pipex.fd) == -1)
		return (0);
	init_struct(&pipex, argv, env);
	while (cmd_count-- >= 0)
	{
		if ()
		id1 = fork();
		id2 = fork();
		if (id2 == 0)
			child_process(pipex);
		else if (id1 == 0)
			parent_process(pipex);
	}
}
