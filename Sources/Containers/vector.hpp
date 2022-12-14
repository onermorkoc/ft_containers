# ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "../Iterator/normal_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"

namespace ft{

        template < typename T, typename Alloc = std :: allocator<T> > 
        class vector{

                public:

                        // ############################### => Typedef <= ###############################  

                        typedef                 T                                               value_type;             // int
                        typedef                 Alloc                                           allocator_type;         // allocator<int> classı
                        typedef typename        allocator_type::reference                       reference;              // int &
                        typedef typename        allocator_type::const_reference                 const_reference;        // const &
                        typedef typename        allocator_type::pointer                         pointer;                // int *
                        typedef typename        allocator_type::const_pointer                   const_pointer;          // const int *
                        typedef typename        allocator_type::difference_type                 difference_type;        // unsigned long
                        typedef typename        allocator_type::size_type                       size_type;              // unsigned int

                        typedef typename        ft::normal_iterator<pointer>                    iterator;
                        typedef typename        ft::normal_iterator<pointer>                    const_iterator;
                        typedef typename        ft::reverse_iterator<iterator>                  reverse_iterator;
                        typedef typename        ft::reverse_iterator<const_iterator>            const_reverse_iterator;

                private:
                        pointer         array;
                        size_type       array_size;
                        size_type       array_capacity;
                        allocator_type  object;

                public:

                        // ############################### => Constructor <= ###############################

                        // Default: ft::vector<T> v;  => 0 elemanlı içi boş T türünde dizi olsun
                        explicit vector(const allocator_type &alloc = allocator_type()){
                                
                                this->object = alloc;
                                this->array_size = 0;
                                this->array_capacity = 0;
                                this->array = object.allocate(0, NULL);

                        }

                        // Constructor v1: ft::vector<int> v(10, 0);    => 10 elemanlı int bir dizi olsun ve tüm elemanları 0 olsun
                        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
                                
                                this->object = alloc;
                                this->array_size = n;
                                this->array_capacity = n;
                                this->array = this->object.allocate(n, NULL);

                                for (int i = 0; i < n; i++){
                                        this->array[i] = val;
                                }

                        }

                        // Constructor v2: iki iterator aralığı alıcaz kendi arrayımıza eklicez std :: string s parametresi silinecek
                        template <class InputIterator> 
                        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Copy
                        vector(const vector &copy){
                                *this = copy;
                        }

                        // Destructor
                        ~vector(void){
                                this->object.deallocate(this->array, this->array_capacity);
                        }

                        // ############################### => Metotlar <= ###############################

                        // ***************** ===> iterator işlemlerine yönelik <=== *****************

                        // Dizinin ilk elemanın iteratorunu döndürür.
                        iterator begin(void){
                                iterator i(this->array);
                                return (i);
                        }
                        
                        const_iterator begin(void) const{
                                const_iterator i(this->array);
                                return (i);
                        }

                        // Dizinin son elemanın iteratorunu döndürür.
                        iterator end(void){
                                iterator i(this->array + this->array_size);
                                return (i);
                        }
                        
                        const_iterator end(void) const{
                                const_iterator i(this->array + this->array_size);
                                return (i);
                        }

                        // Dizinin ilk elemanın iteratorunu ters olarak döndürür.
                        reverse_iterator rbegin(void){
                                reverse_iterator r(this->end() - 1); // -1 null atlamak için
                                return (r);
                        }
                        
                        const_reverse_iterator rbegin(void) const{
                                const_reverse_iterator r(this->end() - 1);
                                return (r);
                        }

                        // Dizinin son elemanın iteratörünü ters olarak döndürür.                        
                        reverse_iterator rend(void){
                                reverse_iterator r(this->begin() - 1); // -1 bu sefer null olması için
                                return (r);
                        }
                        
                        const_reverse_iterator rend(void) const{
                                const_reverse_iterator r(this->begin() - 1);
                                return (r);
                        }

                        // ***************** ===> Kapasite işlemlerine yönelik <=== *****************

                        // Dizinin size döndürür
                        size_type size(void) const{
                                return (this->array_size);
                        }

