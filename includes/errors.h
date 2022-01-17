/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:12:01 by emtran            #+#    #+#             */
/*   Updated: 2022/01/17 15:37:22 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_NOENV "No such environment\n"
# define ERR_MALLOC "Failed to allocate memory.\n"
# define ERR_UNCLOSED "bash: syntax error: unclosed quotes `"

/*		ERRORS.C		*/

void	fork_of_errors(int a, t_args *args);
void	print_error(char *msg_error, t_args *args);
void	print_syntax_error(char *msg_error, char sign, int a);

#endif