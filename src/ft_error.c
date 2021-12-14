/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:57 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 19:32:33 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_errors.h"

bool	m_is_number(char *arg)
{
	int 	i;

	if (!arg)
		return (false);
	i = 0;
	while (arg[i] == ' ')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	while (arg[i] == ' ')
		i++;
	if (arg[i] != '\0')
		return (false);
	return (true);
}

int		m_errno(int errnoval)
{
	static int errno;

	if (errnoval != EVOID)
		errno = errnoval;
	return (errno);
}

bool	m_is_error(void)
{
	return (m_errno(EVOID) != ENOERROR);
}

int		m_put_error()
{
	// TODO: change
	if (m_errno(EVOID) == ENOERROR)
		return (0);
	if (m_errno(EVOID) == ENOMEM)
		dprintf(2, "Error\n%s", MSG_ENOMEM);
	else if (m_errno(EVOID) == EMTXINIT)
		dprintf(2, "Error\n%s", MSG_EMTXINIT);
	else if (m_errno(EVOID) == EMTXLOCK)
		dprintf(2, "Error\n%s", MSG_EMTXLOCK);
	else if (m_errno(EVOID) == EMTXUNLCK)
		dprintf(2, "Error\n%s", MSG_EMTXUNLCK);
	else if (m_errno(EVOID) == EMTXDEST)
		dprintf(2, "Error\n%s", MSG_EMTXDEST);
	else if (m_errno(EVOID) == ETRDINIT)
		dprintf(2, "Error\n%s", MSG_ETRDINIT);
	else if (m_errno(EVOID) == EARGS)
		dprintf(2, "Error\n%s", MSG_EARGS);
	return (1);
}
