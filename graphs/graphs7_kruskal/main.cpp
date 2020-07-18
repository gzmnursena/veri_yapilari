#include<bits/stdc++.h>
#include <iostream>
using namespace std;

//Kruskal algoritması

// integer çifti için pair typedef oluşturma
typedef pair<int, int> iPair;

//bir graf oluşturmak için struct
struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;

    //constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    // grafa kenar eklemek için fonksiyon
    void kenarEkle(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    //kruskal'ın MST algoritmasını kullanarak mst'yi bulan fonksiyon
    int kruskalMST();
};

// Ayrık düğümleri gosteren fonksiyon
struct DisjointSets
{
    int *parent, *rnk;
    int n;

    //constructor
    DisjointSets(int n)
    {
        // bellek ayırma
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        //başlangıçta, tüm köşeler farklı düğümlerdir ve sıra 0'dır
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //her oge kendi parent'tıdır
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
       //düğümlerin üst kısmını u--> parent[u] noktasından parent[u] noktasına getirir
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        //  küçük boy bir ağaç ile ağaç yapma
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

/* Fonksiyonların  mst'nin ağırlığını döndürür*/
int Graph::kruskalMST()
{
    int mst_wt = 0; // sonucu başlatır

    //kenarları maliyet bazında artan düzende sıralar
    sort(edges.begin(), edges.end());

    //ayrık kümeler oluşturma
    DisjointSets ds(V);

    // tüm sıralanmış kenarları yineleme
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        /*seçilen kenarın bir döngü oluşturup oluşturmadığını kontrol edir
          (U ve V aynı kümeye aitse döngü oluşturulur)*/
        if (set_u != set_v)
        {
            //mevcut kenar MST'DE olacak, bu yüzden yazdırır
            cout << u << " - " << v << endl;

            // MST ağırlığını günceller
            mst_wt += it->first;

            //iki seti birleştirir
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main()
{
    //ağırlıklı ve tek yönlü graf oluşturma
    int V = 9, E = 14;
    Graph graf(V, E);

    // grafa kenarlar ekler
    graf.kenarEkle(0, 1, 4);
    graf.kenarEkle(0, 7, 8);
    graf.kenarEkle(1, 2, 8);
    graf.kenarEkle(1, 7, 11);
    graf.kenarEkle(2, 3, 7);
    graf.kenarEkle(2, 8, 2);
    graf.kenarEkle(2, 5, 4);
    graf.kenarEkle(3, 4, 9);
    graf.kenarEkle(3, 5, 14);
    graf.kenarEkle(4, 5, 10);
    graf.kenarEkle(5, 6, 2);
    graf.kenarEkle(6, 7, 1);
    graf.kenarEkle(6, 8, 6);
    graf.kenarEkle(7, 8, 7);

    cout << "MST kenarları\n";
    int mst_wt = graf.kruskalMST();

    cout << "\nMST ağırlığı= " << mst_wt;

    return 0;
}
