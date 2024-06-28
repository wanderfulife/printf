/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:18 by jowander          #+#    #+#             */
/*   Updated: 2024/06/28 10:29:40 by jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_hex(va_list *args, bool uppercase)
{
	unsigned int	number;

	number = va_arg(*args, unsigned int);
	return (ft_print_num_as_hex(number, uppercase));
}

int	ft_print_pointer(va_list *args)
{
	void		*pointer;
	int			count;
	uintptr_t	address;

	pointer = va_arg(*args, void *);
	if (!pointer)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	address = (uintptr_t)pointer;
	count = 2 + ft_print_hex_address(address);
	return (count);
}
