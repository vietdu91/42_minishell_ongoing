/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_to_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:02:36 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 13:17:29 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_pars_node *node)
{
	if (!node || !node->content_exp_sans_q)
		return (-1);
	if (!ft_strcmp(node->content_exp_sans_q, "env"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "pwd"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "unset"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "scare_me"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, \
	"patience_is_a_virtue"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "cd"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "export"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "exit"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "echo"))
		return (0);
	return (1);
}

int	which_node(t_pars_list *l, int n)
{
	t_pars_node	*node;
	int			i;

	i = 0;
	node = l->head;
	while (node)
	{
		if (node->type == CMD)
		{
			i++;
			if (i == n)
			{	
				return (is_builtin(node));
			}
		}
		node = node->next;
	}
	return (0);
}

int	return_or_exit(int n, t_args *args, int datas[5])
{
	// close(0);
	// close(1);
	// ft_putstr("salut\n", 2);
	if (datas[2] > 0)
		close(datas[2]);
	if (datas[1] > 1)
	{
		close(0);
		close(1);
		close(datas[3]);
	}
	close(datas[4]);
	if (args->parser->pipe[0])
		close(args->parser->pipe[0]);
	if ( args->parser->pipe[1])
		close(args->parser->pipe[1]);
	reset_in_out(datas, args->parser);
	if (n == 1)
	{
		// ft_putstr("rien a faire ici \n", 2);
		return (0);
	}
	else
	{
		//ft_putstr("je suis le traitre\n", 1);
		free_all(args);
		exit(0);
	}
	ft_putstr("sortie\n", 2);
	return (0);
}

int	exec_builtin_3(t_args *args, t_pars_node *node, int n, int datas[5])
{
	if (!ft_strcmp(node->content_exp_sans_q, "scare_me"))
	{
		print_scare_me();
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, \
	"patience_is_a_virtue"))
	{
		print_patience(args);
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "echo"))
	{
		echo_main(args, node);
		return (return_or_exit(n, args, datas));
	}
	return (-1);
}

int	exec_builtin_2(t_args *args, t_pars_node *node, int n, int datas[5])
{
	if (!ft_strcmp(node->content_exp_sans_q, "env"))
	{
		display_env(node, args->env);
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "pwd"))
	{
		pwd_main(node, args);
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "unset"))
	{
		unset_main(args, node);
		return (return_or_exit(n, args, datas));
	}
	return (exec_builtin_3(args, node, n, datas));
}

int	exec_builtin_1(t_args *args, t_pars_node *node, int n, int datas[5])
{
	if (node)
	{
		if (!ft_strcmp(node->content_exp_sans_q, "cd"))
		{
			cd_main(args, args->env, node);
			return (return_or_exit(n, args, datas));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "export"))
		{
			export_main(args, node, args->export);
			return (return_or_exit(n, args, datas));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "exit"))
		{
			exit_main(args, node);
			return (return_or_exit(n, args, datas));
		}
	}
	return (exec_builtin_2(args, node, n, datas));
}
