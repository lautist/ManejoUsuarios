#include <string>
#include <vector>
#include <iostream>
#include <fstream> //Crear archivo

using namespace std;

class Usuario //declaramos el usuario
{
private: //damos los datos que se van a pedir 
    string name;
    string lastname;
    string id;
    string text;
    string socialWork;
    string numberAfiliater;

public: //creamos sus respectivos get y set
    void setName()
    {
        cout << "Ingrese el nombre: ";
        getline(cin, name);
    }
    string getName()
    {
        return name;
    }

    void setLastname()
    {
        cout << "Ingrese el Apellido: ";
        getline(cin, lastname);
    }
    string getLastname()
    {
        return lastname;
    }

    void setId()
    {
        cout << "Ingrese el DNI: ";
        getline(cin, id);
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
        if (result == 's') //consultamos si quiere agregar una descripcion
        {
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
    string getSocialWork()
    {
        return socialWork;
    }

    void setNumberAfiliater()
    {
        cout << "Ingrese el numero de afiliado: ";
        getline(cin, numberAfiliater);
    }
    string getNumberAfiliater()
    {
        return numberAfiliater;
    }
};


int main()
{
    ofstream Myfile("filename.txt", ios::app); // Se usa ios::app para agregar al final del archivo
    string myText;
    ifstream MyReadFile("filename.txt");

    vector<Usuario> usuarios; // Vector para almacenar objetos Usuario

    char menuBucle = 's'; //manejo del bucle del menu
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
            while (getline(MyReadFile, myText))
            {
                cout << myText << "\n";
            }
            break;
        case 2:
        {
            Usuario usuario1;
            //damos inicio a la clase y la iniciamos
            usuario1.setName();
            usuario1.setLastname();
            usuario1.setId();
            usuario1.setText();
            usuario1.setSocialWork();
            usuario1.setNumberAfiliater();
            //comprobamos los datos guardados
            usuarios.push_back(usuario1);
            cout << usuario1.getName() << " " << usuario1.getLastname() << " " << usuario1.getId() << endl;
            cout << usuario1.getText() << endl;
            cout << usuario1.getSocialWork() << endl;
            cout << usuario1.getNumberAfiliater() << endl;
            Myfile << usuario1.getName() << "," << usuario1.getLastname() << "," << usuario1.getId() << "," << usuario1.getSocialWork() << "," << usuario1.getNumberAfiliater() << endl; //agregamos los datos
            
        }
        break;
        case 3:
            Myfile.close();
            return 1;
            break;

        default:
            cout << "default";
            break;
        }

        cout << "\n Quiere ver el menu? s/n:  \n";
        cin >> menuBucle;
    }

    return 0;
}