                        size_type max_size(void) const{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Dizinin size yeniden boyutlandırmak için kullanılır
                        void resize(size_type n, value_type val = value_type()){
                                // ++++++++++++ YAZILACAK ++++++++++++
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
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // ***************** ===> Dizinin elemanlarına erişmeye yönelik <=== *****************

                        // Dizinin gelen indexteki elemanın değerini döndürür.
                        reference at(size_type n){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }
                        
                        const_reference at(size_type n) const{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Dizinin ilk elemanın değerini döndürür.
                        reference front(void){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }
                        
                        const_reference front(void) const{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Dizinin son elemanın değerini döndürür.
                        reference back(void){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }
                        
                        const_reference back(void) const{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Vector'un türünden düz dizi yapıp döndürür.
                        value_type *data(void) noexcept{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }
                        
                        const value_type *data(void) const noexcept{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // ***************** ===> Dizinin elemanlarına modifiye yönelik <=== *****************

                        // Assign fonksiyonları diziyi yeniden tanımlamak için kullanılır
                        template <class InputIterator> 
                        void assign(InputIterator first, InputIterator last){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        void assign(size_type n, const value_type &val){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Dizinin en sonuna eleman ekler yeterli alan yoksa diziyi bir büyütür
                        void push_back(const value_type &val){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Dizinin en sonuna ki elemanı çıkartır ve diziyi bir küçültür
                        void pop_back(void){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Insert fonksiyonları diziye toplu eleman eklemek için kullanılır
                        iterator insert(iterator position, const value_type &val){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        void insert(iterator position, size_type n, const value_type &val){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        template <class InputIterator>
                        void insert(iterator position, InputIterator first, InputIterator last){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Erase fonksiyonları diziden direk eleman silme veya aralık vererek toplu eleman silmeye yarar 
                        iterator erase(iterator position){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }
                        
                        iterator erase(iterator first, iterator last){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // std :: swap kullancaz
                        void swap(vector &x){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Dizinin tüm elemanlarını siler
                        void clear(void){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // Allocator dan gelen nesneyi geri döndürülür
                        allocator_type get_allocator(void) const{
                                return(this->object);
                        }

                        // ############################### => Operator Overloading <= ###############################

                        // Copy Assignment Operator
                        vector &operator=(const vector &copy){

                                this->object = copy.object;
                                this->array_size = copy.array_size;
                                this->array_capacity = copy.array_capacity;
                                this->array = this->object.allocate(this->array_capacity, NULL);

                                for (int i = 0; i < this->array_size; i++){
                                        this->array[i] = copy.array[i];
                                }
                                return (*this);

                        }

                        // ft::vector<T> v(5); v[2] dizinin 2. indexsini döndürür
                        reference operator[](size_type n){
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }
                        
                        const_reference operator[](size_type n) const{
                                // ++++++++++++ YAZILACAK ++++++++++++
                        }

                        // ############################### => Test <= ###############################

                        void elemanEkle(void){
                                this->array[0] = 56;
                                this->array[1] = 2;
                                this->array[2] = 3;
                                this->array[3] = 4;
                                this->array[4] = 5;
                                this->array[5] = 6;
                                this->array[6] = 90;
                        }

                        void ekranaBas(void){
                                std :: cout << "Eleman: " << this->array[0] << std :: endl;
                                std :: cout << "Eleman: " << this->array[1] << std :: endl;
                                std :: cout << "Eleman: " << this->array[2] << std :: endl;
                                std :: cout << "Eleman: " << this->array[3] << std :: endl;
                                std :: cout << "Eleman: " << this->array[4] << std :: endl;
                                std :: cout << "Eleman: " << this->array[5] << std :: endl;
                                std :: cout << "Eleman: " << this->array[6] << std :: endl;                                
                        }
        };

        // ############################### => Mantıksal Operator Overloading <= ###############################
        
        template <class T, class Alloc>
        bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                // ++++++++++++ YAZILACAK ++++++++++++
        }
        
        template <class T, class Alloc>
        bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                // ++++++++++++ YAZILACAK ++++++++++++
        }
        
        template <class T, class Alloc>
        bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                // ++++++++++++ YAZILACAK ++++++++++++
        }
        
        template <class T, class Alloc>
        bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                // ++++++++++++ YAZILACAK ++++++++++++
        }
        
        template <class T, class Alloc>
        bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                // ++++++++++++ YAZILACAK ++++++++++++
        }
        
        template <class T, class Alloc>
        bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
                // ++++++++++++ YAZILACAK ++++++++++++
        }
}

# endif