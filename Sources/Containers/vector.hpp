# ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../Iterator/normal_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"
# include "../Utils/stl_algobase.hpp"
# include "../Utils/type_traits.hpp"
# include <climits>
# include <sstream>

/* c++98 standartlarına göre to_string işlevini yapıyor */
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

namespace ft{

        template < typename T, typename Alloc = std :: allocator<T> > 
        class vector{

                public:

                        // ############################### => Typedef <= ###############################                // Örnek:

                        typedef                 T                                               value_type;             // int
                        typedef                 Alloc                                           allocator_type;         // allocator<int> classı
                        typedef typename        allocator_type::reference                       reference;              // int &
                        typedef typename        allocator_type::const_reference                 const_reference;        // const &
                        typedef typename        allocator_type::pointer                         pointer;                // int *
                        typedef typename        allocator_type::const_pointer                   const_pointer;          // const int *
                        typedef typename        allocator_type::difference_type                 difference_type;        // unsigned long
                        typedef typename        allocator_type::size_type                       size_type;              // unsigned int

                        typedef typename        ft::normal_iterator<pointer>                    iterator;
                        typedef typename        ft::normal_iterator<const_pointer>              const_iterator;
                        typedef typename        ft::reverse_iterator<iterator>                  reverse_iterator;
                        typedef typename        ft::reverse_iterator<const_iterator>            const_reverse_iterator;

                private:
                        pointer         array;
                        size_type       array_size;
                        size_type       array_capacity;
                        allocator_type  alloc;

                        void checkLength(size_type n){
                                if (n < 0 || n > INT_MAX)
                                        throw std :: length_error("cannot create ft::vector larger than max_size()");
                        }

                        void firstExecute(const allocator_type &alloc){
                                this->alloc = alloc;
                                this->array_size = 0;
                                this->array_capacity = 0;
                                this->array = this->alloc.allocate(0, NULL);
                        }

                        void freeArray(void){
                                for (size_type i = 0; i < this->array_size; i++)
                                        this->alloc.destroy(this->array++);
                                this->alloc.deallocate(this->array - this->array_size, this->array_capacity);
                        }

                public:

                        // ############################### => Constructor <= ###############################

                        // Default: ft::vector<T> v;  => 0 elemanlı içi boş T türünde dizi olsun
                        explicit vector(const allocator_type &alloc = allocator_type()){
                                this->firstExecute(alloc);
                        }

                        // Constructor v1: ft::vector<int> v(10, 0);    => 10 elemanlı int bir dizi olsun ve tüm elemanları 0 olsun
                        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
                                this->checkLength(n);
                                this->firstExecute(alloc);
                                this->insert(this->begin(), n, val);
                        }

                        // Constructor v2: iki iterator aralığı alıcaz kendi arrayımıza eklicez
                        template <typename InputIterator> 
                        vector(InputIterator first, typename ft::enable_if< !ft::is_integral<InputIterator>::value_type, InputIterator >::type last, const allocator_type &alloc = allocator_type()){
                                this->firstExecute(alloc);
                                this->assign(first, last);
                        }

                        // Copy
                        vector(const vector &copy){
                                this->firstExecute(copy.alloc);
                                *this = copy;
                        }

                        // Destructor
                        ~vector(void){
                                this->freeArray();
                        }

                        // ############################### => Metotlar <= ###############################

                        // ***************** ===> iterator işlemlerine yönelik <=== *****************

                        // Dizinin ilk elemanın iteratorunu döndürür.
                        iterator begin(void){
                                return (iterator(this->array));
                        }
                        
                        const_iterator begin(void) const{
                                return (const_iterator(this->array));
                        }

                        // Dizinin son elemanın iteratorunu döndürür.
                        iterator end(void){
                                return (iterator(this->array + this->array_size));
                        }
                        
                        const_iterator end(void) const{
                                return (const_iterator(this->array + this->array_size));
                        }

                        // Dizinin ilk elemanın iteratorunu ters olarak döndürür.
                        reverse_iterator rbegin(void){
                                return (reverse_iterator(this->end()));
                        }
                        
                        const_reverse_iterator rbegin(void) const{
                                return (const_reverse_iterator(this->end()));
                        }

                        // Dizinin son elemanın iteratörünü ters olarak döndürür.                        
                        reverse_iterator rend(void){
                                return (reverse_iterator(this->begin()));
                        }
                        
                        const_reverse_iterator rend(void) const{
                                return (const_reverse_iterator(this->begin()));
                        }

                        // ***************** ===> Kapasite işlemlerine yönelik <=== *****************

