#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Usuario
{
private:
    string name;
    string lastname;
    string id;
    string text;
    string socialWork;
    string numberAfiliater;

public:
    void setName()
    {
        cout << "Ingrese el nombre: ";
        cin >> name;
    }
    string getName()
    {
        return name;
    }

    void setLastname()
    {
        cout << "Ingrese el Apellido: ";
        cin >> lastname;
    }
    string getLastname()
    {
        return lastname;
    }

    void setId()
    {
        cout << "Ingrese el DNI: ";
        cin >> id;
        cin.ignore();
    }
    string getId()
    {
        return id;
    }

    void setText()
    {
        char result;
        cout << "Quiere agregar descripcion? s/n: ";
        cin >> result;
        cin.ignore();
            if (result == 's'){
                cout << "Ingrese el texto: ";
                getline(cin, text);
            }
    }
    string getText()
    {
        return text;
    }

    void setSocialWork()
    {
        cout << "Ingrese el nombre de la Obra social: ";
        getline(cin, socialWork);
    }
    string getSocialWork(){
        return socialWork;
    }

    void setNumberAfiliater()
    {
        cout << "Ingrese el numero de afiliado: ";
        cin >> numberAfiliater;
    }
    string getNumberAfiliater(){
        return numberAfiliater;
    }
};

ofstream Myfile("filename.txt");
string myText;
ifstream MyReadFile("filename.txt");

int main()
{
    char menuBucle = 's';
   while (menuBucle == 's')
   {
    int reply;
    cout << "Menu \n";
    cout << "1. Quieres buscar un afiliado? \n";
    cout << "2. Agregar nuevo \n";
    cout << "3. Salir \n";
    cout << "Ingrese su opcion: \n";
    cin >> reply;
    cin.ignore();

    switch (reply)
    {
    case 1:
        cout << "test caso 1 bien";
        while (getline(MyReadFile, myText)){
            cout << myText;
        }
        MyReadFile.close();
        break;
    case 2:{
            Usuario test;

            test.setName();
            test.setLastname();
            test.setId();
            test.setText();
            test.setSocialWork();
            test.setNumberAfiliater();



            cout << test.getName() << " " << test.getLastname() << " " << test.getId() << endl;
            cout << test.getText() << endl;
            cout << test.getSocialWork() << endl;
            cout << test.getNumberAfiliater() <<endl;
            Myfile << test.getName() +  test.getId() << endl;
            Myfile.close();
            }
        break;
    case 3:
        return 1;
        break;

    default:
        cout << "default";
        break;

    }


    
    cout <<"Quiere ver el menu? s/n:  \n";
    cin >> menuBucle;

    
   }
   
    return 0;
}