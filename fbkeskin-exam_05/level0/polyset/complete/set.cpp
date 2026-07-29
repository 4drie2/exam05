#include "set.hpp"

void	set::insert(int n){
	if (!has(n))
		bag->insert(n);
}

void	set::insert(int *a, int n){
	for (int i = 0; i < n; ++i)
		insert(a[i]);
}

bool	set::has(int n) const { return (bag->has(n)); }
void	set::print() const { bag->print(); }
void	set::clear() { bag->clear(); }
const searchable_bag	&set::get_bag() const { return (*bag); }
