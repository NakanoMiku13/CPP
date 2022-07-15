#include<bits/stdc++.h>
using namespace std;
struct Alumno{
    string Nombre;
    int edad,id;
    float altura;
};
auto ingresaAlumno(int id)->Alumno{
    string nombre;
    int edad;
    float altura;
    cout<<"Ingresa nombre, edad y altura:"<<endl;
    cin>>nombre>>edad>>altura;
    Alumno tmp = {nombre,edad,id,altura};
    return tmp;
}
auto imprimirAlumnos(auto data){
    cout<<"Estos son los alumnos registrados."<<endl;
    for(auto i=0;i<data.size();i++){
        Alumno alumnoN = data[i];
        cout<<alumnoN.id;
    }
}
auto main()->int{
    vector<Alumno> alumnos;
    int n;
    cout<<"Cuantos alumnos desea ingresar?"<<endl;
    cin>>n;
    for(auto i=0;i<n;i++) alumnos.push_back(ingresaAlumno(i));
    imprimirAlumnos(alumnos);
}