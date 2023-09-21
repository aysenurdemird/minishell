/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:59:29 by msaydam           #+#    #+#             */
/*   Updated: 2023/03/28 16:08:08 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	g_ms.exit_code = 0;
	g_ms.parent_pid = getpid();
	g_ms.paths = NULL;
	set_env(env);
	set_paths();
}

void	main_continue(char *input)
{
	if (ft_pipecheck(input))
		init_shell(input);
	add_history(input);
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	init_app(env);
	while (ac && av)
	{
		g_ms.ignore = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\e[0;37m", 8);
		input = readline("minishell ~ % ");
		write(1, "\e[0m", 5);
		ctrl_d(input);
		if (g_ms.ignore)
		{
			free(input);
			input = malloc(1);
		}
		else if (*input && g_ms.ignore == FALSE)
			main_continue(input);
		free(input);
	}
	exit(g_ms.exit_code);
}
