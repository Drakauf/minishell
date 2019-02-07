/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 14:36:33 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:43:35 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(char *exec, char **tab)
{
	int		w;
	pid_t	p;

	p = fork();
	if (p == 0)
		execve(exec, tab, NULL);
	else
		wait(&w);
}

void	ft_exec(char **tab, t_envlist **envir)
{
	char	*str;
	char	**path;
	char	*execp;
	int		j;
	int		i;

	str = ft_strdup(ft_get_path(envir));
	i = -1;
	j = 0;
	path = ft_strsplit(str, ':');
	while (path && path[++i])
	{
		execp = ft_strjoin(path[i], "/");
		execp = ft_strjoinfree(&execp, tab[0]);
		if (ft_valid_execp(execp))
		{
			execute(execp, tab);
			j++;
		}
		ft_strdel(&execp);
	}
	ft_free_tab(path);
	(j == 0) ? ft_printf("%s: Command not found\n", tab[0]) : 0;
	ft_strdel(&str);
}

void	ft_to_execute(char **tab, t_envlist **envir)
{
	if (ft_is_path(tab[0]))
	{
		if (ft_valid_path(tab[0]))
			execute(tab[0], tab);
		return ;
	}
	if (ft_is_builtin(tab, envir))
		return ;
	else
	{
		ft_exec(tab, envir);
	}
}
