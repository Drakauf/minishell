/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   semicolon.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:07:23 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:33:25 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		next_comma(int i, char c, char *line)
{
	int	k;

	k = 1;
	while (line[i + k])
	{
		if (line[i + k] == c && (i + k - 1 >= 0 && line[i + k - 1] != '\\'))
		{
			break ;
		}
		k++;
	}
	if (line[i + k])
		return (i + k);
	else
		return (i);
}

int		separate_scolon(char *line, int k)
{
	int		i;

	i = 0;
	while (line[k + i])
	{
		if (line[k + i] == '\'')
			i = next_comma(i, '\'', line);
		else if (line[k + i] == '\"')
			i = next_comma(i, '\"', line);
		else if (line[k + i] == ';' && ((k + i == 0) || (line[k + i - 1]
				&& line[k + i - 1] != '\\')))
			return (k + i);
		if (line[i + k])
			i++;
	}
	return (k + i);
}
