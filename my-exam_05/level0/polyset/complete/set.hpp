#pragma once

#include "searchable_bag.hpp"

class set {
    seachable_bag *bag;
    public:
        set(seachable_bag &b) : bag(b) {};
}