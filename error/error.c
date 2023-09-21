/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:57:40 by msaydam           #+#    #+#             */
/*   Updated: 2023/03/25 14:50:55 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	command_err(char *str)
{
	g_ms.exit_code = 127;
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	if (!is_parent())
		exit(g_ms.exit_code);
}

void	token_err(int type)
{
	char	*red;

	if (type == HERE_DOC)
		red = "<<";
	else if (type == RED_INPUT)
		red = "<";
	else if (type == RED_OUTPUT)
		red = ">";
	else if (type == RED_APPEND)
		red = ">>";
	else if (type == PIPE)
		red = "|";
	else
		red = "newline";
	g_ms.exit_code = 258;
	write(2, "syntax error near unexpected token '", 37);
	write(2, red, ft_strlen(red));
	write(2, "'\n", 2);
}

void	directory_err(char *str)
{
	g_ms.exit_code = 126;
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	if (!is_parent())
		exit(g_ms.exit_code);
}

void	no_file_err(char *str)
{
	if (ft_strchr(str, '/'))
	{
		g_ms.exit_code = 127;
	}	
	else
	{
		g_ms.exit_code = 1;
	}	
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	if (!is_parent())
		exit(g_ms.exit_code);
}
