/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/06 15:35:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 17:37:55 by shthevak    ###    #+. /#+    ###.fr     */
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
	if (pwd)
	{
		ft_change_env("OLDPWD", pwd, env);
		ft_strdel(&pwd);
	}
	if (oldpwd)
	{
		ft_change_env("PWD", oldpwd, env);
		chdir(oldpwd);
		ft_strdel(&oldpwd);
	}
}

void	ft_cd_two(char **tab, t_envlist **env)
{
	char *pwd;
	char dir[999];

	pwd = ft_strdup(ft_get_val("PWD", env));
	if (pwd)
	{
		ft_change_env("OLDPWD", pwd, env);
		ft_strdel(&pwd);
	}
	chdir(tab[1]);
	getcwd(dir, 999);
	ft_change_env("PWD", dir, env);
}

void	ft_cd_three(char **tab, t_envlist **env)
{
	char	*str;
	char	*pwd;

	str = NULL;
	str = ft_strdup(ft_get_val("HOME", env));
	if (str)
	{
		pwd = ft_strdup(ft_get_val("PWD", env));
		if (pwd)
		{
			ft_change_env("OLDPWD", pwd, env);
			ft_strdel(&pwd);
		}
		chdir(str);
		ft_change_env("PWD", str, env);
		ft_strdel(&str);
	}
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
	else if (!tab[1])
		ft_cd_three(tab, env);
	return (1);
}
