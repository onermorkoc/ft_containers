# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft{

        template <typename Iterator> 
        class reverse_iterator{

                public:

                // ############################ => Typedef <= ############################

                typedef                 Iterator                                                iterator_type;
                typedef typename        ft::iterator_traits<Iterator>::iterator_category        iterator_category;
                typedef typename        ft::iterator_traits<Iterator>::value_type               value_type;
                typedef typename        ft::iterator_traits<Iterator>::difference_type          difference_type;
                typedef typename        ft::iterator_traits<Iterator>::pointer                  pointer;
                typedef typename        ft::iterator_traits<Iterator>::reference                reference;

                private:
                        iterator_type   i;

                public:

                // ############################ => Constructor <= ############################

                // Default
                reverse_iterator(void){
                        this->i = iterator_type();
                }

                // Constructor v1:
                explicit reverse_iterator(iterator_type it){
                        this->i = it;
                }

                // Copy
                template <class Iter> 
                reverse_iterator(const reverse_iterator<Iter> &rev_it){
                        this->i = rev_it.i;
                }

                // ############################ => Metot <= ############################

                iterator_type base(void) const{
                        return (this->i);
                }

                // ############################ => Operator Overloading <= ############################

                reference operator*(void) const{
                        return (*this->i);
                }

                reverse_iterator operator+(difference_type n) const{
                        return (reverse_iterator(this->i - n));
                }

                reverse_iterator &operator++(void){
                        this->i--;
                        return (*this);
                }
                
                reverse_iterator operator++(int){
                        reverse_iterator<Iterator> temp(*this);
                        this->i--;
                        return (temp);
                }

                reverse_iterator &operator+=(difference_type n){
                        this->i -= n;
                        return (*this);
                }

                reverse_iterator operator-(difference_type n) const{
                        return (reverse_iterator(this->i + n));
                }

                reverse_iterator &operator--(void){
                        this->i++;
                        return (*this);
                }
                
                reverse_iterator operator--(int){
                        reverse_iterator<Iterator> temp(*this);
                        this->i++;
                        return (temp);
                }

                reverse_iterator &operator-=(difference_type n){
                        this->i += n;
                        return (*this);
                }

                pointer operator->(void) const {
                        return &(operator*());
                }

                reference operator[](difference_type n) const{
                        return (this->i[n]);
                }
        };
	
        // ############################ => Operator Overloading <= ############################

        template <typename Iterator> 
        bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (lhs.base() == rhs.base());
        }

        template <typename Iterator> 
        bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (lhs.base() != rhs.base());
        }

        template <typename Iterator> 
        bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (lhs.base() > rhs.base());
        }

        template <typename Iterator> 
        bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (lhs.base() >= rhs.base());
        }

        template <typename Iterator> 
        bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (lhs.base() < rhs.base());
        }

        template <typename Iterator> 
        bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (lhs.base() <= rhs.base());
        }

        template <typename Iterator> // int x + iterator
        reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it){
                return (reverse_iterator<Iterator>(rev_it.base() - n));
        }

        template <typename Iterator> // iki iterator arası mesafeyi hesaplıyor
        typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs){
                return (typename reverse_iterator<Iterator>::difference_type(lhs.base() - rhs.base()));
        }
}

# endif