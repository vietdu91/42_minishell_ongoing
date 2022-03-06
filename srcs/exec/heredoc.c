/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:53:09 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/06 17:43:02 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_heredoc(t_pars_list *l)
{
	int			i;
	t_pars_node	*node;

	i = 0;
	node = l->head;
	while (node)
	{
		if (node->type == 18)
			i++;
		node = node->next;
	}
	return (i);
}

int	fill_d_tab_heredoc(t_args *args, int size, char **eof)
{
	int	i;

	if (!size)
		return (0);
	i = 0;
	args->hdocs = malloc(sizeof(char *) * (size + 1));
	if (!args->hdocs)
		return (-1);
	while (i < size)
	{
		args->hdocs[i] = NULL;
		if (!read_heredoc(args->hdocs[i], eof[i]))
		{
			malloc_failed(args->hdocs, i);
			return (-2);
		}
		i++;
	}
	return (1);
}
