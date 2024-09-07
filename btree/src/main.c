/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:17:24 by madias-m          #+#    #+#             */
/*   Updated: 2024/09/07 14:17:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btree.h"

char *to_str(enum token tk)
{
	if (tk == 2)
		return ("PIPE");
	else if (tk == 1)
		return ("REDIRECT");
	else
		return ("WORD");
}

enum token	what_is_it(char *str)
{
	if (!ft_strncmp(str, ">", 1))
		return (REDIRECT);
	else if (!ft_strncmp(str, ">>", 2))
		return (REDIRECT);
	else if (!ft_strncmp(str, "<", 1))
		return (REDIRECT);
	else if (!ft_strncmp(str, "<<", 2))
		return (REDIRECT);
	else if (!ft_strncmp(str, "|", 1))
		return (PIPE);
	else
		return (WORD);
}

void	do_it(char *args)
{
	char	**splitted;
	int		i;

	splitted = ft_split(args, ' ');
	i = -1;
	while (splitted[++i])
		ft_printf("%s é um: %s\n", splitted[i], to_str(what_is_it(splitted[i])));
}


int main(void)
{
	while (1)
	{
		readline("digite o cmd: \n");
		if (!ft_strncmp(rl_line_buffer, "exit", 5))
		{
			free(rl_line_buffer);
			exit(0);
		}
		add_history(rl_line_buffer);
		//rl_replace_line("current", 0);
		do_it(rl_line_buffer);
	}
	return (0);	
}
