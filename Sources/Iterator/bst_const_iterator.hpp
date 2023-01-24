# ifndef BST_CONST_ITERATOR_HPP
# define BST_CONST_ITERATOR_HPP

# include "bst_iterator.hpp"

namespace ft{

    template<typename T>
    class bst_const_iterator{

        public:
                // ############################ => Typedef <= ############################
        
                typedef     T                                   value_type;
                typedef     const T*                            pointer;
                typedef     const T&                            reference;
                typedef     std::ptrdiff_t                      difference_type;
                typedef     std::bidirectional_iterator_tag     iterator_category;
                typedef     BST<T>                              node_type;
                typedef     node_type*                          node_pointer;
                typedef     ft::bst_iterator<T>                 bst_iterator;

        private:
                node_pointer node;

                /*  Arttırma işlemi:
                    1) Sağın varsa sağın en soluna git.
                    2) Sağın yoksa parent git taa ki kendisinden büyük node bulana kadar.(node->parent->left != node bütün olay burada dönüyor)
                */

                void increase(void){
                    if (node->right != NULL){ // (1)
                        node = node->right;
                        while (node->left != NULL)
                            node = node->left;
                    }else{
                        while (node->parent != NULL && node->parent->left != node) // (2)
				            node = node->parent;
				        node = node->parent;
                    }
                }

                /*  Azaltma işlemi:
                    1) Solun varsa solun en sağına git ama end() olmayacak.
                    2) Solun varsa parent git taa ki kendisinden büyük node bulana kadar.
                */

                void decrease(void){
                    if (node->left != NULL){ // (1)
                        node = node->left;
                        while(node->right != NULL)
                            node = node->right;
                    }else{
                        while (node->parent != NULL && node->parent->right != node) // (2)
				            node = node->parent;
				        node = node->parent;
                    }
                }
        
        public:
                // ############################ => Constructor <= ############################

                // Default
                bst_const_iterator(void):	node(NULL){}

                // Constructor v1:
	            bst_const_iterator(node_pointer node): node(node){}

                // Copy
	            bst_const_iterator(const bst_const_iterator &copy){ *this = copy; }

                // Copy non const
                bst_const_iterator(const bst_iterator &copy): node(copy.base()) {}

                // Destructor
	            ~bst_const_iterator(void){}
                
                // ############################ => Metotlar <= ############################

                const node_pointer &base(void) const{
                    return (this->node);
                }

                // ############################ => Operator Overloading <= ############################

                // Copy Assignment
                bst_const_iterator &operator=(const bst_const_iterator &copy) {
                    if (*this != copy)
			            this->node = copy.node;
                    return (*this);
                }
                
                reference operator*(void) const{
                    return (this->node->data);
                }

                pointer operator->(void) const{
                    return (&this->node->data);
                }

                bst_const_iterator &operator++(void) {
                    this->increase();
                    return (*this);
                }

                bst_const_iterator operator++(int) {
                    bst_const_iterator temp = *this;
                    this->increase();
                    return (temp); 
                }

                bst_const_iterator &operator--(void) {
                    this->decrease();
                    return (*this);
                }

                bst_const_iterator operator--(int) {
                    bst_const_iterator temp = *this;
                    this->decrease();
                    return (temp); 
                }

                bool operator==(const bst_const_iterator &rhs) const{
                    return (this->node == rhs.node);
                }

	            bool operator!=(const bst_const_iterator &rhs) const{
                    return (!(*this == rhs));
                }
    };

    template <typename IteratorL, typename IteratorR> 
    bool operator==(const bst_iterator<IteratorL> &lhs, const bst_const_iterator<IteratorR> &rhs){
            return (lhs.base() == rhs.base());
    }

    template <typename IteratorL, typename IteratorR> 
    bool operator!=(const bst_iterator<IteratorL> &lhs, const bst_const_iterator<IteratorR> &rhs){
            return (lhs.base() != rhs.base());
    }
}

# endif