/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   var.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 12:50:36 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 17:12:45 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_val(char *str, t_envlist **envir)
{
	t_envlist	*list;

	list = *envir;
	while (list)
	{
		if (ft_strcmp(str, list->var) == 0)
			return (list->val);
		list = list->next;
	}
	return (NULL);
}

char	*ft_get_path(t_envlist **envir)
{
	t_envlist	*list;

	list = *envir;
	while (list)
	{
		if (ft_strcmp("PATH", list->var) == 0)
			return (list->val);
		list = list->next;
	}
	return (NULL);
}

int		ft_copy_var(char *str, char **new, int *i, t_envlist **envir)
{
	char		*var;
	t_envlist	*list;

	list = *envir;
	if (str[(*i)] == '~')
		var = ft_strdup("HOME");
	else
		var = ft_split_var(str + *i + 1);
	while (list)
	{
		if (ft_strcmp(var, list->var) == 0)
		{
			*new = ft_strcat(*new, list->val);
			*i = (*i) + (str[*i] == '~' ? 0 : ft_strlen(var));
			ft_strdel(&var);
			return (ft_strlen(list->val));
		}
		list = list->next;
	}
	*i = (*i) + (str[*i] == '~' ? 0 : ft_strlen(var));
	ft_strdel(&var);
	return (0);
}

int		ft_var_len(char *com, int *i, t_envlist **envir)
{
	char		*var;
	t_envlist	*list;

	list = *envir;
	if (com[(*i)] == '~')
	{
		var = ft_strdup("HOME");
	}
	else
		var = ft_split_var(com + *i + 1);
	while (list)
	{
		if (ft_strcmp(var, list->var) == 0)
		{
			*i = (*i) + (com[(*i)] == '~' ? 0 : ft_strlen(var));
			ft_strdel(&var);
			return (ft_strlen(list->val));
		}
		list = list->next;
	}
	*i = (*i) + (com[*i] == '~' ? 0 : ft_strlen(var));
	ft_strdel(&var);
	return (0);
}

char	*ft_split_var(char *c)
{
	int i;

	i = 0;
	while (c[i] && c[i] != '\\' && c[i] != '\'' && c[i] != '"'
			&& c[i] != '$' && c[i] != ' ')
		i++;
	return (ft_strsub(c, 0, i));
}
