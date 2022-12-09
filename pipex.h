/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:37:51 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/09 02:45:49 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdint.h>
# include "get_line.h"

typedef struct s_pipex
{
	int		fd[2];
	char	*cmd1;
	char	*cmd2;
	char	**env;
	char	*file1;
	char	*file2;
	int		counter;
}	t_pipex;

typedef struct s_exec_utils
{
	char	**paths;
	char	**cmd_arg;
	int		i;
	char	*main_cmd;
	char	*paths_line;
}	t_exec_utils;

size_t	ft_strlen(const char *str);
char	*ft_strjoin_pipex(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_strcat(char *s1, char *s2);
void	ft_swap(char **s1, char **s2);
void	parent_process(t_pipex pipex);
void	child_process(t_pipex pipex);
void	ft_exec(char *cmd, char **env);
void	tab_free(char **tab);
int		check_Read_file(char *file);
int		check_Write_file(char *file);
int		check_files(char *file1, char *file2);
int		check_args(char **args);
int		error_file(char *file);
int		ft_print_error(char *msg);
void	init_struct(t_pipex *pipex, char **argv, char **env, int argc);
int		ft_strncmp(char *s1, char *s2, int len);
char	*ft_strjoin_simple(char *s1, char *s2);
void	child_process_doc(t_pipex pipex);
void	ft_putstr(char *str);
void	parent_process_doc(t_pipex pipex);
void	loop_and_exit(char *limit);

#endif
