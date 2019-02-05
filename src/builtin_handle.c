/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_handle.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 16:48:26 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:23:02 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_is_builtin(char **tab, t_envlist **envir)
{
	int j;

	j = 0;
	if (ft_strcmp(tab[0], "echo") == 0)
		j = ft_printf("echo to code\n");
	else if (ft_strcmp(tab[0], "cd") == 0)
		j = ft_printf("cd to code\n");
	else if (ft_strcmp(tab[0], "setenv") == 0)
		j = ft_printf("setenv to code\n");
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		j = ft_printf("unsetenv to code\n");
	else if (ft_strcmp(tab[0], "env") == 0)
		j = ft_printf("env to code\n");
	else if (ft_strcmp(tab[0], "exit") == 0)
		j = ft_printf("exit to code\n");
	return (j);
}
