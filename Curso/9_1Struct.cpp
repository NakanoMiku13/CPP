#include<bits/stdc++.h>
using namespace std;
struct Alumno{
    string Nombre;
    int edad,id;
    float altura;
};
auto ingresaAlumno(auto id)->Alumno{
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
    for(auto i:data){
        cout<<"Alumnos NO: "<<i.id<<"\nNombre: "<<i.Nombre<<"\nEdad: "<<i.edad<<"\nAltura: "<<i.altura<<endl<<endl;
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