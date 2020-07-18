#include<iostream>
using namespace std;

// AVL agacı sınıfı
class AVLNode
{
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int depth;
};

//iki sayıdan buyuk olanını bulan fonksiyon
int max(int a, int b){
    return (a > b)? a : b;
}

//ağacın yüksekliğini bulan fonksiyon
int depth(AVLNode *n)
{
    if (n == NULL)
        return 0;
    return n->depth;
}
//anahtar geçerek yeni bir düğüm ata
AVLNode* newNode(int key)
{
    AVLNode* node = new AVLNode();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->depth = 1; // new node added as leaf
    return(node);
}
// y düğümü eklenecek olan alt ağacı sağa döndür
AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // döndürme gerçekleştir
    x->right = y;
    y->left = T2;

    // yükseklik guncellenir
    y->depth = max(depth(y->left),
                   depth(y->right)) + 1;
    x->depth = max(depth(x->left),
                   depth(x->right)) + 1;

    // düğüm return edilir
    return x;
}

// x düğümü eklenecek olan alt ağacı sola döndür
AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // döndürme gerçekleştir
    y->left = x;
    x->right = T2;
    // yükseklik guncellenir
    x->depth = max(depth(x->left),
                   depth(x->right)) + 1;
    y->depth = max(depth(y->left),
                   depth(y->right)) + 1;

    // düğüm return edilir
    return y;
}

//N düğümünün denge faktörünü alınır
int getBalance(AVLNode *N)
{
    if (N == NULL)
        return 0;
    return depth(N->left) -
           depth(N->right);
}
//AVL ağacına düğüm ekleme işlemi
AVLNode* insert(AVLNode* node, int key)  {
    //normal BST rotasyonu
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else //Eşit değerlere izin verilmiyor
        return node;

    //ata düğümünün yüksekliğini günceller
    node->depth = 1 + max(depth(node->left),  depth(node->right));

    int balance = getBalance(node);//denge faktörü

    // dengesizse döndür

    // sol-sol durumu
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // sağ-sağ durumu
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    //sol-sağ durumu
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // sağ-sol durumu
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// minimum değere sahip düğümü bulan fonksiyon
AVLNode * minValueNode(AVLNode* node)
{
    AVLNode* current = node;

    // en soldaki yaprağı bulur
    while (current->left != NULL)
        current = current->left;

    return current;
}
//verilen anahtarla AVL ağacından bir düğümü silen fonksiyon
AVLNode* deleteNode(AVLNode* root, int key)
{
    if (root == NULL)
        return root;

    //BST silme işlemini gerçekleştirilir
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {
        //sadece bir çocuğu olan ya da çocuğu olmayan düğüm
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            AVLNode *temp = root->left ?
                            root->left :
                            root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // düğümde bir çocuk varsa
                *root = *temp;
            free(temp);
        }
        else
        {
            AVLNode* temp = minValueNode(root->right);

            root->key = temp->key;

            // inorder siler
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    //derinliği günceller
    root->depth = 1 + max(depth(root->left), depth(root->right));


    int balance = getBalance(root);//denge faktörü

    //dengesizse ağacı döndür

    //sol-sol durumu
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    //sol-sağ durumu
    if (balance > 1 &&  getBalance(root->left) < 0)  {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //sağ-sağ durumu
    if (balance < -1 &&  getBalance(root->right) <= 0)
        return leftRotate(root);

    //sağ-sol durumu
    if (balance < -1 && getBalance(root->right) > 0)   {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// AVL ağacını inorder yazdırır
void inOrder(AVLNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    AVLNode *root = NULL;

    // AVL ağacı oluşturur ve düğümler eklenir
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 18);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 17);
    root = insert(root, 4);

    //Yukarıdaki ağaç için düzensiz geçiş: 4 5 8 11 12 17 18
    cout << "AVL ağacı: \n";
    inOrder(root);//inorder sıralayarak yazdırır
    root = deleteNode(root, 5);//5 numaralı düğümü siler
    cout << "\n5 numaralı düğüm silindikten sonra AVL ağacı: \n";
    inOrder(root);

    return 0;
}