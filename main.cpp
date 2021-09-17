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
    modelo r1 = modelo();
    vector<string> vector_2= r1.lectura(); //definimos vector q gaurda todas las rutas
    vector <string> v;
    vector<string> lista2;

    //-------------------------------------------------------------------------------------------------------------
    //string buscar; cout << "ingrese la ruta a buscar "<<endl; cin>>buscar;
    //sacar todos los enrutadores que existen
    map<string,int> mapeo; //almacenar rutas y valores
    map<string,int> info; //contiene los enrutadores y las conexiones uqe hay desde estos
    int numVertices = 0;
    for(int j = 0; j < vector_2.size(); j ++){
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
                for(int k = 0 ; k < vector_2.size(); k++){
                    char aux3 = vector_2.at(k)[0];
                    string aux4; aux4.push_back(aux3);
                    if(aux4 == aux2){
                        numVertices+=1;
                    }
                }
                info[aux2] = numVertices;
                numVertices = 0;
            }
    }
    //---------------------------------------------------intento ( 2) del 17/09/21------------------------------------




    //---------------------------------------------------intento (1) del 16/09/21-------------------------------------
    /*
    //empezamos a construir las rutas
   string ruter = "A";  //como ejemplo con A
   for (auto r : info) {
       //si viene a el mismo , es 0
       if( r.first == ruter){
           mapeo[r.first] = 0 ;
       }
       else{ //es otro
   vector<string> rutas_analizar;
   vector <string > nodos_analizados;
   nodos_analizados.push_back(ruter);
   string ruta = ruter;
   while( nodos_analizados.size() != info.size() ){
       //desde donde estamos, buscamos los caminos que hay
       int aux= ruta.length();
       char aux3 = ruta[aux];
       string aux4; aux4.push_back(aux3);
       int aux5 = info[aux4]; //almacena los caminos del ultimo nodo en ruta
       vector<string> caminos;
       while(aux5 > 0){
           //guardamos los caminos
           for(int l = 0; l < vector_2.size(); l++){
               char a = vector_2.at(l)[0];
               string a1; a1.push_back(a);
               if(a1 == aux4){
                   caminos.push_back(vector_2.at(l));
                   char a2 = vector_2.at(l)[1];
                   string a3; a3.push_back(a2);
                   nodos_analizados.push_back(a3);
                   aux -= 1;
               }
           }
       }
       for(auto i : caminos){

       }

       char a = vector_2.at(l)[0];
       string a1; a1.push_back(a); //primera posicion de la conexion
       if(a1 == aux4){ // es un camino
           char a2 = vector_2.at(l)[1];
           string a3; a3.push_back(a2); //aca es el nodo donde llegamos
           //verificamos que no lo haya recorrido ya
           bool repetir = false;
           for (auto nodo : nodos_analizados) {
               if(nodo == a3){
                   repetir = true;
               }
           }
           if(!repetir){
           //llegue
           if(a3 == r.first){
               string new_ruta = ruta;
           }
           //aun no haya llegado
           else{

           }
           }

   }
   }
   }}*/
   //------------------------------------------------------------------------------------------------------------------
    /*
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
        //almacenar las rutas - como caminos que ya paso para no repetir y asi ir sacando
        //almacenar los posibles cmainos de cada una de los enrutadores

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
*/
    return 0;
}