                        // Dizinin size döndürür
                        size_type size(void) const{
                                return (this->array_size);
                        }

                        size_type max_size(void) const{
                                return (this->alloc.max_size());
                        }

                        // Dizinin size yeniden boyutlandırmak için kullanılır
                        void resize(size_type n, value_type val = value_type()){

                                if (n < 0 || n > INT_MAX)
                                        throw std :: length_error("vector::_M_default_append");
                                else if (n < this->array_size) // size kücültmeye yönelik
                                        this->array_size = n;   
                                else // size büyütmeye yönelik
                                        this->insert(this->end(), (n - this->array_size), val);
                        }

                        // Dizinin kapasitesini döndürür
                        size_type capacity(void) const{
                                return (this->array_capacity);
                        }

                        // Dizinin boş olup olmadığı bool olarak döndürür.
                        bool empty(void) const{
                                if (this->array_size == 0)
                                        return (true);
                                return (false);
                        }

                        // Dizinin kapasitesini yendiden boyutlandırmak için kullanılır
                        void reserve(size_type n){
                                
                                if (n < 0 || n > INT_MAX)
                                        throw std :: length_error("ft::bad_alloc");
                                else if (n > this->array_capacity){ // kapasite büyütmeye yönelik

                                        pointer new_array = alloc.allocate(n, NULL);
                                        iterator first = this->begin();

                                        while (first != this->end())
                                                this->alloc.construct(new_array++, *first++);

                                        this->freeArray();
                                        this->array_capacity = n;
                                        this->array = new_array - this->array_size;
                                }
                                // kapasite küçültmeye yönelik herhangi bişey yapmıyoruz 
                        }

                        // ***************** ===> Dizinin elemanlarına erişmeye yönelik <=== *****************

