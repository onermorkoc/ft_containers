# ifndef TYPE_TRAITS
# define TYPE_TRAITS

# include <iostream>

namespace ft{

        // ################################## => enable_if <= ##################################
        // Not: Eğer gelen bool koşulu true ise type özelliğine sahip olacak
        // Örnek: enable_if<is_integral<T>::value_type, T>::type

        template<bool Cond, typename T = void> 
        struct enable_if {};

        template<typename T> 
        struct enable_if<true, T> { 
                typedef T type;
        };

        // ################################## => is_integral <= ##################################
        // Not: Gelen sablon türü int ise value_type true olarak döndürür

        // Not v2: value_type değişkeninde static const kullanma nedenimiz derleyicinin struct ve
        // classlarda direk değer vermesine müsade etmiyor olması static const olursa buna izin veriyor

        struct false_type {
                static const bool value_type = false;
                typedef false_type type;
        };

        struct true_type {
                static const bool value_type = true;
                typedef true_type type;
        };

        template <typename>
        struct is_integral : public false_type {};

        template<>
        struct is_integral<bool>: public true_type {};

        template<>
        struct is_integral<char>: public true_type {};

        template<>
        struct is_integral<signed char>: public true_type {};
        
        template<>
        struct is_integral<short int>: public true_type {};
        
        template<>
        struct is_integral<int>: public true_type {};

        template<>
        struct is_integral<long int>: public true_type {};

        template<>
        struct is_integral<long long int>: public true_type {};

        template<>
        struct is_integral<unsigned char>: public true_type{};

        template<>
        struct is_integral<unsigned short int>: public true_type {};

        template<>
        struct is_integral<unsigned int>: public true_type {};

        template<>
        struct is_integral<unsigned long int>: public true_type {};

        template<>
        struct is_integral<unsigned long long int>: public true_type {};
}

# endif