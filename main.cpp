#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
class enrutador{
private:
    char lista_conexion [7]={'A','B','C','D','E','F','G'};
    char lista_valores[7];
public:
    enrutador(); // constructor vacio
    void definir_conexiones();
    void mostar_conexiones();
};
enrutador::enrutador(){

}
void enrutador::definir_conexiones(){
   cout << "ingrese los valores de las conexiones mostradas, si no hay ponga '-' "<<endl;
   cout << "ingrese . para finalizar"<<endl;
   string ingreso ;
   for (int i = 0; i < 8 ; i++ ) {
       cout << lista_conexion[i]<<endl;
   }

}
*/
class enrutador{
    string conexion;
    int valor;
};
int caminos_t(string ruta,vector<string>v){
    int retorno=0;
    for(int i = 0; i < v.size() ; i++){ //cuantos caminos hay
        if(v.at(i)[0] == ruta[1] && v.at(i)[0] != ruta[0] ){
           retorno+=1;
        }
    }
    return retorno;
}
int main(){
    //entra en una tabla , ASI:
    //   | A | B | C | D |
    // A | 0 | 4 | 10| - |
    //'A','B','C','D','E','F','G'
    //"A","B","C","D","E","F","G"
    string a = "";
    vector<string> vector_2; //definimos vector q gaurda todas las rutas
    vector <string> v;
    cout <<"ingrese la conexion y su costo asi (AB,1)"<<endl<<"ingrese . para acabar"<<endl;
    for (int i  =0 ; i <  25 ; i++ ) {
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
    /*
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
