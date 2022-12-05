/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:37:51 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/05 22:03:09 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd[2];
	char	*cmd1;
	char	*cmd2;
	char	**env;
	char	*file1;
	char	*file2;
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
char	*ft_strjoin(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);
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

#endif