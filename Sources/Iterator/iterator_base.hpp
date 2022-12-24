# ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
struct iterator {

        typedef         T               value_type;
        typedef         Distance        difference_type;
        typedef         Pointer         pointer;
        typedef         Reference       reference;
        typedef         Category        iterator_category;
        
};

# endif