# ifndef ITERATOR_HPP
# define ITERATOR_HPP

// şimdilik iptal //

/* namespace ft{
        
        template<typename I>
        class iterator{

                private:
                        I *address;
                
                public:

                        iterator(I *address){
                                this->address = address;
                        }

                        iterator(const iterator &copy){
                                this->address = copy.address;
                        }

                        iterator &operator=(I &data){
                                this->address = data;
                                return (*this);
                        }

                        I operator*(void){
                                return (this->address[0]);
                        }

                        I operator++(void){
                                this->address++;
                                return (this->address[0]);
                        }

                        I operator--(void){
                                this->address--;
                                return (this->address[0]);
                        }

                        I operator++(int){
                                iterator temp(*this);
                                this->address++;
                                return (temp[0]);
                        }

                        I operator--(int){
                                iterator temp(*this);
                                this->address--;
                                return (temp[0]);
                        }

                        I operator[](int index){
                                return (this->address[index]);
                        }

                        bool operator<(const iterator objectRight){
                                return (this->address < objectRight.address);
                        }

                        bool operator<=(const iterator objectRight){
                                return (this->address <= objectRight.address);
                        }

                        bool operator>(const iterator objectRight){
                                return (this->address > objectRight.address);
                        }

                        bool operator>=(const iterator objectRight){
                                return (this->address >= objectRight.address);
                        }

                        bool operator==(const iterator objectRight){
                                return (this->address == objectRight.address);
                        }

                        bool operator!=(const iterator objectRight){
                                return (this->address != objectRight.address);
                        }
        };
}
 */
# endif