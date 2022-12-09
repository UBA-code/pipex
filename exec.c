/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:08:36 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 03:47:42 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < len)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

int	get_start(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (i);
		i++;
	}
	return (0);
}

char	*get_paths(char **tab)
{
	int		i;
	char	*str;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "PATH", 4))
		{
			str = ft_substr(tab[i], get_start(tab[i]), ft_strlen(tab[i]));
			return (str);
		}
		i++;
	}
	return (0);
}

void	ft_exec(char *cmd, char **env)
{
	t_exec_utils	exec;

	exec.i = 0;
	exec.cmd_arg = ft_split(cmd, ' ');
	execve(exec.cmd_arg[0], exec.cmd_arg, env);
	exec.paths_line = get_paths(env);
	exec.paths = ft_split(exec.paths_line, ':');
	while (exec.paths[exec.i])
	{
		exec.main_cmd = ft_strjoin_pipex(exec.paths[exec.i], exec.cmd_arg[0]);
		execve(exec.main_cmd, exec.cmd_arg, env);
		free(exec.main_cmd);
		exec.i++;
	}
	perror(exec.cmd_arg[0]);
	tab_free(exec.paths);
	tab_free(exec.cmd_arg);
	free(exec.paths_line);
}
