# ifndef STL_ALGOBASE_HPP
# define STL_ALGOBASE_HPP

namespace ft{
        
        // ################################## => equal <= ##################################
        // Not: iki diziyi karşılaştırıyor ama bunu iteratorler ile yapıyor Parametre olarak
        // 1. dizinin iki iterator arası (begin() - end() verirsek tüm diziyi karşılaştırır 
        // herhangi bir aralık veriyoruz kısaca) ve 2. dizinin başlangıç iteratoru (ondan 
        // devamını karşılaştırcak)
        //
        // V2: Ek parametre olarak bir bool döndüren fonksiyon alıyor (fonksiyon parametre
        // olarak T türünden 2 parametre almalı) pred fonksiyonundan gelecek sonuça göre equal 
        // true veya false döndürüyor yani iki diziyi sorgulama işlemini ek parametre ile biz
        // belirliyebiliyoruz örnek tanımlama: bool pred(const Type1 &a, const Type2 &b);

        template <typename InputIterator1, typename InputIterator2>
        bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
                
                while (first1 != last1) {
                        if (*first1++ != *first2++)
                                return (false);
                }
                return (true);
        }

        template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate> 
        bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
                
                while (first1 != last1){
                        if (!pred(*first1++, *first2++))
                                return (false);
                }
                return (true);
        }

        // ################################## => lexicographical_compare <= ##################################
        // Not: iki dizinin sayısal değerlerini karşılaştırıyor (ascii strcmp aslında) ama bunu iterator ile 
        // yapıyor parametre olarak 1. dizinin 2 iterator aralıgı aynı şekil 2. dizinde 2 iterator aralıgı alıyor
        // 2. dizi 1. diziden büyükse true değilse false döner.
        // 
        // v2: Yukardaki gibi karşılaştırma işlemini ek parametre olarak alınan fonksiyon ile yapıyor
        // fonksiyonun tanımı bu şekil olmalı: bool comp( const Type1 &a , const Type2 & b );

        template <typename InputIterator1, typename InputIterator2> 
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
                
                while (first1 != last1){
                        if (first2 == last2 || *first2 < *first1)
                                return (false);
                        else if (*first1 < *first2)
                                return (true);
                        first1++;
                        first2++;
                }
                return (first2 != last2);
        }

        template <typename InputIterator1, typename InputIterator2, typename Compare> 
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp){
                while (first1 != last1){
                        if (first2 == last2 || comp(*first2, *first1))
                                return (false);
                        else if (comp(*first1, *first2))
                                return (true);
                        first1++;
                        first2++;
                }
                return (first2 != last2);
        }
}

# endif