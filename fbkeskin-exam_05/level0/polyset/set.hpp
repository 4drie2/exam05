#pragma once

#include "searchable_bag.hpp"

class	set{
	searchable_bag	&bag;
	public:
		set(searchable_bag &b) : bag(b) {};

		void	insert(int n);
		void	insert(int *a, int n);
		bool	has(int n) const;
		void	print() const;
		void	clear();
		const searchable_bag	&get_bag() const;
};
