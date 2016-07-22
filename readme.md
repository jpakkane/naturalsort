# Natural order

A C++ header only implementation of natural order using only forward iterators.

Natural order means sorting strings so that embedded numbers are treated as numbers. This means that if you use natural order for sorting you get this:

    1 one
    2 two
    3 three
    10 ten

Instead of the default sort behaviour:

    1 one
    10 ten
    2 two
    3 three

