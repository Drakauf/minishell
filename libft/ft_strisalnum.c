/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisalnum.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 13:05:16 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 13:13:25 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strisalnum(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
