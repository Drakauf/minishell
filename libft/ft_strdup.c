/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:10:17 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*r;

	if (!s)
		return (NULL);
	if (!(r = malloc(sizeof(*r) * (ft_strlen(s) + 1))))
		return (NULL);
	l = 0;
	while (s[l])
	{
		r[l] = s[l];
		l++;
	}
	r[l] = '\0';
	return (r);
}