                        // Dizinin gelen indexteki elemanın değerini döndürür.
                        reference at(size_type n){
                                if (n < 0 || n >= this->array_size)
                                        throw std :: out_of_range(SSTR("vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->array_size << ")"));
                                return (this->array[n]);
                        }
                        
                        const_reference at(size_type n) const{
                                if (n < 0 || n >= this->array_size)
                                        throw std :: out_of_range(SSTR("vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->array_size << ")"));
                                return (this->array[n]);
                        }

                        // Dizinin ilk elemanın değerini döndürür.
                        reference front(void){
                                return (*this->array);
                        }
                        
                        const_reference front(void) const{
                                return (*this->array);
                        }

                        // Dizinin son elemanın değerini döndürür.
                        reference back(void){
                                return (this->array[this->array_size - 1]);
                        }
                        
                        const_reference back(void) const{
                                return (this->array[this->array_size - 1]);
                        }

                        // Vector'un türünden düz dizi yapıp döndürür.
                        value_type *data(void) {
                                return (this->array);
                        }
                        
                        const value_type *data(void) const {
                                return (this->array);
                        }

                        // ***************** ===> Dizinin elemanlarına modifiye yönelik <=== *****************

                        // Assign fonksiyonları diziyi yeniden tanımlamak için kullanılır
                        template <typename InputIterator> 
                        void assign(InputIterator first, typename ft::enable_if< !ft::is_integral<InputIterator>::value_type, InputIterator >::type last){
                                
                                //iki iterator arası mesafeyi gösterir.
                                if (std::distance(first, last) < 0)
                                        throw std::length_error("cannot create ft::vector larger than max_size()");
                                this->array_size = 0;
                                this->insert(this->begin(), first, last);
                        }

                        void assign(size_type n, const value_type &val){
                                
                                if (n < 0 || n > INT_MAX)
                                        throw std :: length_error("ft::bad_alloc");
                                else{
                                        this->array_size = 0;
                                        this->insert(this->begin(), n, val);
                                }
                        }

                        // Dizinin en sonuna eleman ekler yeterli alan yoksa diziyi bir büyütür
                        void push_back(const value_type &val){
                                this->resize(this->array_size + 1, val);
                        }

                        // Dizinin en sonuna ki elemanı çıkartır ve diziyi bir küçültür
                        void pop_back(void){
                                this->alloc.destroy(this->array + this->array_size - 1);
                                this->array_size--;
                        }

                        // Insert fonksiyonları diziye toplu eleman eklemek için kullanılır
                        iterator insert(iterator position, const value_type &val){

                                int index = std::distance(this->begin(), position);
                                
                                if (this->array_size + 1 > this->array_capacity){ // yeterli kapasite yoksa

                                        pointer new_array = alloc.allocate(this->array_capacity + 1, NULL);
                                        iterator first = this->begin();

                                        while (first != position)
                                                this->alloc.construct(new_array++, *first++);

                                        this->alloc.construct(new_array++, val);

                                        while (position != this->end())
                                                 this->alloc.construct(new_array++, *position++);

                                        this->freeArray();
                                        this->array_capacity++;
                                        this->array_size++;
                                        this->array = new_array - this->array_size;
                                        
                                }else{ // yeterli kapasite varsa

                                        size_type i = ++this->array_size - 1;

                                        while (i > (size_type)std::distance(this->begin(), position)){
                                                this->alloc.construct((this->array + i), *(this->array + i - 1));
                                                i--;
                                        }
                                        this->alloc.construct((this->array + i), val);
                                }
                                return (this->begin() + index);
                        }

                        // n kadar position sonrasına val ekle
                        void insert(iterator position, size_type n, const value_type &val){

                                for (size_type i = 0; i < n; i++){
                                        position = insert(position, val);
                                }
                        }

                        // first ve last iterator aralığını position den sonrasına ekle. Buradaki position bizim arraymize ait
                        template <typename InputIterator>
                        void insert(iterator position, InputIterator first, typename ft::enable_if< !is_integral<InputIterator>::value_type, InputIterator >::type last){

                                while (last-- != first){
                                        position = insert(position, *last);
                                }
                        }

                        // Erase fonksiyonları diziden direk eleman silme veya aralık vererek toplu eleman silmeye yarar
                        iterator erase(iterator position){

                                int index = std::distance(this->begin(), position);
                                size_type i = index - 1;

                                while (++i < this->array_size - 1)
                                        this->alloc.construct((this->array + i), *(this->array + i + 1));
                                                              
                                this->array_size--;
                                return (this->begin() + index);
                        }
                        
                        // first ve last iki iterator arasındaki herşeyi sil (aslında silmiyoruz yana kaydırıyoruz)
                        iterator erase(iterator first, iterator last){

                                iterator temp = first;
                                iterator position = first;

                                while (first++ != last)
                                        position = erase(position);
                                return (temp);
                        }

                        // std :: swap kullancaz
                        void swap(vector &x){
                                std :: swap(this->alloc, x.alloc);
                                std :: swap(this->array, x.array);
                                std :: swap(this->array_size, x.array_size);
                                std :: swap(this->array_capacity, x.array_capacity);
                        }

                        // Dizinin tüm elemanlarını siler
                        void clear(void){
                                this->freeArray();
                                this->firstExecute(this->alloc);
                        }

                        // Allocator dan gelen nesneyi geri döndürülür
                        allocator_type get_allocator(void) const{
                                return(this->alloc);
                        }

                        // ############################### => Operator Overloading <= ###############################

                        // Copy Assignment Operator
                        vector &operator=(const vector &copy){

                                if(*this != copy){
                                        this->freeArray();
                                        this->alloc = copy.alloc;
                                        this->array_size = copy.array_size;
                                        this->array_capacity = copy.array_capacity;
                                        this->array = this->alloc.allocate(this->array_capacity, NULL);
                                        this->assign(copy.begin(), copy.end());
                                }
                                return (*this);
                        }

                        // ft::vector<T> v(5); v[2] dizinin 2. indexsini döndürür
                        reference operator[](size_type n){
                                return (this->array[n]);
                        }
                        
                        const_reference operator[](size_type n) const{
                                return (this->array[n]);
                        }
        };

        // ############################### => No-member functions <= ###############################

        template< typename T, typename Alloc >
        void swap( ft::vector<T, Alloc> &lhs, ft::vector<T,Alloc> &rhs){
                std :: swap(lhs, rhs);
        }

        // ############################### => Operator Overloading <= ###############################
        // Not: (==) ilk gelen iki dizinin boyutlarına göre bir kıyaslanma olacak boyutları eşit ise
        // equal kullanarak işlem yapılacak
        //
        // (<) de ise lexicographical_compare algoritmasını kullanarak bir kıyaslama yapıcaz

        template <typename T, typename Alloc>
        bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                
                if (lhs.size() != rhs.size())
                        return (false);
                return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
        }
        
        template <typename T, typename Alloc>
        bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
               return (!(lhs == rhs));
        }
        
        template <typename T, typename Alloc>
        bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }
        
        template <typename T, typename Alloc>
        bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                return (!(rhs < lhs));
        }
        
        template <typename T, typename Alloc>
        bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                return (rhs < lhs);
        }
        
        template <typename T, typename Alloc>
        bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                return (!(lhs < rhs));
        }
}

# endif