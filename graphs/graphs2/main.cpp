#include <iostream>
using namespace std;

//Graf oluşturma...

//bağlı liste elemanları tutar
struct adjNode {
    int val, cost;
    adjNode* next;
};

//kenarları saklamak için oluşturulan struct
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph{
    //verilen graftaki bağlı listesine yeni düğümler ekle
    adjNode* getAdjListNode(int value, int weight, adjNode* head)   {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head;  //yeni düğümü geçerli başlığa yönlendir
        return newNode;
    }
    int dugumSayisi;  //graftaki düğüm sayısı
public:
    adjNode **head;  //işaretçi dizisi olarak bağlı liste

    DiaGraph(graphEdge kenarlar[], int kenarSayisi, int dugumSayisi)  { //constructor

        head = new adjNode*[dugumSayisi]();//yeni düğüm ekler
        this->dugumSayisi = dugumSayisi;

        for (int i = 0; i < dugumSayisi; ++i)//tüm köşeler için head işaretçisini başlatır
            head[i] = nullptr;

        //kenarları ekleyerek yönlendirilmiş graf oluşturma
        for (unsigned i = 0; i < kenarSayisi; i++)  {
            int start_ver = kenarlar[i].start_ver;
            int end_ver = kenarlar[i].end_ver;
            int weight = kenarlar[i].weight;

            //başlangıçta ekler
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

            head[start_ver] = newNode;//yeni düğüme head işaretçisini atar
        }
    }

    ~DiaGraph() {// destructor(yıkıcı)
        for (int i = 0; i < dugumSayisi; i++)
            delete[] head[i];
        delete[] head;
    }
};
// verilen tepe noktasının tüm bitişik köşelerini yazdır
void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
             << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    // graf kenarlar dizisi
    graphEdge kenarlar[] = {
            // (x, y, w) -> edge from x to y with weight w
            {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int dugumSayisi = 6;//graftaki köşe noktası(dugum) sayısı

    int kenarSayisi = sizeof(kenarlar)/sizeof(kenarlar[0]);//graftaki kenar sayısını hesaplar

    DiaGraph diagraph(kenarlar, kenarSayisi, dugumSayisi);//graf oluşturur

    cout<<"(start_vertex, end_vertex, weight):"<<endl;
    for (int i = 0; i < dugumSayisi; i++)//bitişik liste grafının gösterimi
    {
        //komşu köşeleri gösterir
        display_AdjList(diagraph.head[i], i);
    }
    return 0;
}