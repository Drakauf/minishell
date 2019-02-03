/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dquote.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:27:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/03 15:46:17 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_dquote_len(char *s, int *i, t_envlist **envir)
{
	int		m;
	int		l;

	m = *i + 1;
	l = 0;
	while (s[m])
	{
		if (s[m] == '"' && ((m > 0 && s[m  - 1] != '\\') ||
		(s[m - 1] != '\\' && (!s[m  + 1] || (s[m + 1] <= 13
		 && s[m  + 1] >= 9) || s[m  + 1] == ' '))))
		{
			while (s[m + 1] && !((s[m +  1] >= 9 &&
					s[m  + 1] <= 13) || s[m  + 1] == ' ' ||
					s[m + 1] == '\'' || s[m  + 1] == '"'))
			{
				l++;
				m++;
			}
			break ;
		}
		if (s[m] == '$' && s[m - 1] != '\\')
		{
//		dprintf(1, "Here  m = %d, l = %d\n", m, l);
			l += ft_var_len(s, &m, envir);
//		dprintf(1, "Here  m = %d, l = %d\n",m , l);
		}
//		dprintf(1, "Here \n");
		m++;
		l++;
	}
	if (s[m] == '"')
		*i += m - *i  + 1;
	else
		*i += m - * i;
	return (l);
}
