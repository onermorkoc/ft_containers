# ifndef NORMAL_ITERATOR_HPP
# define NORMAL_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft{

        template <typename Iterator> 
        class normal_iterator{

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
                normal_iterator(void){
                        this->i = iterator_type();
                }

                // Constructor v1:
                explicit normal_iterator(iterator_type it){
                        this->i = it;
                }

                // Copy
                template <typename Iter> 
                normal_iterator(const normal_iterator<Iter> &copy){
                        this->i = copy.base();
                }

                // ############################ => Metot <= ############################

                const iterator_type base(void) const{
                        return (this->i);
                }

                // ############################ => Operator Overloading <= ############################

                // Copy Assignment
                normal_iterator &operator=(const normal_iterator &copy){

                        if (*this != copy)
                                this->i = copy.base();
                        return (*this);
                }

                reference operator*(void) const{
                        return (*this->i);
                }

                normal_iterator operator+(difference_type n) const{
                        return (normal_iterator(this->i + n));
                }

                normal_iterator &operator++(void){
                        this->i++;
                        return (*this);
                }
                
                normal_iterator operator++(int){
                        normal_iterator<Iterator> temp(*this);
                        this->i++;
                        return (temp);
                }

                normal_iterator &operator+=(difference_type n){
                        this->i += n;
                        return (*this);
                }

                normal_iterator operator-(difference_type n) const{
                        return (normal_iterator(this->i - n));
                }

                normal_iterator &operator--(void){
                        this->i--;
                        return (*this);
                }
                
                normal_iterator operator--(int){
                        normal_iterator<Iterator> temp(*this);
                        this->i--;
                        return (temp);
                }

                normal_iterator &operator-=(difference_type n){
                        this->i -= n;
                        return (*this);
                }

                pointer operator->(void) const {
                        return &(operator*());
                }

                reference operator[](difference_type n) const{
                        return (*(this->i + n));
                }
        };
	
        // ############################ => Operator Overloading <= ############################
        // Not: Çift olmasın nedeni templateler 2 farklı türde olabilir diye belirtiyoruz
        // örnek kullanım olarak: iterator != const_iterator

        template <typename Iterator> 
        bool operator==(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() == rhs.base());
        }

        template <typename IteratorL, typename IteratorR> 
        bool operator==(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() == rhs.base());
        }

        template <typename Iterator> 
        bool operator!=(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() != rhs.base());
        }

        template <typename IteratorL, typename IteratorR> 
        bool operator!=(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() != rhs.base());
        }

        template <typename Iterator> 
        bool operator<(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() < rhs.base());
        }

        template <typename IteratorL, typename IteratorR> 
        bool operator<(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() < rhs.base());
        }

        template <typename Iterator> 
        bool operator<=(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() <= rhs.base());
        }

        template <typename IteratorL, typename IteratorR> 
        bool operator<=(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() <= rhs.base());
        }

        template <typename Iterator> 
        bool operator>(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() > rhs.base());
        }

        template <typename IteratorL, typename IteratorR> 
        bool operator>(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() > rhs.base());
        }

        template <typename Iterator> 
        bool operator>=(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() >= rhs.base());
        }

        template <typename IteratorL, typename IteratorR> 
        bool operator>=(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() >= rhs.base());
        }

        template <typename Iterator> // int x + iterator
        normal_iterator<Iterator> operator+(typename normal_iterator<Iterator>::difference_type n, const normal_iterator<Iterator> &it){
                return (normal_iterator<Iterator>(it.base() + n));
        }

        template <typename Iterator> // iki iterator arası mesafeyi hesaplıyor
        typename normal_iterator<Iterator>::difference_type operator-(const normal_iterator<Iterator> &lhs, const normal_iterator<Iterator> &rhs){
                return (lhs.base() - rhs.base());
        }

        template <typename IteratorL, typename IteratorR>
        typename normal_iterator<IteratorL>::difference_type operator-(const normal_iterator<IteratorL> &lhs, const normal_iterator<IteratorR> &rhs){
                return (lhs.base() - rhs.base());
        }
}

# endif