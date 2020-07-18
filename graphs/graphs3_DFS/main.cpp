#include <iostream>
#include <vector>

using namespace std;

class Graph{
    int dugum; //köşe sayısı

    //bitişik listeler içeren bir vektörün işaretçisi
    vector < int > *adj;
public:
    Graph(int dugumSayisi); //constructor

    void kenarEkle(int dugumSayisi, int eleman);//grafa kenar ekleme fonksiyonu

    void dfs();
    void dfs_util(int s, vector < bool> &visited);
};

Graph::Graph(int dugum){
    this -> dugum = dugum;
    adj = new vector < int >[dugum];
}

void Graph::kenarEkle(int dugum, int eleman){
    adj[dugum].push_back(eleman); //listeye elemanı'yi ekler
    adj[eleman].push_back(eleman);  //dugumSayisini eleman listesine ekler (graf yönlendirilmişse bu ifadeyi kullanılmaz!)
}
void Graph::dfs(){
    //düğümleri işaretlemek için vector
    vector < bool > visited(dugum, false);  //tüm düğümleri / köşeleri ziyaret edilmemiş olarak işaretleme
    for(int i = 0; i < dugum; i++)
        if(!visited[i])
            dfs_util(i, visited);
}
// referans ile dugumler çagirilir
void Graph::dfs_util(int s, vector < bool > &visited){
    //ziyaret edilen düğüm/köşe işaretlenir
    visited[s] = true;
    cout << s << " ";//yazdırılır

    /* traverse its adjacency list and recursively call dfs_util for all of its neighbours!
    bitişiklik listesini dolaşır ve yinelemeli komşusu için dfs_util aranır*/
    for(vector < int > :: iterator itr = adj[s].begin(); itr != adj[s].end(); itr++)
        if(!visited[*itr])
            dfs_util(*itr, visited);
}

int main()
{
    //Graph sınıfı kullanılarak graf olusturulur
    Graph graf(4);
    graf.kenarEkle(0, 1);
    graf.kenarEkle(0, 2);
    graf.kenarEkle(1, 2);
    graf.kenarEkle(2, 0);
    graf.kenarEkle(2, 3);
    graf.kenarEkle(3, 3);

    graf.dfs(); // 0 1 2 3

    return 0;
}