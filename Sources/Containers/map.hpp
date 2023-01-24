# ifndef MAP_HPP
# define MAP_HPP

# include "../Utils/stl_pair.hpp"
# include "../Utils/stl_algobase.hpp"
# include "../Iterator/reverse_iterator.hpp"
# include "../Iterator/bst_const_iterator.hpp"

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
                typedef         typename ft::bst_iterator<value_type>                                   iterator;
                typedef         typename ft::bst_const_iterator<value_type>                             const_iterator;
                typedef         typename ft::reverse_iterator<iterator>                                 reverse_iterator;
                typedef         typename ft::reverse_iterator<const_iterator>                           const_reverse_iterator;
                typedef         binary_search_tree<key_type, mapped_type, key_compare, allocator_type>  tree_type;

                private:
                        allocator_type  alloc;
                        key_compare     compare;
                        tree_type       tree;
                public:

                // ################################ => Constructor <= ################################

                // Default
                map(void): alloc(allocator_type()), compare(key_compare()), tree(tree_type()){}

                // Constructor v1
                explicit map(const Compare &comp, const Allocator &alloc = Allocator()): alloc(alloc), compare(comp), tree(tree_type()) {}

                // Constructor v2
                template<typename InputIt>
                map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator()): alloc(alloc), compare(comp), tree(tree_type()) {
                        this->insert(first, last);
                }

                // Copy
                map(const map &copy){ *this = copy; }

                // Destructor
                ~map(void) {}

                // ################################ => Member class <= ################################

                class value_compare : public std::binary_function<value_type, value_type, bool> {
                        
                        class map;

                        private:
                                key_compare comp;

                        public:
                                typedef         value_type              first_argument_type;
                                typedef         value_type              second_argument_type;
                                typedef         bool                    result_type;

                                value_compare(const key_compare &c): comp(c){}

                                bool operator()(const value_type &x, const value_type &y) const{
                                        return comp(x.first, y.first);
                                }
                };

                // ################################ => Metotlar <= ################################
                // ********************* => Elemanlara erişmeye yönelik <= *********************

                allocator_type get_allocator(void) const{
                        return (this->alloc);
                }

                T &at(const Key &key){
                        return (this->tree.keyToValue(key));
                }
	
                const T &at(const Key &key) const{
                        return (this->tree.keyToValue(key));
                }

                // ********************* => İterator işlemlerine yönelik <= *********************

                iterator begin(void){
                        return (iterator(this->tree.minNode()));
                }
                
                const_iterator begin(void) const{
                        return (const_iterator(this->tree.minNode()));
                }

                reverse_iterator rbegin(){
                        return (reverse_iterator(this->end()));
                }

                const_reverse_iterator rbegin() const{
                        return (const_reverse_iterator(this->end()));
                }

                iterator end(void){
                        return (iterator(this->tree.maxNode()));
                }

                const_iterator end(void) const{
                        return (const_iterator(this->tree.maxNode()));
                }

                reverse_iterator rend(void){
                        return (reverse_iterator(this->begin()));
                }

                const_reverse_iterator rend(void) const{
                        return (const_reverse_iterator(this->begin()));
                }

                // ********************* => Kapasite işlemlerine yönelik <= *********************

                bool empty(void) const{
                        if (this->size() == 0)
                                return (true);
                        return (false);
                }

                size_type size(void) const{
                        const_iterator first = begin();
                        size_type i = 0;
		        for (const_iterator first = begin(); first != end(); first++)
                                i++;
		        return (i);
                }

                size_type max_size(void) const{
                        return (this->tree.maxSize());
                }

                // ********************* => Dizinin elemanlarını değiştirmeye yönelik <= *********************

                void clear(void){
                        this->tree.clearTree();
                }

                ft::pair<iterator, bool> insert(const value_type &value){
                        if (this->count(value.first))
                                return (ft::make_pair(iterator(this->tree.addOrFind(value)), false));
                        return (ft::make_pair(iterator(this->tree.add(value)), true));
                }

                iterator insert(iterator position, const value_type &value){
                        (void)position;
                        return (iterator(this->tree.addOrFind(value)));
                }
	
                template <class InputIterator>
                void insert(InputIterator first, InputIterator last){
                        while(first != last)
                                this->insert(*first++);
                }
			
                void erase(iterator position){
                        this->erase((*position).first);
                }

                size_type erase(const key_type &key){
                        return (this->tree.deleteNode(key));
                }
                
                void erase(iterator first, iterator last){

                        if (first == this->begin() && last == this->end())
                                this->clear();
                        else{
                                while (first != last){
                                        key_type key_first = first->first;
                                        key_type key_last = last->first;
                                        this->erase(first);
                                        first = this->lower_bound(key_first);
                                        last = this->lower_bound(key_last);
                                }
                        }
                }

                void swap(map &other){
                        this->tree.swap(other.tree);
                        std :: swap(this->alloc, other.alloc);
                        std :: swap(this->compare, other.compare);
                }

                // ********************* => Dizinin elemanlarını bulmaya yönelik <= *********************

                size_type count(const Key& key) const{
                        return (this->tree.checkKey(key));
                }

                iterator find(const Key &key){
                        return (iterator(this->tree.findOrEnd(key)));
                }

                const_iterator find(const Key &key) const{
                        return (const_iterator(this->tree.findOrEnd(key)));
                }

                ft::pair<iterator, iterator>
                equal_range(const Key &key){
                        return (ft :: make_pair(this->lower_bound(key), this->upper_bound(key)));
                }

                ft::pair<const_iterator, const_iterator>
                equal_range(const Key &key) const{
                        return (ft :: make_pair(this->lower_bound(key), this->upper_bound(key)));
                }

                iterator lower_bound(const Key &key){
                        return (iterator(this->tree.findLowerOrEnd(key)));
                }
                
                const_iterator lower_bound(const Key &key) const{
                        return (const_iterator(this->tree.findLowerOrEnd(key)));
                }

                iterator upper_bound(const Key &key){
                        return (iterator(this->tree.findUpperOrEnd(key)));
                }
                
                const_iterator upper_bound(const Key &key) const{
                        return (const_iterator(this->tree.findUpperOrEnd(key)));
                }

                // ********************* => Key keyword'e yönelik <= *********************

                key_compare key_comp(void) const{
                        return (this->compare);
                }

                value_compare value_comp(void) const{
                        return (value_compare(this->compare));
                }

                // ################################ => Operator Overloading <= ################################

                // Copy assignment
                map &operator=(const map &copy){

                        if (*this != copy){
                                this->alloc = copy.alloc;
                                this->compare = copy.compare;
                                this->tree.setRoot(copy.tree.getRoot());
                        }
                        return (*this);
                }

                T &operator[](const Key &key){
                        return (this->tree.addOrFind(value_type(key, T()))->data.second);
                }
        };

        // ################################ => Non-member functions <= ################################

        template<typename Key, typename T, typename Compare, typename Alloc>
        void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs){
                lhs.swap(rhs);
        }

        // ################################ => Operator Overloading <= ################################

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){
                return ((lhs.size() == rhs.size()) && (ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
        }

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){
                return (!(lhs == rhs));
        }

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){
                return ((lhs < rhs) || (lhs == rhs));
        }

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){
                return (rhs < lhs);
        }

        template<typename Key, typename T, typename Compare, typename Alloc > 
        bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs){
                return ((rhs < lhs) || (lhs == rhs));
        }
}

# endif