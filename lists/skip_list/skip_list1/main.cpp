#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//skip list'e eleman ekleme

//düğüm oluşturmak için sınıf
class Node
{
public:
    int key;

    //işaretçileri farklı düzeydeki düğüme tutmak için dizi
    Node **forward;
    Node(int, int);
};

Node::Node(int key, int level)
{
    this->key = key;

    //ileriye doğru bellek ayırma
    forward = new Node*[level+1];

    //diziyi 0 (NULL) ile doldur
    memset(forward, 0, sizeof(Node*)*(level+1));
};

class SkipList
{
    int MAXLVL; //Skip list için maksimum seviye
    float P;
    int level;//geçerli Skip list seviyesi

    Node *header;//header düğümü işaretçisi
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    void displayList();
};

SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;

    //header düğümü oluşturur ve anahtarı -1 olarak başlatır
    header = new Node(-1, MAXLVL);
};

//düğüm için rastgele seviye oluşturur
int SkipList::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};

//yeni düğüm oluşturur
Node* SkipList::createNode(int key, int level)
{
    Node *node = new Node(key, level);
    return node;
};

//verilen anahtarı SkipList'e ekler
void SkipList::insertElement(int key)
{
    Node *current = header;

    //güncelleme dizisi oluşturur ve başlatır
    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));

    /* en üst düzey atlama listesinden anahtar başlar , update dizisi aksi halde güncellenmiş update dizisi yanındaki düğümün
     anahtarından daha büyük iken geçerli işaretçiyi ileriye doğru hareket ettirir ve bir seviye aşağı doğru hareket
     ettirir ve aramaya devam eder
    */
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != NULL &&
               current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    /* anahtar eklemek için istenen pozisyon sağ seviye 0 ve ileri işaretçi ulaştı*/
    current = current->forward[0];

    /* current NULL ise, seviyenin sonuna ulaştığımız anlamına gelir veya current'in anahtarı eklemek için anahtara
     eşit değildir; bu, update[0] ve current node arasında düğüm eklememiz gerektiği anlamına gelir */
    if (current == NULL || current->key != key)
    {
        // düğüm için rastgele bir seviye oluşturma
        int rlevel = randomLevel();

        /*rasgele düzey listenin geçerli düzeyinden büyükse, daha fazla
         kullanım için üstbilgi işaretçisi ile güncelleme değerini başlatılır*/
        if (rlevel > level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = header;

            //liste current seviyesini güncelleme
            level = rlevel;
        }

        //rasgele seviye oluşturulmuş yeni düğüm oluştur
        Node* n = createNode(key, rlevel);

        //işaretçileri yeniden düzenleyerek düğümü ekler
        for (int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout << "Successfully Inserted key " << key << "\n";
    }
}

//listenin yazdırılması
void SkipList::displayList()
{
    cout<<"\n*****Skip List*****"<<"\n";
    for (int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != NULL)
        {
            cout << node->key<<" ";
            node = node->forward[i];
        }
        cout << "\n";
    }
};

int main()
{
    srand((unsigned)time(0));//program her çalıştığında farklı sayı üretmek için

    SkipList liste(3, 0.5);//SkipList sınıfına nesne oluşturma

    liste.insertElement(3);//listeye anahtarlar ekler
    liste.insertElement(6);
    liste.insertElement(7);
    liste.insertElement(9);
    liste.insertElement(12);
    liste.insertElement(19);
    liste.insertElement(17);
    liste.insertElement(26);
    liste.insertElement(21);
    liste.insertElement(25);

    liste.displayList();//listeyi yazdırır
}
