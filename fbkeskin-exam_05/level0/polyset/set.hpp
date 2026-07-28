/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:42:38 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/28 18:03:55 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"

// "wrapping" (sarama) işlemi, genellikle bir sınıfın (class) başka bir sınıfı,
// fonksiyonu ya da veriyi içine alarak bir arayüz (interface) sağlaması anlamına gelir.
// REFERANSLA SARMA
class set
{
	private:
		searchable_bag& bag;
		set();                          // interdits : une reference ne peut
		set(const set&);                // etre ni construite par defaut,
		set& operator=(const set&);     // ni copiee, ni reassignee.
	public:
		set(searchable_bag& b);
		~set();

		void insert(int);
		void insert(int*, int);
		bool has(int) const;
		void print() const;
		void clear();
		const searchable_bag& get_bag() const;
};
