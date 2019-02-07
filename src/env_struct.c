/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_struct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 12:54:50 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 15:25:34 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		get_env_struct(char **str, t_envlist **list)
{
	char		**envir;
	char		**tab;
	int			i;
	t_envlist	*new;

	i = 0;
	envir = str;
	while (envir[i])
	{
		tab = ft_strsplit(envir[i], '=');
		new = create_env_elem(tab[0], tab[1]);
		new->env = 0;
		env_list_add(list, new);
		i++;
		ft_free_tab(tab);
		tab = NULL;
	}
}

void		env_list_add(t_envlist **l, t_envlist *list)
{
	t_envlist	*tmp;

	if (*l == NULL)
		*l = list;
	else
	{
		tmp = *l;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = list;
	}
}

t_envlist	*create_env_elem(char *var, char *val)
{
	t_envlist	*list;

	list = malloc(sizeof(t_envlist));
	if (list)
	{
		list->var = ft_strdup(var);
		list->val = ft_strdup(val);
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}

void		ft_print_env(t_envlist **env)
{
	t_envlist *list;

	list = *env;
	while (list)
	{
		ft_printf("%s=%s\n", list->var, list->val);
		list = list->next;
	}
}

void		ft_change_env(char *var, char *val, t_envlist **env)
{
	t_envlist	*list;
	t_envlist	*nlist;
	int			i;
	char		**new;

	list = *env;
	i = 0;
	while (list)
	{
		if (ft_strcmp(list->var, var) == 0)
		{
			free(list->val);
			list->val = ft_strdup(val);
			i++;
		}
		list = list->next;
	}
	if (i == 0)
	{
		nlist = create_env_elem(var, val);
		nlist->env = 1;
		env_list_add(env, nlist);
	}
}
