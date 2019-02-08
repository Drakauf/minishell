/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 15:26:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 17:38:07 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab[i]);
		free(tab);
		tab = NULL;
	}
}

void	free_envlist(t_envlist **list)
{
	t_envlist *tmp;
	t_envlist *tmp2;

	tmp = *list;
	while (tmp)
	{
		free(tmp->var);
		free(tmp->val);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
