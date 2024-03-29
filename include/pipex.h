/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 12:24:53 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/03/30 10:33:47 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdbool.h>
# include <libft.h>

typedef struct s_vars {
	int		f1;
	int		f2;
	int		argc;
	int		argv_index;
	char	**cmd;
	char	**path;
	char	*path_cmd;
	char	*my_path;
}				t_vars;

//path
char	**find_path(char **envp, t_vars *vars);
char	*right_path(t_vars *vars);
void	free_split(char **input);
int		split_index(char **split);

//error
void	print_error(t_vars *vars);

#endif