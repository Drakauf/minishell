/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/02 10:55:59 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/02 11:10:16 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_handle_tab(char **tab)
{
	int i;

	i = ft_tab_len(tab);
	dprintf(1, "tablen = %i\n", i);
	ft_free_tab(tab);
	return (tab);
}
