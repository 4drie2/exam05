#include "searchable_tree_bag.hpp"

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &o) {
    if (this != &o)
        array_bag::operator=(o);
    return *this;
}

bool searchable_tree_bag::has(int n) const {
    node *t = tree;
    while (t){
        if (n == t->value)
            return true;
        if (n < t->value)
            t = t->l;
        else
            t = t->r;
    }
    return false;
}