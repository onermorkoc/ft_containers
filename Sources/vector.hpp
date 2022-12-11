# ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft{

        template < class T, class Alloc = std :: allocator<T> > 
        class vector{

                private:

                public:

                        // ############################### => Constructor <= ###############################

                        // Default
                        explicit vector(const allocator_type &alloc = allocator_type()){}

                        // Constructor v1:
                        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){}

                        // Constructor v2:
                        template <class InputIterator> 
                        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()){}

                        // Copy
                        vector(const vector &x){}

                        // Destructor
                        ~vector(void){}

                        // ############################### => Metotlar <= ###############################

                        // ***************** ===> iterator işlemlerine yönelik <=== *****************

                        // Dizinin ilk elemanın iteratorunu döndürür.
                        iterator begin(void){}
                        
                        const_iterator begin(void) const{}

                        // Dizinin son elemanın iteratorunu döndürür.
                        iterator end(void){}
                        
                        const_iterator end(void) const{}

                        reverse_iterator rbegin(void){}
                        
                        const_reverse_iterator rbegin(void) const{}

                        reverse_iterator rend(void){}
                        
                        const_reverse_iterator rend(void) const{}

                        // ***************** ===> Kapasite işlemlerine yönelik <=== *****************

                        size_type size(void) const{}

                        size_type max_size(void) const{}

                        void resize(size_type n, value_type val = value_type()){}

                        size_type capacity(void) const{}

                        bool empty(void) const{}

                        void reserve(size_type n){}

                        // ***************** ===> Dizinin elemanlarına erişmeye yönelik <=== *****************

                        // Dizinin gelen indexteki elemanın değerini döndürür.
                        reference at(size_type n){}
                        
                        const_reference at(size_type n) const{}

                        // Dizinin ilk elemanın değerini döndürür.
                        reference front(void){}
                        
                        const_reference front(void) const{}

                        // Dizinin son elemanın değerini döndürür.
                        reference back(void){}
                        
                        const_reference back(void) const{}

                        // Vector'un türünden düz dizi yapıp döndürür.
                        value_type *data(void) noexcept{}
                        
                        const value_type *data(void) const noexcept{}

                        // ***************** ===> Dizinin elemanlarına modifiye yönelik <=== *****************

                        template <class InputIterator> 
                        void assign(InputIterator first, InputIterator last){}

                        void assign(size_type n, const value_type &val){}

                        // Dizinin en sonuna eleman ekler yeterli alan yoksa diziyi bir büyütür
                        void push_back(const value_type &val){}

                        // Dizinin en sonuna ki elemanı çıkartır ve diziyi bir küçültür
                        void pop_back(void){}

                        iterator insert(iterator position, const value_type &val){}

                        void insert(iterator position, size_type n, const value_type &val){}

                        template <class InputIterator>
                        void insert(iterator position, InputIterator first, InputIterator last){}

                        iterator erase(iterator position){}
                        
                        iterator erase(iterator first, iterator last){}

                        // std :: swap kullancaz
                        void swap(vector &x){}

                        void clear(void){}

                        allocator_type get_allocator(void) const{}

                        // ############################### => Operator Overloading <= ###############################

                        // Copy Assignment Operator
                        vector &operator=(const vector &x){}

                        reference operator[](size_type n){}
                        
                        const_reference operator[](size_type n) const{}
        };

        // ############################### => Mantıksal Operator Overloading <= ###############################
        
        template <class T, class Alloc>
        bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){}
        
        template <class T, class Alloc>
        bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){}
        
        template <class T, class Alloc>
        bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){}
        
        template <class T, class Alloc>
        bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){}
        
        template <class T, class Alloc>
        bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){}
        
        template <class T, class Alloc>
        bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){}
}

# endif