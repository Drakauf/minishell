/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/07 11:26:36 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:39:37 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_env(char **tab, t_envlist **envir)
{
	if (!tab[1])
	{
		ft_print_env(envir);
	}
	return (1);
}

int		ft_is_env(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] >= 13 || str[i] <= 9) && str[i]
			!= '\\' && str[i] != '$' && str[i] != '=')
		i++;
	if (str[i] == '=')
	{
		i++;
		while (str[i] && (str[i] >= 13 || str[i] <= 9) && str[i]
				!= '\\' && str[i] != '$' && str[i] != '=')
			i++;
	}
	else if (str[i])
		return (0);
	if (!str[i])
		return (1);
	return (0);
}

void	ft_unsetenv(char *str, t_envlist **envir)
{
	t_envlist *list;
	t_envlist *tmp;

	list = *envir;
	if (ft_strcmp(str, list->var) == 0)
	{
		(*envir) = (*envir)->next;
		list->next = NULL;
		free_envlist(&list);
		return ;
	}
	list = list->next;
	tmp = *envir;
	while (list)
	{
		if (ft_strcmp(str, list->var) == 0)
		{
			tmp->next = list->next;
			list->next = NULL;
			free_envlist(&list);
			break ;
		}
		tmp = tmp->next;
		list = list->next;
	}
}

int		ft_set_env(char **tab, t_envlist **envir)
{
	int			i;
	int			j;
	char		**new;
	t_envlist	*list;

	i = 1;
	j = 1;
	while (tab[i] && ft_strcmp(tab[i], "") != 0)
	{
		if (ft_is_env(tab[i]))
		{
			new = ft_strsplit(tab[i], '=');
			if (new[0])
			{
				new[1] ? ft_change_env(new[0], new[1], envir) : 0;
				!new[1] ? ft_change_env(new[0], "", envir) : 0;
			}
			ft_free_tab(new);
			j++;
		}
		i++;
	}
	return (j);
}

int		ft_unset_env(char **tab, t_envlist **envir)
{
	int i;

	i = 1;
	while (tab[i])
	{
		ft_unsetenv(tab[i], envir);
		i++;
	}
	return (1);
}
