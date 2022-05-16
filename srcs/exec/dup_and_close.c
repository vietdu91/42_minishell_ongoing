/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:09:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/16 22:57:29 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	close_maestro(int datas[5], t_pars_list *l)
{
	t_pars_node	*node;

	if (datas[2] > 0)
		close(datas[2]);
	if (datas[0] < datas[1])
		close(l->pipe[1]);
	else
		close(l->pipe[0]);
	node = l->head;
	while (node)
	{		
		if (node->fds[0] > 0)
			close(node->fds[0]);
		if (node->fds[1] > 0)
			close(node->fds[1]);
	}
	return (0);
}

int	datas_zero(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (datas[1] > 1)
	{
		if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		else if (cpy->fds[1] < 1 && dup2(l->pipe[1], STDOUT_FILENO) < 0)
		{
			// ft_putstr("erreur 2\n", 2);
			close_maestro(datas, l);
			return (-1);
		}
		ft_close(l->pipe[0], "datas zero \n");
		if (datas[2] > 0)
			ft_close(datas[2], "datas zero \n"); // empeche decrire dans l'entree standa, "datas zero \n"rd
		// ft_close(l->pipe[1]); // bad file descripto, "datas zero \n"r 
		ft_close(datas[3], "datas zero \n");
		ft_close(datas[4], "datas zero \n");
	}
	else
	{
		if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		else if (l->pipe[1] > 0 && dup2(l->pipe[1], STDOUT_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		if (datas[1] > 1)
		{
			if (datas[1])
			{
				close(l->pipe[0]);
				if (datas[2] > 0)
					close(datas[2]);
				close(l->pipe[1]);
			}
		}
		close(datas[3]);
		close(datas[4]);
	}
	return (0);
}

int	datas_end(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	else if (cpy->fds[0] < 1 && dup2(datas[2], STDIN_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	if (datas[2] > 0)
		ft_close(datas[2], "datas end close \n");
	if (cpy->fds[1] > 0)
		ft_close(cpy->fds[1], "datas end close \n");
	ft_close(l->pipe[1], "datas end close \n");
	ft_close(l->pipe[0], "datas end close \n");
	ft_close(datas[3], "datas end close \n");
	ft_close(datas[4], "datas end close \n");
	return (0);
}

int	datas_middle(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	else
	{
		if (dup2(datas[2], STDIN_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		ft_close(datas[2], "middle close \n");
		ft_close(l->pipe[0], "middle close \n");
	}
	if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
		close(l->pipe[0]);
		close(l->pipe[1]);
		close(datas[2]);
	}
	else
	{
		if (dup2(l->pipe[1], STDOUT_FILENO) < 0)
		{
			close_maestro(datas, l);
			return (-1);
		}
		close(l->pipe[1]);
		close(datas[3]);
		close(datas[4]);
	}
	return (0);
}

int	dup_maestro(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (datas[0] == 1)
		return (datas_zero(datas, l, cpy));
	else if (datas[0] == datas[1] && datas[1] > 1)
		datas_end(datas, l, cpy);
	else
		datas_middle(datas, l, cpy);
	return (0);
}































	// if (cpy->fds[0] > 0)
	// {
	// 	if (datas[0] == 1)
	// 	{
	// 		// close(l->pipe[0]);
	// 		// close(l->pipe[1]);
	// 	}
	// 	if (dup2(cpy->fds[0], STDIN_FILENO) < 0)
	// 	{
	// 		close_maestro(datas, l);
	// 		return (-1);
	// 	}
	// 	close(cpy->fds[0]);
	// 	close(datas[3]);
	// }
	// if (cpy->fds[1] > 0)
	// {
	// 	printf("FILHO DE PUTa\n");
	// 	if (datas[0] == 1)
	// 	{
	// 		close(l->pipe[0]);
	// 		close(l->pipe[1]);
	// 		close(datas[4]);
	// 	}
	// 	// close(l->pipe[1]);
	// 	if (dup2(cpy->fds[1], STDOUT_FILENO) < 0)
	// 	{
	// 		close_maestro(datas, l);
	// 		return (-1);
	// 	}
	// 	close(cpy->fds[1]);
	// }