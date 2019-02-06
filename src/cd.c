/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/06 15:35:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 17:36:52 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd_back(char **tab, t_envlist **env)
{
	char *pwd;
	char *oldpwd;

	oldpwd = NULL;
	pwd = ft_strdup(ft_get_val("PWD", env));
	oldpwd = ft_strdup(ft_get_val("OLDPWD", env));
	ft_change_env("PWD", oldpwd, env);
	ft_change_env("OLDPWD", pwd, env);
	if (oldpwd)
		chdir(oldpwd);
	ft_strdel(&pwd);
	ft_strdel(&oldpwd);
}

void	ft_cd_two(char **tab, t_envlist **env)
{
	char *pwd;

	pwd = ft_strdup(ft_get_val("PWD", env));
	ft_change_env("OLDPWD", pwd, env);
	ft_change_env("PWD", tab[1], env);
	chdir(tab[1]);
	ft_strdel(&pwd);
}

int		ft_cd(char **tab, t_envlist **env)
{
	if (ft_tab_len(tab) > 2)
		ft_printf("cd: too many arguments\n");
	else if (tab[1] && ft_strcmp("-", tab[1]) == 0)
		ft_cd_back(tab, env);
	else if (tab[1])
	{
		if ((access(tab[1], F_OK) == -1))
		{
			ft_printf("cd: no such file or directory: %s\n", tab[1]);
			return (1);
		}
		if ((access(tab[1], X_OK) == -1))
		{
			ft_printf("cd: not a directory or don't have access: %s\n", tab[1]);
			return (1);
		}
		ft_cd_two(tab, env);
	}
	return (1);
}
