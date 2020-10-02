#include <iostream>

using namespace std;

struct Suelo {

    string tipo;
    float grosor;
    int dureza;

};
typedef struct Suelo suelo;

struct Node {

    suelo element;
    struct Node *next;

};
typedef struct Node *Stack;

void initiliaze(Stack *);
bool empty(Stack *);
void push(Stack *, suelo e);
suelo pop(Stack *s);
suelo top(Stack *s);
void promedio(Stack *s);

int main (){

    Stack stack;

    initiliaze(&stack);

    bool status = true;
    int opcion;

    cout << endl;
    while (status){

        cout << "\t Menu Litologico" << endl << endl;
        cout << "1. Agregar capa" << endl;
        cout << "2. Borrar ultima capa" << endl;
        cout << "3. Eliminar todas las capas ingresadas" << endl;
        cout << "4. Obtener promedio de durezas" << endl;
        cout << "5. Salir" << endl;;
        cout << "\nIngrese su opcion: "; 

        cin >> opcion;

        switch (opcion){

            case 1: 
                
                char c;
                cout << "\nSi desea ingresar una capa digite (S): ";
                cin >> c;
                
                cin.ignore();

                if (c == 's'|| c == 'S'){

                    suelo unSuelo;
                    
                    cout << "\nIngrese el Tipo de Suelo: ";
                    getline(cin, unSuelo.tipo);

                    do{
                    cout << "Ingrese el grosor del suelo: ";
                    cin >> unSuelo.grosor;
                    }while (unSuelo.grosor <= 0);
                    
                    do{
                    cout << "Ingrese la dureza del suelo: ";
                    cin >> unSuelo.dureza;

                    }while(unSuelo.dureza <= 0);
                }
                cout << endl;
                break;
                
            case 2: 
            {
                if(!empty(&stack)){

                cout << "\nEliminando ultima capa... " << endl << endl;

                }
                else {

                    cout << "\nError Underflow" << endl << endl;

                }

                pop(&stack); 
                break;

            }
            case 3: 
            {
                while(!empty(&stack)){

                    if(!empty(&stack)){
                    cout << "Eliminando todas las capas...  " << endl << endl;
                    }
                    else{

                        cout << "\nError Underflow" << endl << endl;

                    }

                    pop(&stack);

                }
                cout << "\nTodas las capas eliminadas con exito" << endl;
                break;
            }
            case 4: 
            {
                promedio(&stack);
            }

            case 5: 
            {
                status = false;
                break;
            }

        }
    
    }

    return 0;
}

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, suelo e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

suelo pop(Stack *s){
    if(!empty(s)){
        struct Node *unNodo = *s;
        suelo e = (*s) -> element;
        *s = (*s) -> next;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return {{" "},-1,-1};
}

suelo top(Stack *s){
    if(!empty(s))
        return (*s)->element;

    else // Underflow!
        return {{" "},-1,-1};
}

void promedio(Stack *s){

    int suma = 0;
    int prom = 0;
    int cont = 0;

    Stack *clone = s;
    while(!empty(clone)){

        suma += top(clone).dureza;
        
        pop(clone);
        cont ++;

    }

    prom = suma / cont;

    cout << "El promedio de la dureza es: " << prom << endl << endl;

}