/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:00:57 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/10 18:00:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	main(void)
{
	kill(0, SIGSEGV);
	return (0);
}
