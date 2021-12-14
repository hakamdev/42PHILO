/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:30:12 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 19:37:17 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_errors.h"

int main() {

	printf("VALID = %d -- |%s|\n", m_is_number("0"), "0");
	printf("VALID = %d -- |%s|\n", m_is_number("123"), "123");
	printf("VALID = %d -- |%s|\n", m_is_number("0012"), "0012");
	printf("VALID = %d -- |%s|\n", m_is_number("12 12"), "12 12");
	printf("VALID = %d -- |%s|\n", m_is_number("123a"), "123a");
	printf("VALID = %d -- |%s|\n", m_is_number("123 cv"), "123 cv");
	printf("VALID = %d -- |%s|\n", m_is_number("12 123 b"), "12 123 b");
	printf("VALID = %d -- |%s|\n", m_is_number("sfsfd"), "sfsfd");
}