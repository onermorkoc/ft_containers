# ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include <iostream>

template<typename T>
struct BST{

    typedef     T                   value_type;
    typedef     BST<value_type>*    node_pointer;

    bool            end;
    value_type      data;
    node_pointer    left;
    node_pointer    right;
    node_pointer    parent;
    
    BST(bool end, const value_type &data, node_pointer left, node_pointer right, node_pointer parent):
    end(end), data(data), left(left), right(right), parent(parent) {}
};

template<typename Key, typename T, typename Compare, typename Allocator>
class binary_search_tree {

    public:
            // ############################ => Typedef <= ############################
            typedef             Key                                                 key_type;
            typedef             ft::pair<const Key, T>                              value_type;
            typedef             Compare                                             key_compare;
            typedef             BST<value_type>                                     node_type;
            typedef             node_type*                                          node_pointer;
            typedef typename    Allocator::size_type                                size_type;
	        typedef typename    Allocator::template rebind<node_type>::other        node_alloc;

    private:
            node_pointer    root;
            node_pointer    end_node;
            key_compare     compare;
            node_alloc      alloc;
    public:
            // ############################ => Constructor <= ############################

            // Default
            binary_search_tree(void): compare(key_compare()), alloc(node_alloc()) {
                this->firstExecute();
            }

            // Destructor
            ~binary_search_tree(void) {
                this->freeTree(this->root);
                this->freeNode(this->end_node);
            }

    private:

            // İlk çalışmada root ve end() ayarlıyorum.
            void firstExecute(void){
                this->root = NULL;
                this->end_node = createNewNode(node_type(true, value_type(), NULL, NULL, NULL));
            }

            // Yeni node oluşturup döndürür.
            node_pointer createNewNode(node_type node_t){
                node_pointer new_node = this->alloc.allocate(1);
                this->alloc.construct(new_node, node_t);
                return (new_node);
            }

            // Node'nin içindeki datayı(pair) değiştirir.
            node_pointer changeNodeData(node_pointer node, const value_type &new_data){
                node_pointer temp_right = node->right;
                node_pointer temp_lelft = node->left;
                node_pointer temp_parent = node->parent;
                this->freeNode(node);
                return (createNewNode(node_type(false, new_data, temp_lelft, temp_right, temp_parent)));
            }

            // Tree'ye yeni node ekler.
            node_pointer addTreeNode(node_pointer tree, const value_type &data, node_pointer parent) {
                if(tree == NULL || tree->end == true)
                    return (this->createNewNode(node_type(false, data, NULL, NULL, parent)));
                else{
                    if (compare(data.first, tree->data.first))
                        tree->left = addTreeNode(tree->left, data, tree);
                    else
                        tree->right = addTreeNode(tree->right, data, tree);
                    return (tree);
                }
            }

            // Gelen key'i tree'nin içinde arar varsa node'yi yoksa null döndürür.
            node_pointer keyToNode(node_pointer tree, key_type key) const{
                if (tree == NULL)
                    return (NULL);
                else if (tree->data.first == key)
                    return (tree);
                else{
                    if (compare(key, tree->data.first))
                        return keyToNode(tree->left, key);
                    else
                        return keyToNode(tree->right, key);
                }
            }

            // Gelen ağacın en soluna gider(min).
            node_pointer goLastLeft(node_pointer tree) const {
                if (tree->left != NULL)
                    tree = goLastLeft(tree->left);
                return (tree);
            }

            // Gelen ağacın en sağına gider(max).
            node_pointer goLastRight(node_pointer tree) const {
                if (tree->right != NULL)
                    tree = goLastRight(tree->right);
                return (tree);
            }

            /*
             -Tree'den gelen node'yi bulup siler.
             -Sağ varsa sağın en soluna git
             -Sol varsa solun en sağına git
             -Bu işlemler leaf veya null olana kadar iç içe devam eder.
            - Burdaki püf nokta silinecek olan değer freelenmiyor içindeki değerler değişiyor.(taşıma işlemi diyebiliriz)
              freelenenen node: leaf veya null bir node oluyor
            */
            node_pointer deleteNode(node_pointer tree, const value_type &data){

	            if (tree == NULL)
		            return (NULL);
                else if (tree->data == data){ // Değer bulundu silme işlemi yap
                    if (tree->left == NULL && tree->right == NULL){ // Leaf olma durumu
                        this->freeNode(tree);
                        return (NULL);
                    }
		            else {
                        if (tree->right != NULL){
                            // tree nin parenti sabit kalacak.
                            // sağının ve solunun parenti tree olacak
                            if (tree->right->end == true){ //silinecek değerin sağında end olma durumu
                                node_pointer temp_parrent = tree->parent;
                                this->freeNode(tree);
                                tree = this->end_node;
                                tree->parent = temp_parrent;
                            }else{
                                tree = changeNodeData(tree, goLastLeft(tree->right)->data);
                                tree->right->parent = tree;
                                if (tree->left != NULL)
                                    tree->left->parent = tree;
			                    tree->right = deleteNode(tree->right, goLastLeft(tree->right)->data);
                            }
		                }else{
                            tree = changeNodeData(tree, goLastRight(tree->left)->data);
                            tree->left->parent = tree;
                            if (tree->right != NULL)
                                tree->right->parent = tree;
		                    tree->left = deleteNode(tree->left, goLastRight(tree->left)->data);
                        }
                        return (tree);
                    }
                }else{ // Bulana kadar dolaş
                    if (compare(data.first, tree->data.first))
                        tree->left = deleteNode(tree->left, data);
                    else
                        tree->right = deleteNode(tree->right, data);
                }
                return (tree);
            }

