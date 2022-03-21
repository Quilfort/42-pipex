/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 14:29:45 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/03/21 13:45:10 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char	**path;	
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		print_error();
	return (path);
}

char	*right_path(t_vars *vars)
{
	char	*slash;
	char	*pipex_path;
	char	*my_path;
	int		i;
	int		index_split;

	i = 0;
	index_split = split_index(vars->path);
	while (i < index_split)
	{
		slash = ft_strjoin(vars->path[i], "/");
		if (!slash)
			print_error();
		pipex_path = ft_strjoin(slash, vars->path_cmd);
		if (!pipex_path)
			print_error();
		if (access(pipex_path, F_OK) == 0)
			my_path = ft_strdup(pipex_path);
		free(slash);
		free(pipex_path);
		i++;
	}
	if (!my_path)
		print_error();
	return (my_path);
}