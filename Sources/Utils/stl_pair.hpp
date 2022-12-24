# ifndef STL_PAIR_HPP 
# define STL_PAIR_HPP

namespace ft{

        // ################################## => pair <= ##################################
        // Not: icinde 2 farklı veri tipi tutucağımız data diyebiliriz(iki dizi olur bir
        // sayının tam kısmı ondalık kısmı olabilir vb...) 

        template<typename T1, typename T2>
        struct pair{
                
                typedef T1 first_type;
                typedef T2 second_type;

                first_type first;
                second_type second;

                // ###################################### => Constructor <= ######################################

                // Default
                pair(void){
                        this->first = first_type();
                        this->second = second_type();
                }
                
                // Copy
                template<typename U, typename V>
                pair(const pair<U, V> &copy){
                        *this = copy;
                }

                // Constructor v1                
                pair (const first_type &a, const second_type &b){
                        this->first = a;
                        this->second = b;
                }

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
                return (lhs != rhs);
        }

        template <typename T1, typename T2>
        bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return ((lhs.first < rhs.first) || ((lhs.first < rhs.first) && (lhs.second < rhs.second)));
        }

        template <typename T1, typename T2>
        bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return (lhs < rhs);
        }

        template <typename T1, typename T2>
        bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return (lhs > rhs);
        }

        template <typename T1, typename T2>
        bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
                return (lhs > rhs);
        }

        // ################################## => make_pair <= ##################################

        template <typename T1, typename T2>
        pair<T1, T2> make_pair (T1 x, T2 y){
                return (pair<T1, T2>(x, y) );
        }
}

# endif