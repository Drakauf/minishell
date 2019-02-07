/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_handle.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 16:48:26 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 16:48:50 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_echo(char **tab, t_envlist **envir)
{
	int i;
	int j;
	int k;

	j = 0;
	if (tab[1] && ft_strcmp("-n", tab[1]) == 0)
	{
		j++;
		i = 2;
	}
	else
		i = 1;
	k = 0;
	while (tab[i])
	{
		k != 0 ? ft_printf(" ") : 0;
		ft_printf("%s", tab[i]);
		k++;
		i++;
	}
	j == 0 ? ft_printf("\n") : ft_printf("[uwhite][black]%%[eoc][eou]\n");
	return (1);
}

int		ft_is_builtin(char **tab, t_envlist **envir)
{
	int j;

	j = 0;
	if (ft_strcmp(tab[0], "echo") == 0)
		j = ft_echo(tab, envir);
	else if (ft_strcmp(tab[0], "cd") == 0)
		j = ft_cd(tab, envir);
	else if (ft_strcmp(tab[0], "setenv") == 0)
		j = ft_set_env(tab, envir);
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		j = ft_unset_env(tab, envir);
	else if (ft_strcmp(tab[0], "env") == 0)
		j = ft_env(tab, envir);
	return (j);
}
