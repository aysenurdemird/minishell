/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:57:29 by msaydam           #+#    #+#             */
/*   Updated: 2023/03/20 17:57:30 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_env(char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), env_len() + 1);
	while (g_ms.env[i])
	{
		if (ft_strncmp(g_ms.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(g_ms.env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_array(g_ms.env);
	g_ms.env = new_env;
}

void	builtin_unset(char **input)
{
	char	*data;

	input++;
	while (*input)
	{
		data = ft_strjoin(*input, "=");
		remove_env(data);
		free(data);
		input++;
	}
	set_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
