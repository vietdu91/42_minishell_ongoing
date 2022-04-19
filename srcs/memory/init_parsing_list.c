/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/19 19:38:04 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_parsing_list(t_pars_list **parser)
{
	*parser = malloc(sizeof(t_pars_list));
	if (!(*parser) || !parser)
		return (0);
	(*parser)->head = NULL;
	(*parser)->tail = NULL;
	(*parser)->length = 0;
	(*parser)->pipe[0] = 0;
	(*parser)->pipe[1] = 0;
	return (1);
}

void	init_parsing_node(t_pars_node *node)
{
	node->content = NULL;
	node->nw_content = NULL;
	node->content_exp = NULL;
	node->content_exp_sans_q = NULL;
	node->type = 0;
	node->index_crypted = 0;
	node->cmds = NULL;
	node->path = NULL;
	node->fds[0] = 0;
	node->fds[1] = 0;
	node->previous = NULL;
	node->next = NULL;
}

t_pars_list	*list_end_parse(t_pars_list *list, char *content)
{
	t_pars_node	*node;

	if (!list || !content)
		return (NULL);
	node = malloc(sizeof(t_pars_node));
	if (!node)
		return (NULL);
	init_parsing_node(node);
	node->content = ft_strdup(content);
	node->next = NULL;
	if (list->tail == NULL)
	{
		node->previous = NULL;
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
	}
	list->length++;
	return (list);
}


t_pars_list	*list_mid_parse(t_pars_list *list, t_pars_node *n, char *content)
{
	t_pars_node	*node;

	if (!list || !n || !content)
		return (NULL);
	node = malloc(sizeof(t_pars_node));
	if (!node)
		return (NULL);
	printf("n = %s\n", n->content);
	init_parsing_node(node);
	node->content = ft_strdup(content);
	printf("hello content %s\n", node->content);
	if (n->next == NULL)
	{
		node->next = NULL;
		list->tail = node;
	}
	else
	{
		printf("doing the job n->content = %s\n", n->content);
		node->next = n->next;
		n->next->previous = node;
		// list->tail = node;
	}
	node->previous = n;
	n->next = node;
	list->length++;
	return (list);
}

void	display_parsing(t_pars_list *parser)
{
	t_pars_node	*i;

	i = parser->head;
	while (i)
	{
		if (i->type == CMD)
		{
			printf("Path = %s\n", i->path);
			int j = -1;
			while (i->cmds[++j])
				printf("%s\n", i->cmds[j]);
		}
		printf("parsing = %s\n", i->content);
		printf("len->content = %d\n", ft_strlen(i->content));
		printf("content_exp = %s\n", i->content_exp);
		printf("content_exp_sans_quotes = %s\n", i->content_exp_sans_q);
		printf("nw_content = %s\n", i->nw_content);
		printf("type = %u\n\n", i->type);
		i = i->next;
	}
}
