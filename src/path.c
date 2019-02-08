/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 16:39:01 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 13:52:40 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_is_path(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int		ft_valid_path(char *str)
{
	if ((access(str, F_OK) == -1))
	{
		ft_printf("%s: Command not found\n", str);
		return (0);
	}
	if ((access(str, X_OK) == -1))
	{
		ft_printf("%s: Can't be executed\n", str);
		return (0);
	}
	return (1);
}

int		ft_valid_execp(char *str, int *j)
{
	if ((access(str, F_OK) == -1))
		return (0);
	if ((access(str, X_OK) == -1))
	{
		*j = 20;
		return (0);
	}
	return (1);
}
