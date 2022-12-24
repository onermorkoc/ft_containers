# ifndef MAP_HPP
# define MAP_HPP

# include "../Utils/stl_pair.hpp"
# include "../Iterator/normal_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"
# include <iostream>

// normal array kullanmak yasak.

namespace ft {
        
        template< typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
        class map{

                public:

                // ################################ => Typedef <= ################################

                typedef         Key                                                                     key_type;
                typedef         T                                                                       mapped_type;
                typedef         ft::pair<const Key, T>                                                  value_type;
                typedef         Compare                                                                 key_compare;
                typedef         Allocator                                                               allocator_type;
                typedef         typename allocator_type::size_type                                      size_type;
                typedef         typename allocator_type::difference_type                                difference_type;
                typedef         value_type&                                                             reference;
                typedef         const value_type&                                                       const_reference;
                typedef         typename allocator_type::pointer                                        pointer;
                typedef         typename allocator_type::const_pointer                                  const_pointer;
                typedef         typename ft::normal_iterator<T>::value_type                             iterator;       // Yanlış olabilir
                typedef         typename ft::normal_iterator<T>::const_value_type                       const_iterator; // Yanlış olabilir
                typedef         typename ft::reverse_iterator<iterator>::value_type                     reverse_iterator;
                typedef         typename ft::normal_iterator<const_iterator>::const_value_type          const_reverse_iterator;

                private:

                public:

                // ################################ => Constructor <= ################################

                // Default
                map(void){}

                // Constructor v1
                explicit map(const Compare &comp, const Allocator &alloc = Allocator()){}

                // Constructor v2
                template<typename InputIt>
                map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator()){}

                // Destructor
                ~map(void){}

                // ################################ => Member class <= ################################

                class value_compare : public std::binary_function<value_type, value_type, bool> {
                        
                        friend class map;

                        private:
                                key_compare comp;

                        public:
                                typedef         value_type              first_argument_type;
                                typedef         value_type              second_argument_type;
                                typedef         bool                    result_type;

                                value_compare(const key_compare& c): comp(c){}

                                bool operator()(const value_type& x, const value_type& y) const {
                                        return comp(x.first, y.first);
                                }
                };

                // ################################ => Metotlar <= ################################
                // ********************* => Elemanlara erişmeye yönelik <= *********************
                allocator_type get_allocator(void) const{}

                T &at(const Key &key){}
	
                const T &at(const Key &key) const{}

                // ********************* => İterator işlemlerine yönelik <= *********************

                iterator begin(void){}
                
                const_iterator begin(void) const{}

                reverse_iterator rbegin(){}

                const_reverse_iterator rbegin() const{}

                iterator end(void){}

                const_iterator end(void) const{}

                reverse_iterator rend(void){}

                const_reverse_iterator rend(void) const{}

                // ********************* => Kapasite işlemlerine yönelik <= *********************

                bool empty(void) const{}

                size_type size() const{}

                size_type max_size() const{}

                // ********************* => Dizinin elemanlarını değiştirmeye yönelik <= *********************

                void clear(void){}

                ft::pair<iterator, bool>
                insert(const value_type &value){}

                iterator insert(iterator pos, const value_type &value){}

                iterator erase(iterator pos){}

                iterator erase(iterator first, iterator last){}

                size_type erase(const Key &key){}

                void swap(map &other){}

                // ********************* => Dizinin elemanlarını bulmaya yönelik <= *********************

                size_type count(const Key& key) const{}

                iterator find(const Key &key){}

                const_iterator find(const Key &key) const{}

                ft::pair<iterator, iterator>
                equal_range(const Key &key){}

                ft::pair<const_iterator, const_iterator>
                equal_range(const Key &key) const{}

                iterator lower_bound(const Key &key){}
                
                const_iterator lower_bound(const Key &key) const{}

                iterator upper_bound(const Key &key){}
                
                const_iterator upper_bound(const Key &key) const{}

                // ********************* => Key keyword'e yönelik <= *********************

                key_compare key_comp(void) const{}

                map::value_compare value_comp(void) const{}


                // ################################ => Operator Overloading <= ################################

                // Copy assignment
                map &operator=(const map &copy){}

                T &operator[](const Key &key){}
        };

        // ################################ => Non-member functions <= ################################

        template<typename Key, typename T, typename Compare, typename Alloc>
        void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs){}


        // ################################ => Operator Overloading <= ################################

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator==(const ft::map<Key, T, Compare,Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){}

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator!=(const ft::map<Key, T, Compare,Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){}

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator<(const ft::map<Key, T, Compare,Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){}

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator<=(const ft::map<Key, T, Compare,Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){}

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator>(const ft::map<Key, T, Compare,Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){}

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator>=(const ft::map<Key, T, Compare,Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){}
}

# endif