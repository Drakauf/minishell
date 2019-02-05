/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 14:36:33 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:23:00 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(char *exec, char **tab)
{
	int        w;
	pid_t    p;

	p = fork();
	if (p == 0)
		execve(exec, tab, NULL);
	else
		wait(&w);
}

void	ft_exec(char **tab, t_envlist **envir)
{
	char *str;
	char **path;

	str = ft_strdup(ft_get_path(envir));
//	ft_free_tab(str);
	dprintf(1, "Here\n");
	int i;
	i = 0;
	dprintf(1, "%s\n", str);
	path = ft_strsplit(str, ':');
	while (path[i])
	{
		dprintf(1, "%s\n", path[i]);
		i++;
	}
}

void	ft_to_execute(char **tab, t_envlist **envir)
{
	if (ft_is_path(tab[0]))
	{
		ft_printf("path\n");
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
