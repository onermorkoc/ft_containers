# ifndef STL_PAIR_HPP 
# define STL_PAIR_HPP

namespace ft{

        // ################################## => pair <= ##################################
        // Not: içinde 2 farklı veri tipi tutucağımız data diyebiliriz(iki dizi olur bir
        // sayının tam kısmı ondalık kısmı olabilir vb...). Pair'i map kısmında kullancaz
        // key-value tutmak için. 

        template<typename T1, typename T2>
        struct pair{
                
                typedef T1 first_type;
                typedef T2 second_type;

                first_type first;
                second_type second;

                // ###################################### => Constructor <= ######################################

                // Default
                pair(void): first(first_type()), second(second_type()) {}

                // Constructor v1                
                pair (const first_type &a, const second_type &b): first(a), second(b) {}

                // Constructor v2
                template<typename U, typename V>
                pair(const pair<U, V> &object): first(object.first), second(object.second) {}

                // Copy
                pair(const pair &copy): first(copy.first), second(copy.second) {}

                // ###################################### => Operator Overloading <= ######################################

                // Copy Assignment
                pair &operator=(const pair &copy){
                        
                        if (*this != copy){
                                this->first = copy.first;
                                this->second = copy.second;
                        }
                        return (*this);
                }
        };

        // ###################################### => Operator Overloading <= ######################################

        template <typename T1, typename T2>
        bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){ 
                return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
        }

        template <typename T1, typename T2>
        bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return (!(lhs == rhs));
        }

        template <typename T1, typename T2>
        bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return ((lhs.first < rhs.first) || ((lhs.first == rhs.first) && (lhs.second < rhs.second)));
        }

        template <typename T1, typename T2>
        bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return ((lhs < rhs) || (lhs == rhs));
        }

        template <typename T1, typename T2>
        bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return (rhs < lhs);
        }

        template <typename T1, typename T2>
        bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return ((rhs < lhs) || (lhs == rhs));
        }

        // ################################## => make_pair <= ##################################

        template <typename T1, typename T2>
        pair<T1, T2> make_pair (T1 x, T2 y){
                return (pair<T1, T2>(x, y) );
        }
}

# endif