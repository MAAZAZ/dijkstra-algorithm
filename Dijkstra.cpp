/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ///
///                                           Recherche Opérationnelle                                                        ///
///                                           MINI-PROJET: Algorithme de Dijksra                                              ///
///                                           Réalisé par :  - MAAZAZ ZAKARIA                                                 ///
///                                                          - ELKAMA ANASS                                                   ///
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ///


#include <iostream>

using namespace std;

/// les prototypes
void afficherGraphe(int[50][50],int);
void lectureGrapheValue(int[50][50],int[50][50],int);
void dijkstra(int [][50],int [][50],int &);
int val_tab(int [][50],int &,int &,int &);
int minum(int [],int &);

/// main
int main()
{
    int n=0; /// Nombre de sommets
    int t[50][50]; /// la matrice d'adjacence
    int arcs[50][50]; /// valeurs des arcs

    cout<<endl<<"Tapez le nombre de sommets : ";
    cin>>n;

    /// Lecture
    lectureGrapheValue(t,arcs,n);
    /// Affichage
    afficherGraphe(t,n);
    /// Algorithme de Dijkstra
    dijkstra(t,arcs,n);


    return 0;
}

/// afficher le graphe sous forme d'un matrice adjacence
void afficherGraphe(int t[50][50],int n){

    cout<<endl<<"La matrice d'Adjacence :"<<endl;
    cout<<endl;
    cout<<"  ";
    for(int i=1;i<=n;i++)
        cout<<i<<" ";
        cout<<endl;
    cout<<"  ";
    for(int i=1;i<=n;i++)
    cout<<"_"<<" ";
    cout<<endl;

    for(int i=1;i<=n;i++){
    cout<<i<<"|";
        for(int j=1;j<=n;j++){
            cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }

}

/// demande au utilisateur de taper les informations de graphe
void lectureGrapheValue(int t[50][50],int c[50][50],int n){
        int nb;
        int p;
        int val;

        /* initialiser tous les ... à 0*/
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        t[i][j]= 0; // initialisé par 0 c'est à dire pas de arc entre deux sommets
        c[i][j]= 0; // initialisé par 0
        }
        }

        for(int i=1;i<=n;i++){
        cout<<"Nombre de successeurs du sommet de "<<i<<" ? ";
        cin>>nb;
        for(int j=1;j<=nb;j++)
            {
                    cout<<endl<<"Donnez le successeur Numero "<<(j)<<" de sommet "<<i<<" ? ";
                    cin>>p;
                    for(int k=1;k<=n;k++)
                        if(k==p)
                          t[i][k]=1; // matrice d'adjacence
                    cout<<"Valeur de l'arc : ("<<i<<","<<p<<") ? ";
                    cin>>val;
                    for(int k=1;k<=n;k++)
                        if(k==p)
                         c[i][k]=val; //remplir les valeurs des arcs
            }
        }
}

/// Algorithme de Dijkstra
void dijkstra(int t[][50],int arcs[][50],int &n){

int Noued[n],x[n];
int i,j;
int cpt=1;
int s[n];
int tr=0;
int debut=0;
int p,m,minn,mnn;
for(int i=0;i<=n;i++)
    s[i]=0;

for(i=1;i<=n;i++){
       tr=0;
       for(int f=1;f<=n;f++)
        x[f]=val_tab(arcs,n,i,f);
        minn=9999; //infinite
        for(j=1;j<=n;j++){
        if( i!=j && t[i][j]==1 )
        {
            if(x[j] <= minn ){
            minn=x[j];
            m=j;
            tr=1; /// existe un chemin ou non
            }
        }
        }
         if(tr==1){
         s[cpt]=m;
         cpt++;
         //cout<<debut<<" ";
         debut=debut+minn;
         for(p=1;p<=n;p++)
          t[p][j]=0; // pour ne pas assez a la meme sommet a la deuxieme fois
         }
}
/*
/// la valeur du plus court chemin
cout<<"\n --> La valeur minimal : "<<debut<<endl;
*/
/// le trajet
cout<<"\n --> Le chemin minimal : 1 ";
for(i=1;i<cpt-1;i++)
cout<<s[i]<<" ";
if(s[i]!=n)
    cout<<n;
}

/// retourner une valeur au tableau
int val_tab(int c[][50],int &n,int &i,int &j)
{
    return c[i][j];
}

/// retourner le minimum d'un tableau d'un seul dimension
int minum(int t[],int &n){
    int minum=1000;
    for(int i=1;i<=n;i++)
        if (minum>t[i])
        minum=t[i];

    return minum;
}
