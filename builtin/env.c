/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:57:24 by msaydam           #+#    #+#             */
/*   Updated: 2023/03/25 14:57:23 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(int flag)
{
	char	**env;

	env = g_ms.env;
	if (flag == 1)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else if (flag == 0)
	{
		while (*env)
		{
			printf("declare -x %s\n", *env);
			env++;
		}	
	}
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
