#include<iostream>
#include <list>

//Belirli bir kaynak köşesinden bfs geçişi yazdırmak için program. BFS (int s), s'den erişilebilen köşeleri geçer.

using namespace std;

//Graph sınıfı, bitişik liste gösterimini kullanarak yönlendirilmiş bir grafı temsil eder
class Graph
{
    int koseler;  //koseler

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    Graph(int V); //constructor

    //grafa bir kenar eklemek için fonksiyon
    void kenarEkle(int dugum, int eleman);

    //belirli bir kaynaktan bfs geçişi yazdırır
    void BFS(int s);
};

Graph::Graph(int koseler)
{
    this->koseler = koseler;
    adj = new list<int>[koseler];
}

void Graph::kenarEkle(int dugum, int eleman){

    adj[dugum].push_back(eleman); //düğüme eleman ekler
}

void Graph::BFS(int s)
{
    bool *visited = new bool[koseler];// ziyaret edilmeyen tüm köşeleri işaretler
    for(int i = 0; i < koseler; i++)
        visited[i] = false;

    list<int> queue; //bfs için bir queue oluşturma


    visited[s] = true;//geçerli düğümü ziyaret edilmiş olarak işaretler
    queue.push_back(s);

    list<int>::iterator i;//i: bir köşenin tüm bitişik köşelerini elde etmek için kullanılacaktır


    while(!queue.empty())
    {
        s = queue.front();//kuyruğa köşeyi(düğümü) ekler
        cout << s << " ";
        queue.pop_front();

        //dequeued vertex s'nin tüm bitişik köşelerini alır. ziyaret edilen düğümleri işaretler ve enqueue yapar
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    //Graph sıınıfından graf oluşturur
    Graph graf(4);
    graf.kenarEkle(0, 1);
    graf.kenarEkle(0, 2);
    graf.kenarEkle(1, 2);
    graf.kenarEkle(2, 0);
    graf.kenarEkle(2, 3);
    graf.kenarEkle(3, 3);

    graf.BFS(2);

    return 0;
}