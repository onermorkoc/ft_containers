# ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft {
        
        template<typename V>
        class vector {
                
                private:
                        V *array;

                public:

                        // Arrayın elemanlarına erişmeye yönelik
                        void assign(void){}
                        void get_allocator(void){}
                        void at(void){}
                        void front(void){}
                        void back(void){}
                        void data(void){}

                        // iterator işlemlerine yönelik
                        void begin(void){}
                        void end(void){}
                        void rbegin(void){}
                        void rend(void){}

                        // Kapasite işlemlerine yönelik
                        void empty(void){}
                        void size(void){}
                        void max_size(void){}
                        void reserve(void){}
                        void capacity(void){}

                        // Arrayın elemanlarına ekle/çıkar/sil işlemlerine yönelik
                        void clear(void){}
                        void insert(void){}
                        void erase(void){}
                        void push_back(void){}
                        void pop_back(void){}
                        void resize(void){}
                        void swap(void){}

        };

        template<typename V>
        bool operator==(vector<V> &objectLeft, vector<V> &objectRight){}

        template<typename V>
        bool operator!=(vector<V> &objectLeft, vector<V> &objectRight){}

        template<typename V>
        bool operator<(vector<V> &objectLeft, vector<V> &objectRight){}

        template<typename V>
        bool operator<=(vector<V> &objectLeft, vector<V> &objectRight){}

        template<typename V>
        bool operator>(vector<V> &objectLeft, vector<V> &objectRight){}

        template<typename V>
        bool operator>=(vector<V> &objectLeft, vector<V> &objectRight){}
}

# endif