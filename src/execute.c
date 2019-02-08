/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 14:36:33 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 16:56:13 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		env_len(t_envlist **envir)
{
	int i;
	t_envlist *list;

	i = 0;
	list = *envir;
	while(list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	**env_tab(t_envlist **envir)
{
	t_envlist *list;
	int 		i;
	char		**tab;
	char		c;

	list = *envir;
	if (!(tab = malloc(sizeof(tab) * (env_len(envir) + 1))))
		return (NULL);
	i = 0;
	while(list)
	{
		tab[i] = ft_strjoin(list->var, "=");
		tab[i] = ft_strjoinfree(&(tab[i]), list->val);
		list = list->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	execute(char *exec, char **tab, char **en)
{
	int		w;
	pid_t	p;

	p = fork();
	if (p == 0)
		execve(exec, tab, en);
	else
		wait(&w);
}

void	ft_exec(char **tab, t_envlist **envir, char **en)
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
		if (ft_valid_execp(execp, &j))
		{
			execute(execp, tab, en);
			j++;
		}
		ft_strdel(&execp);
	}
	ft_free_tab(path);
	(j == 0) ? ft_printf("%s: Command not found\n", tab[0]) : 0;
	(j == 20) ? ft_printf("%s: Can't execute\n", tab[0]) : 0;
	ft_strdel(&str);
}

void	ft_to_execute(char **tab, t_envlist **envir)
{
	char	**en;

	en = env_tab(envir);
	if (ft_is_path(tab[0]))
	{
		if (ft_valid_path(tab[0]))
			execute(tab[0], tab, en);
		return ;
	}
	if (ft_is_builtin(tab, envir))
		return ;
	else
	{
		ft_exec(tab, envir, en);
	}
	ft_free_tab(en);
}
