/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/31 12:35:16 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_new_content_in_env(t_env *node, char *content, t_args *args)
{
	node->line = ft_strdup(content);
	if (!node->line)
		intersection_of_errors(2, args);
	node->variable = set_variable_env(node->line);
	if (!node->variable)
		intersection_of_errors(2, args);
	node->content = set_content_env(node->line);
	if (!node->content)
		intersection_of_errors(2, args);
	node->var_id = set_id_env(node->variable);
}

void	display_env(t_env_list *env)
{
	t_env	*current;

	if (!env)
		return ;
	current = NULL;
	current = env->head;
	while (current)
	{
		if (ft_strcmp(current->content, "\0"))
			printf("%s\n", current->line);
		current = current->next;
	}
}

void	get_env(t_args *args, char **envp)
{
	int	i;

	i = 0;
	args->export = init_env_list(args->export, args);
	args->env = init_env_list(args->env, args);
	while (envp[i])
	{
		add_var_to_env(args->env, envp[i], args);
		i++;
	}
	g_exit_status = 0;
}
