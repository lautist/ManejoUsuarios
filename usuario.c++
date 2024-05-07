#include <string>
#include <vector>
#include <iostream>
#include <fstream> //Crear archivo
#include <sstream> //Para dividir lineas por comas

using namespace std;

class Usuario // declaramos el usuario
{
private: // damos los datos que se van a pedir
    string name;
    string lastname;
    string id;
    string text;
    string socialWork;
    string numberAfiliater;

public: // creamos sus respectivos get y set
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
        cin.ignore();
        if (result == 's') // consultamos si quiere agregar una descripcion
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

    char menuBucle = 's'; // manejo del bucle del menu
    while (menuBucle == 's')
    {
        int reply;
        cout << "Menu \n";
        cout << "1. Listado de pacientes? \n";
        cout << "2. Agregar nuevo \n";
        cout << "3. Buscar pacientes \n";
        cout << "4. Modificar pacientes? \n";
        cout << "5. Eliminar pacientes \n";
        cout << "6. Salir \n";
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
            // damos inicio a la clase y la iniciamos
            usuario1.setName();
            usuario1.setLastname();
            usuario1.setId();
            usuario1.setText();
            usuario1.setSocialWork();
            usuario1.setNumberAfiliater();
            // comprobamos los datos guardados
            usuarios.push_back(usuario1);
            cout << usuario1.getName() << " " << usuario1.getLastname() << " " << usuario1.getId() << endl;
            cout << usuario1.getText() << endl;
            cout << usuario1.getSocialWork() << endl;
            cout << usuario1.getNumberAfiliater() << endl;
            Myfile << usuario1.getName() << "," << usuario1.getLastname() << "," << usuario1.getId() << "," << usuario1.getSocialWork() << "," << usuario1.getNumberAfiliater() << endl; // agregamos los datos
        }
        break;
        case 3:
        {
            string searchId;
            cout << "Ingrese el DNI a buscar: "; // solicitamos el usuario
            getline(cin, searchId);

            bool found = false;
            while (getline(MyReadFile, myText)) // bucle para buscar
            {
                stringstream ss(myText); // se divide cada linea en partes
                string item;
                vector<string> items;
                while (getline(ss, item, ','))
                {
                    items.push_back(item);
                }
                if (items.size() >= 3 && items[2] == searchId)
                {
                    found = true;
                    cout << "Usuario encontrado\n";
                    cout << "Nombre: " << items[0] << endl;
                    cout << "Apellido: " << items[1] << endl;
                    cout << "DNI: " << items[2] << endl;
                    cout << "Obra social: " << items[3] << endl;
                    cout << "Numero de afiliado: " << items[4] << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "No se encontro ningun usuario con el DNI ingresado.\n";
            }
            MyReadFile.clear();
            MyReadFile.seekg(0, ios::beg); // Reiniciar la lectura del archivo al inicio
            break;
        }
        case 4:
        {
            string searchId;
            cout << "Ingrese el DNI a buscar: ";
            getline(cin, searchId);

            bool found = false;
            vector<string> fileContents; // Vector para almacenar las líneas del archivo

            // Leer el archivo y almacenar las líneas en fileContents
            while (getline(MyReadFile, myText))
            {
                fileContents.push_back(myText);
            }

            // Buscar el usuario por DNI
            for (size_t i = 0; i < fileContents.size(); ++i)
            {
                stringstream ss(fileContents[i]);
                string item;
                vector<string> items;
                while (getline(ss, item, ','))
                {
                    items.push_back(item);
                }
                if (items.size() >= 3 && items[2] == searchId)
                {
                    found = true;
                    int result;
                    cout << "Usuario encontrado " << items[0] << " " << items[1];
                    cout << "Que dato quieres modificar \n";
                    cout << "1. Nombre \n";
                    cout << "2. Apellido \n";
                    cout << "3. DNI \n";
                    cout << "4. Obra Social \n";
                    cout << "5. Numero de afiliado \n";
                    cout << "Selecciona la opcion: \n";
                    cin >> result;
                    cin.ignore();

                    // Modificar el dato correspondiente
                    switch (result)
                    {
                    case 1:
                        cout << "Ingrese el nuevo nombre: ";
                        getline(cin, items[0]); // Modificar el nombre
                        break;
                    case 2:
                        cout << "Ingrese el nuevo apellido: ";
                        getline(cin, items[1]); // Modificar el apellido
                        break;
                    case 3:
                        cout << "Ingrese el nuevo DNI: ";
                        getline(cin, items[2]); // Modificar el DNI
                        break;
                    case 4:
                        cout << "Ingrese la nueva obra social: ";
                        getline(cin, items[3]); // Modificar la obra social
                        break;
                    case 5:
                        cout << "Ingrese el nuevo número de afiliado: ";
                        getline(cin, items[4]); // Modificar el número de afiliado
                        break;
                    default:
                        cout << "Opción no válida";
                        break;
                    }

                    // Actualizar la línea en el archivo
                    fileContents[i] = items[0] + "," + items[1] + "," + items[2] + "," + items[3] + "," + items[4];
                    break;
                }
            }

            if (!found)
            {
                cout << "No se encontró ningún usuario con el DNI ingresado.\n";
            }

            // Sobrescribir el archivo con las líneas actualizadas
            MyReadFile.close();
            ofstream MyWriteFile("filename.txt");
            for (const string &line : fileContents)
            {
                MyWriteFile << line << endl;
            }
            MyWriteFile.close();

            // Abrir el archivo nuevamente para leer desde el principio
            MyReadFile.open("filename.txt");
            break;
        }

        default:
            cout << "default";
            break;
        }

        cout << "\n Quiere ver el menu? s/n:  \n";
        cin >> menuBucle;
    }

    return 0;
}
