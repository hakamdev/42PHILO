/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:30:12 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 21:42:10 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

int main(int c, char **v) {

	m_errno(ENOERROR);
	
	t_params *p = init_params(c, v);
	if (m_is_error()) {
		return m_put_error();
	}
	dprintf(2, "RAPAM:\nn_philos\t\t%zu\nt_die\t\t%zu\nt_eat\t\t%zu\nt_slp\t\t%zu\nn_eat\t\t%zu\n", p->n_philos, p->t_die, p->t_eat, p->t_sleep, p->n_eat);

	// printf("VALID = %d -- |%s|\n", m_is_number("+0"), "+0");
	// printf("VALID = %d -- |%s|\n", m_is_number("+123"), "+123");
	// printf("VALID = %d -- |%s|\n", m_is_number("+ 0012"), "+ 0012");
	// printf("VALID = %d -- |%s|\n", m_is_number("12 12"), "12 12");
	// printf("VALID = %d -- |%s|\n", m_is_number("123a"), "123a");
	// printf("VALID = %d -- |%s|\n", m_is_number("123 cv"), "123 cv");
	// printf("VALID = %d -- |%s|\n", m_is_number("12 123 b"), "12 123 b");
	// printf("VALID = %d -- |%s|\n", m_is_number("sfsfd"), "sfsfd");
	// printf("VALID = %d -- |%s|\n", m_is_number("   +   23 "), "   +   23 ");
	// printf("VALID = %d -- |%s|\n", m_is_number("   +   "), "   +   ");
	// printf("VALID = %d -- |%s|\n", m_is_number("   +"), "   +");
	// printf("VALID = %d -- |%s|\n", m_is_number("   +12   "), "   +12  ");
}