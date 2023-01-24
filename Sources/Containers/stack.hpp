# ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

        template< typename T, typename Container = ft::vector<T> >
        class stack{

                public:

                        // ######################### => Typedef <= #########################

                        typedef         T               value_type;
                        typedef         Container       container_type;
                        typedef         size_t          size_type;

                protected:
                        container_type c;

                public:
                        // ######################### => Constructor <= #########################

                        // Default
                        explicit stack(const container_type &ctnr = container_type()): c(ctnr) {}

                        // Destructor
                        ~stack(void) {}

                        // ######################### => Metotlar <= #########################

                        bool empty(void) const {
                                return (c.empty());
                        }

                        size_type size(void) const {
                                return (c.size());
                        }

                        // Diziye en son giren elemanı döndürür.
                        value_type &top(void){
                                return (c.back());
                        }
                        
                        const value_type &top(void) const{
                                return (c.back());
                        }

                        // Dizinin en sonuna eleman ekler
                        void push(const value_type &val){
                                c.push_back(val);
                        }

                        // Diziye giren en son elemanı çıkartır
                        void pop(){
                                c.pop_back();
                        }

                        // ######################### => Operator Overloading <= #########################

                        // Copy assignment
                        stack &operator=(const stack &copy){
                                if (*this != copy)
                                        this->c = copy.c;
                                return (*this);
                        }

                        // ######################### => Friend Fonksiyonlar <= #########################

                        template<typename T2, typename Container2>
                        friend bool operator==(const ft::stack<T2, Container2> &lhs, const ft::stack<T2, Container2> &rhs);

                        template<typename T2, typename Container2>
                        friend bool operator<(const ft::stack<T2, Container2> &lhs, const ft::stack<T2, Container2> &rhs);
                
                };

        // ######################### => Operator Overloading <= #########################

        template<typename T, typename Container>
        bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs){
                return (lhs.c == rhs.c);
        }

        template<typename T, typename Container>
        bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs){
                return (!(lhs == rhs));
        }

        template<typename T, typename Container>
        bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs){
                return (lhs.c < rhs.c);
        }

        template<typename T, typename Container>
        bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs){
                return ((lhs < rhs) || (lhs == rhs));
        }

        template<typename T, typename Container>
        bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs){
                return (rhs < lhs);
        }

        template<typename T, typename Container>
        bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs){
                return ((rhs < lhs) || (lhs == rhs));
        }
}

# endif