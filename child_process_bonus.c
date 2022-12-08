/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:19:18 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/08 17:08:40 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	child_process(t_pipex pipex)
{
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	ft_exec(pipex.cmd1, pipex.env);
}
