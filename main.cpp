/*
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver program to test above function
int main()
{

    Let us create the example graph discussed above
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}
*/
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include<map>
using namespace std;


class enrutador{
private:
    string V ;
    map<string,int> mapa_conexiones;
public:
    enrutador(string); // constructor vacio
    void agg_el_coneccion(string);
    void actualizar();

};
class modelo{
private:
    vector<enrutador> modelamiento;
public:
    modelo();
    vector<string> lectura();
    vector<string> escritura();
    void envio(string , string);
    void agg_el_enrutador(string);
};
enrutador::enrutador(string _v){
    V = _v;
}
modelo::modelo(){

}
vector<string>modelo::lectura(){
    vector<string> vector_2;
    ifstream data;
    string texto;
    data.open("../enrutadores/BD/conections.txt",ios::in); //modo lectura
    if(data.fail()  == true){
        cout <<"no se pudo abrir"<<endl;
        exit(1);
    }
    while(!data.eof()){
        getline(data,texto);
        cout << texto <<endl;
        vector_2.push_back(texto);
    }
    data.close(); // cerramos
    return vector_2;
}
vector<string>modelo::escritura(){
    vector<string> vector_2;
    string a = "";
    cout <<"ingrese la conexion y su costo asi (AB,1)"<<endl<<"ingrese . para acabar"<<endl;
    for (int i  =0 ; i <  49; i++ ) {
        string a; cin >> a;
        if(a == "."){
            break;
        }
        else{

            vector_2.push_back(a);
        }
    }
    return vector_2;
}
int main(){
    //entra en una tabla , ASI:
    //   | A | B | C | D |
    // A | 0 | 4 | 10| - |
    //'A','B','C','D','E','F','G'
    //"A","B","C","D","E","F","G"
    string variable = "A";
    modelo r1 = modelo();
    vector<string> vector_2= r1.lectura(); //definimos vector q gaurda todas las rutas
    vector <string> v;
    vector<string> lista2;
    //ingreso manual

    string a = "";

    cout <<"ingrese la conexion y su costo asi (AB,1)"<<endl<<"ingrese . para acabar"<<endl;
    for (int i  =0 ; i <  49; i++ ) {
        string a; cin >> a;
        if(a == "."){
            break;
        }
        else{

            vector_2.push_back(a);
        }
    }
    string buscar; cout << "ingrese la ruta a buscar "<<endl; cin>>buscar;
    vector<string> r_; //contener las rutas de llegada
    for(int p = 0; p < vector_2.size() ; p++){
        if(vector_2.at(p)[1] == buscar[1] ){ //ruats de llegada
        cout << vector_2.at(p)[0]<<" posicion:"<<p<<endl;
        r_.push_back(vector_2[p]);
        }
    }
    //sacar todos los enrutadores que existen

    for(int j = 0; j < vector_2.size(); j ++){
        if(lista2.empty() == true){
            char aux1 = vector_2.at(j)[0];
            string aux2; aux2.push_back(aux1);
            lista2.push_back(aux2);
        }
        else{
            bool repetido = false;
            char aux1 = vector_2.at(j)[0];
            string aux2; aux2.push_back(aux1);
            //buscamos si el elemento esta ya en lalista
            for (int i = 0; i < lista2.size(); i++) {
                string _letra = lista2[i];
                if(_letra == aux2 ) {
                repetido = true;
                break;
              }
            }
            if(!repetido){ //si no esta lo agregamos
                lista2.push_back(aux2);
            }
        }
    }
    //-------------------------------------------------------------metod 3-----------------------------------------
    //--------------------------------------------------------------------------------------------------------------





 //--------------------------------------------------------------metodo 2-------------------------------------------------
 //---------------------------------------------------------------------------------------------------------------------

    //empezamos a buscar los caminos
    string enrutador = "A"; //ejemplo con el nrutador A
    list<string> lista;
    for(int i = 0; i  < lista2.size(); i++){
        char aux0 = lista2.at(i)[0];
        string aux; aux.push_back(aux0);
        if(aux == enrutador){ //para ir de enrutador hacia el mismo
            //lista2.insert(i,"0");
        }
        else{
            for(int J = 0; J  < vector_2.size(); J++){
                char aux1 = vector_2.at(J)[0];
                string aux2; aux2.push_back(aux1);
                //vamos a  las aristas de "enrutador"
                if( aux2 == enrutador){
                    char conexion = vector_2.at(J)[1];
                    string conection; conection.push_back(conexion);
                    //buscamos la posicion de conection
                    int index;
                    for(int i = 0; i  < lista2.size(); i++){
                        string aux3 = lista2.at(i);
                        if(aux3 == conection){
                            index = i;
                            break;
                        }
                    }
                    //cogemos el valor
                    string cadena = vector_2.at(J);
                    int start = cadena.find(",")+1;
                    int finish = cadena.length();
                    string valor;
                    while(start != finish){
                        valor+= cadena[start];
                        start++;
                    }
                    cout << conection <<"en la lista:" <<index<<" valor: " <<valor<<endl;
                    //lo agregamos a la lista
                }


            }

        }

    }

//----------------------------------------------------------------metodo1----------------------------------------------------------------------------------
//falla: solo pude recorrer una vez cada posible camino ( ejm B -> D : Rutas ( DAB , DEB) : rutas totales ( DAB,DACB,DEB)
//--------------------------------------------------------------------------------------------------------------------------------------------------------

    //luego vamos a hacer un ciclo anidado para las rutas
    for(int p = 0; p < vector_2.size() ; p++){
        string ruta="";
        if(vector_2.at(p)[0] == buscar[0] ){
            //empieza la ruta
            ruta+= vector_2.at(p)[0];
            //preguntamos si tiene conexion directa a la llegada ( para rutas tipo AB )
            if(vector_2.at(p)[1] == buscar[1]){
                ruta+=vector_2.at(p)[1];
            }
            else{ //si no vamos a buscar si tienne conexion a alguna llegada ( rutas derechas (ACB )
                bool finsish = false;
                ruta+=vector_2.at(p)[1];
            for(int a = 0; a < v.size() ; a++){
                if(ruta[1]  == v.at(a)[0]){
                   ruta+= v.at(a)[1];
                   finsish = true;
                  break;
                }
            }
            if(!finsish){ //vamos a buscar si desde el punto tiene conexion a alguna llegada (rutas mas largas ACBE )
                for(int b = 0; b < vector_2.size() ; b++){
                    if(vector_2.at(b)[0] == ruta[1] && vector_2.at(b)[1] != ruta[0] ){
                        ruta+= vector_2.at(b)[1];
                        for(int a = 0; a < v.size() ; a++){
                            if(vector_2.at(b)[1]  == v.at(a)[0]){
                               ruta+= v.at(a)[1];
                               finsish = true;
                               break;
                            }
                        }

                    }
                }

            }
            }

        }
        cout << "ruta:"<<ruta<<endl;
    }

//-----------------------------------------------------------------------metodo 2---------------------------------------------------------------------------

    //definimos la ruta
    vector<string> caminos;
    string ruta="";
    int rutas = 0;
    for(int i = 0; i < vector_2.size() ; i++){ //cuantos caminos hay
        if(vector_2.at(i)[0] == buscar[0] ){
            ruta+=buscar[0];
           //buscamos la cantidad de caminos
            for(int aux = 0; aux < vector_2.size();aux++){
                if(vector_2.at(aux)[0]==buscar[0]){
                    rutas+=1;
                    //por cada posible ruta agregamos un componente en "caminos"
                    caminos.push_back(ruta);
                }
            }

        }
    }
    //ahora agregamnos la ruta
    while(rutas > 0 ){
        for(int aux = 0; aux < vector_2.size();aux++){
            if(vector_2.at(aux)[0]==buscar[0]){
                caminos[rutas]+= vector_2.at(aux)[1];
                cout <<":"<<caminos[rutas]<<endl;
            }
        }
        rutas-=1;
    }
    //buscar por cada camino las rutas q hay

    return 0;
}


