/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:12:59 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/28 16:13:27 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag& b) : bag(b) {}

set::~set() {}

void set::insert(int value)
{
	if (!has(value))
		bag.insert(value);
}

void set::insert(int *values, int size)
{
	for (int i = 0; i < size; i++)
		insert(values[i]);
}

bool set::has(int value) const { return (bag.has(value)); }

void set::print() const { bag.print(); }

void set::clear() { bag.clear(); }

const searchable_bag& set::get_bag() const { return (bag); }
