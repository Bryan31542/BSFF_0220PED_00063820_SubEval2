#include <iostream>
#include <stack>

using namespace std; 

struct plato{

    string material;
    string color;
    string estado;
};
typedef struct plato Plato;

int main(){

    stack <Plato> limpio;
    stack <Plato> sucio;

    int n;
    string material, color;
    bool estado = true;

    cout << "\nIngrese la cantidad de platos que tiene a su dispocision: ";
    cin >> n;

    int a[n];

    cout << endl;
    cin.ignore();

    for (int i = 0; i < n; i++){

        Plato unPlato;

        cout << "Ingrese el material de su plato: ";
        getline(cin, unPlato.material);

        cout << "Ingrese el color de su plato: ";
        getline(cin, unPlato.color);

        limpio.push(unPlato);

        cout << endl;

    }

    int option;
    bool status = true;

    while(status){

        cout << "\tPilas de platos" << endl << endl;
        cout << "Opciones: " << endl;
        cout << "1. Ensuciar un plato" << endl;
        cout << "2. Ensuciar N platos" << endl;
        cout << "3. Limpiar un plato" << endl;
        cout << "4. Limpiar N plato" << endl;
        cout << "5. Mostrar pila limpia" << endl;
        cout << "6. Mostrar pila sucia" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese su opcion: "; cin >> option;

        switch (option){

            case 1:

                char c;
                cout << "\nSi quieres ensuciar un plato ingresa (S): ";
                cin >> c;

                if(c == 'S' || c == 's'){

                    Plato platoEncima;

                    platoEncima = limpio.top();
                    limpio.pop();
                    sucio.push(platoEncima);

                }

                break;

            case 2:
            {
                int m;
                cout << "\nIngrese la cantidad de platos que desea ensuciar: ";
                cin >> m;
                cout << endl;

                Plato plate;

                for (int i = 0; i < m; i++){

                    plate = limpio.top();
                    limpio.pop();
                    sucio.push(plate);

                }
                break;
            }
            case 3:
            {

                char c;
                cout << "\nSi quieres limpiar un plato ingresa (S): ";
                cin >> c;

                if(c == 'S' || c == 's'){

                    Plato platoEncima;

                    platoEncima = sucio.top();
                    sucio.pop();
                    limpio.push(platoEncima);

                }
                break;
            }
            case 4:
            {
                int o;
                cout << "\nIngrese la cantidad de platos que desea limpiar: ";
                cin >> o;
                cout << endl;

                Plato plat;

                for (int i = 0; i < o; i++){

                plat = sucio.top();
                sucio.pop();
                limpio.push(plat);

                }
                break;
            }
            case 5:
            {
                Plato pl = limpio.top();
            
                cout << endl;
                while (!limpio.empty()) { 

                cout << "Material y color: " << pl.material << ", ";
                cout << pl.color << endl << endl;

                limpio.pop(); 

                }
                break;
            }
            case 6:
            {
                Plato p = sucio.top();

                cout << endl;
                while (!sucio.empty()) { 
                
                cout << "Material y color: "<<p.material << ", "; 
                cout << p.color << endl << endl;

                sucio.pop(); 

                }
                break;
            }
            case 7:

                status = false;

                break;

            default:
                break;

        }
    }

    return 0;
}