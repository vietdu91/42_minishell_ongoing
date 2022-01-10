/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:10 by emtran            #+#    #+#             */
/*   Updated: 2022/01/10 19:13:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "./bultin.h"

typedef struct s_exit_status
{
	int	interrogation;
}	t_exit_status;

typedef struct s_builtin
{
	char		**tab_builtin;
	t_cd		*cd;
	t_env		*env;
	t_export	*export;
}	t_builtin;

/* pointeurs sur les structs de type fichier builtin etc */
typedef struct s_args
{
	t_exit_status	*exit_status;
	t_builtin		*builtin;
}	t_args;
/* checker comment faire differents types de struct*/

/* maillons de la liste chainee */
typedef struct s_list
{
	t_args	*head;
	t_args	*tail;
}	t_list;

#endif