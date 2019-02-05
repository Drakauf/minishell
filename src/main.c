/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 18:24:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 16:38:56 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parse_line(char *line, t_envlist **envir)
{
	char	*str;
	char	**tab;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	str = NULL;
	while (line[i])
	{
		i = separate_scolon(line, i);
		((str = ft_strsub(line, j, i))) ? 0: exit(0);
		tab = ft_split_com(str);
		tab[0] ? tab = ft_handle_tab(tab, envir) : 0;
		tab[0] ? ft_to_execute(tab,envir): 0;
		str ? free(str): 0;
		ft_free_tab(tab);
		line[i] ? i++: 0;
		j = i;
	}
}

int		ft_prompt(t_envlist **envir)
{
	static int	i = 1;
	char	*line;

	line = NULL;
	if (i)
	{
		/**** Print Dir ****/
		ft_putstr("$> ");
		i = 0;
	}
	if (get_next_line(0, &line))
	{
		if (ft_strcmp("exit", line) == 0)
		{
			free(line);
			return (0);
		}
		ft_parse_line(line, envir);
		free(line);
		line = NULL;
		i = 1;
	}
	return (1);
}

int main(int argc, char **argv, char **env)
{
	t_envlist	*env_list;
	print_drak();
	env_list = NULL;
	get_env_struct(env, &env_list);
	while (1)
	{
		if (!(ft_prompt(&env_list)))
			break;
	}
	free_envlist(&env_list);
	return (0);
}
