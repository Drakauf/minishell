/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 17:48:17 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:15:27 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoinfree(char **s1, char *s2)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ret[0] = '\0';
	ret = ft_strcat(ret, *s1);
	ret = ft_strcat(ret, s2);
	ft_strdel(s1);
	return (ret);
}
