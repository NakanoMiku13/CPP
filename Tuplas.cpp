#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
vector<string> attributeNames;
int id=1;
auto convertToNumber(string value)->int{
    int result=0;
    stringstream geek(value);
    geek>>result;
    return result;
}
string aps[]={
    "Garcia",
    "Rodriguez",
    "Gonzalez",
    "Fernandez",
    "Lopez",
    "Martinez",
    "Perez",
    "Gomez",
    "Martin",
    "Jimenez",
    "Ruiz",
    "Diaz",
    "Moreno",
    "Alvarez",
    "Ulrich",
    "Alonso",
    "Sanchez",
    "Vanegas"
};
string Names[]={
"Adel",
"Adonis",
"Lier",
"Lionel",
"Lisandro",
"Lucian",
"Mael",
"Misael",
"Moad",
"Munir",
"Nael",
"Najim",
"Neo",
"Neil",
"Nikita",
"Nilo",
"Otto",
"Pep",
"Policarpo",
"Radu",
"Ramses",
"Romulo",
"Roy",
"Severo",
"Sidi",
"Simeon","Taha","Tao","Vadim","Vincenzo","Zaid","Zigor","Zouhair",
"Abril",
"Adela",
"Adelaida",
"Adriana",
"Agueda",
"Aida",
"Esmeralda",
"Estefania",
"Estela",
"Ester",
"Eva",
"Fatima",
"Francisca",
"Gabriela",
"Gaia",
"Gala",
"Gema",
"Genesis",
"Gloria",
"Greta",
"Guadalupe",
"Ingrid",
"Inma",
"Irati",
"Iris",
"Isabel",
"Sofia",
"Sol",
"Soledad",
"Sonia",
"Susana",
"Tania",
"Tatiana",
"Telma",
"Teresa",
"Triana",
"Trini",
"Úrsula",
"Uxia",
"Valentina",
"Valeria","Erandi","Adriana","Andrea"
};
auto setBlock(auto section)->string{
    int n = section.size(),i=0;
    string result="";
    string attributeName="";
    while(section[i]!=' '){
        attributeName+=section[i];
        i++;
    }
    attributeNames.push_back(attributeName);
    string dataType ="";
    i++;
    while(section[i]!=' '){
        dataType+=section[i];
        i++;
    }
    string Domain="";
    i++;
    while(section[i]!=' ' and i<n){
        Domain+=section[i];
        i++;
    }
        i=0;
        string type = "",capacity="";
        if(dataType!="int" or dataType!="float"){
            while(dataType[i]!='(') i++;
            while(dataType[i]!=')') { capacity+=dataType[i]; i++;}
            int capacities = convertToNumber(capacity);
        }else{
            type = dataType;
        }
        if(Domain=="id" or (Domain[1]=='i' and Domain[2]=='d')){
            stringstream ss;
            ss<<id;
            id++;
            string ids="";
            ss>>ids;
            result+=ids;
            cout<<ids<<endl;
            result+=',';
        }else
        if(Domain[1]=='N' and Domain[2]=='2'){
            result+="'";
            result+=aps[rand()%18];
            result+="',";
        }
        else if(Domain!="(N1)"){
            if(dataType!="int" and dataType!="float"){
                vector<string> values;
                i=1;
                string val="";
                while(i<Domain.size()-1){
                    if(Domain[i]!='_'){
                        val+=Domain[i];
                    }else{
                        values.push_back(val);
                        val="";
                    }
                    i++;
                }
                int ran = rand()%values.size()+1;
                result+="'";
                result+=values[ran];
                result+="',";
            }else{
                int ini=0,end=0;
                i=1;
                string num="";
                while(Domain[i]!='_') {num+=Domain[i]; i++;}
                ini = convertToNumber(num);
                num="";
                i++;
                while(i<Domain.size()){
                    num+=Domain[i];
                    i++;
                }
                end=convertToNumber(num);
                num="";
                stringstream ss;
                int rr=ini+(rand()%(end-ini+1));
                cout<<rr<<endl;
                ss<<rr;
                ss>>num;
                result+=num;
                result+=",";
            }
        }else{
            result+="'";
            result+=Names[rand()%77];
            result+="',";
        }
    return result;
}
auto readCommand(string command)->string{
    auto n = command.size();
    vector<string> fullcommands;
    string result="";
    for(auto i=0;i<n;i++){
        if(command[i]!=','){
            string section="";
            while(command[i]!=',' and i<=n){ section+=command[i]; i++;}
            fullcommands.push_back(setBlock(section));
        }
    }
    for(auto i:fullcommands) result+=i;
    string correction="";
    int x =result.size()-1;
    for(auto i=0;i<x;i++) correction+=result[i];
    return correction;
}
auto command(auto procedureName,auto nomEsq,const auto cant)->list<string>{
    list<string> tupples;
    cout<<"Ingresa el orden correcto de atributos, nombre de atributo y tipo de dato\n";
    cout<<"Ejemplo:\nidPersona int (id),Nombre char(50) (N1),ApPat char(50) (N2),ApMat char(50) (N2),genero char(5) (m_h_o),edad int (0_40)\n";
    cout<<"NO PONER ESPACIOS ANTES O DESPUES DE CADA COMA\n";
    cout<<"Si ocupas identificadores para tus tuplas, solo coloca ID en el dominio\n";
    cout<<"Empieza por el nombre del atributo; tipo de dato, en caso de necesitar longitud, colocarla seguida sin espacios entre parentesis\n";
    cout<<"Despues especificar el dominio (en caso de los nombres y apellidos esta definido por N1 para nombres y N2 Apellidos) entre parentesis el dominio y tomara un valor aleatorio de lo que coloques, cada dominio o posible valor, ira con guion bajo\n";
    cout<<"en caso de char, sera alguna de las palabras o letras antes de cada guion bajo, en el caso de enteros o similares, tomara el rango entre X y Y\n";
    cout<<"El resultado como ejemplo es\n";
    cout<<"call InsertIntoEmployee('Jhon','Doe','Marquez','m',29)\n\n\n";
    getchar();
    string commands;
    getline(cin,commands);
    if(procedureName.size()>0){
        for(auto i=0;i<cant;i++){
            string x = "call ";
            x+=procedureName;
            x+="(";
            x+=readCommand(commands);
            x+=");";
            tupples.push_back(x);
        }
    }else{
        string x = "insert into ",y=readCommand(commands), z="",zp="";
        x+=nomEsq;
        x+="(";
        for(auto i:attributeNames) {z+=i; z+=",";};
        int zSize = z.size()-1;
        for(auto i=0;i<zSize;i++) zp+=z[i];
        x+=zp;
        x+=") values (";
        x+=y;
        if(cant>1) x+="),";
        else x+=");";
        for(auto i=0;i<cant;i++){
            x+="(";
            y=readCommand(commands);
            x+=y;
            x+="),";
        }
        x[x.size()-1]=';';
        tupples.push_back(x);
    }
    return tupples;
}
auto main()->int{
    srand (time(NULL));
    cout<<"Cuantas tuplas?\n";
    int cantTuplas;
    cin>>cantTuplas;
    cout<<"Nombre del esquema\n";
    string nomEsq;
    cin>>nomEsq;
    system("cls");
    int x;
    cout<<"Tienes procedimiento almacenado?\nSi (1) No (2)\n";
    cin>>x;
    list<string> lista;
    if(x==1){
        cout<<"Inserta el nombre del procedimiento\n";
        string procedure;
        cin>>procedure;
        system("cls");
        lista = command(procedure,nomEsq,cantTuplas);
    }else{
        string xd="";
        lista = command(xd,nomEsq,cantTuplas);
    }
    ofstream file;
    file.open("tuplas.txt",ios::out);
    cout<<"dnd\n"; 
    if(file.fail()){
        cout<<"ERROR GUARDANDO ARCHIVO\n Imprimiendo tuplas...\n";
        for(auto i:lista){
            cout<<i<<endl;
        }
    }else{
        for(auto i:lista){
            file<<i<<endl;
        }
        file.close();
        for(auto i:lista){
            cout<<i<<endl;
        }
    }
    system("pause");
    return 0;
}