            void freeTree(node_pointer tree){
                if (tree == NULL || tree->end == true)
                    return;
                freeTree(tree->right);
                freeTree(tree->left);
                this->freeNode(tree);
            }

            void transfer(node_pointer tree){
                if (tree == NULL || tree->end == true)
                    return;
                this->add(tree->data);
                this->transfer(tree->left);
                this->transfer(tree->right);
            }

            // Gelen key'in en yakın değerini bul yoksa end döndür. 
            node_pointer nextOrEnd(const key_type &key) const{
                
                node_pointer temp = this->root;

                if (temp->end == true || !compare(key, this->maxNode()->parent->data.first))
                    return (this->maxNode());
                else{
                    while (1){
                        if(temp->right == NULL && !compare(key, temp->data.first)){
                            while (temp->parent->left != temp)
				                temp = temp->parent;
				            return (temp->parent);
                        }else if (temp->left == NULL && compare(key, temp->data.first))
                            return (temp);
                        else{ // Dolaşma
                            if (compare(key, temp->data.first))
                                temp = temp->left;
                            else
                                temp = temp->right;
                        }
                    }
                }
            }

            void freeNode(node_pointer node){
                this->alloc.destroy(node);
                this->alloc.deallocate(node, 1);
            }

            void updateEndNode(void){
                node_pointer node = this->goLastRight(this->root);
                if (node->end == false){
                    node->right = this->end_node;
                    node->right->parent = node;
                }
            }
            
    public:
            // Gelen key tree de ara varsa value'sini döndür yoksa throw fırlat.
            T &keyToValue(const key_type &key) const{
                if (!this->checkKey(key))
                    throw std ::out_of_range("map::at");
                return (keyToNode(this->root, key)->data.second);
            }

            // Tree nin key bakımından en küçük elemanı döndürür.
            node_pointer minNode(void) const{
                if (this->root == NULL)
                    return (this->end_node);
                return (this->goLastLeft(this->root));
            }

            // Tree nin key bakımından en büyük elemanı döndürür.
            node_pointer maxNode(void) const{
                if (this->root == NULL)
                    return (this->end_node);
                return (this->goLastRight(this->root));
            }

            /*  Açıklama:
                1) Gelen pair varsa bulunduğu node yi return et.
                2) Eğer yoksa ekleyip return et.
                3) Şayet ekleme işlemi olursa end() durumunu düzenle.
            */
            node_pointer addOrFind(const value_type &data){
                if (!this->checkKey(data.first))
                    return (this->add(data)); // (2)
                return (this->keyToNode(this->root, data.first)); // (1)
            }

            // Burada eklenecek data nın tree de olmama durumunu kabul eder
            node_pointer add(const value_type &data){
                this->root = this->addTreeNode(this->root, data, NULL);
                this->updateEndNode(); // (3)
                return (this->keyToNode(this->root, data.first));
            }

            // Gelen key tree de varsa 1 yoksa 0 döndür.
            size_type checkKey(const key_type &key) const{
                if (keyToNode(this->root, key) == NULL)
                    return (0);
                return (1);
            }

            // Gelen key tree de varsa bul nodeyi return et yoksa end() return et.
            node_pointer findOrEnd(const key_type &key) const{
                if (this->checkKey(key))
                    return (this->keyToNode(this->root, key));
                return (this->maxNode());
            }

            // Gelen key tree de yoksa silme ve 0 return et varsa sil ve 1 return et.
            size_type deleteNode(const key_type &key){
                if (!this->checkKey(key))
                    return (0);
                this->root = this->deleteNode(this->root, keyToNode(this->root, key)->data);
                return (1);
            }

            node_pointer getRoot(void) const{
                return (this->root);
            }

            // Gelen key'in bir sonraki nodeyi return et yoksa end() node'yi return et.
            node_pointer findUpperOrEnd(const key_type &key) const{
                return (this->nextOrEnd(key));
            }

            // Gelen key varsa node'sini return et yoksa findUpperOrEnd() işlevini tekrarla.
            node_pointer findLowerOrEnd(const key_type &key) const {
                if(this->checkKey(key))
                    return (this->keyToNode(this->root, key));
                return (this->nextOrEnd(key));
            }

            void setRoot(const node_pointer tree){
                this->clearTree();
                return (this->transfer(tree));
            }

            size_type maxSize(void) const{
                return (this->alloc.max_size());
            }

            void clearTree(void){
                this->freeTree(this->root);
                this->freeNode(this->end_node);
                this->firstExecute();
            }

            void swap(binary_search_tree &other){
                std :: swap(this->root, other.root);
                std :: swap(this->alloc, other.alloc);
                std :: swap(this->end_node, other.end_node);
                std :: swap(this->compare, other.compare);
            }
};

# endif