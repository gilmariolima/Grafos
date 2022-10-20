#include <iostream>
#include <string>
#include <vector>

#define VERMELHO "\x1b[31m"
#define VERDE "\x1b[32m"
#define ROXO "\x1b[34m"
#define AMARELO "\x1b[33m"
#define RESET "\x1b[0m"

using namespace std;

class vertice{
    private:
        int lable;
        string cor;
        int d;
        int f;
        string nome_seta1;
        string nome_seta2;
        string nome_seta3;
    public:
        vertice(int lable, string cor, int d, int f){
            set_lable(lable);
            set_cor(cor);
            set_d(d);
            set_f(f);
        }
        vertice(){}

        void set_lable(int lable){this->lable = lable;}
        void set_cor(string cor){this->cor = cor;}
        void set_d(int d){this->d = d;}
        void set_f(int f){this->f = f;}
        void set_nome_seta(string nome, int id){
            if(id == 1) nome_seta1 = nome;
            else if(id == 2) nome_seta2 = nome;
            else if(id == 3) nome_seta3 = nome;
        }

        int get_lable(){return lable;}
        string get_cor(){return cor;}
        int get_d(){return d;}
        int get_f(){return f;}
        string get_nome_seta(int id){
            if(id == 1)return nome_seta1;
            else if(id == 2)return nome_seta2;
            else if(id == 3)return nome_seta3;
        }
        vertice * seta1;
        vertice * seta2;
        vertice * seta3;

        vertice * prox;
};

int tam = 1;
int mark = 0;
vertice * inicio = NULL;
vertice * fim = NULL;

void cadastrar(){
    vertice * novo = new(vertice);
    novo->set_lable(tam);
    novo->set_cor("Branco");
    novo->prox = NULL;
    novo->seta1 = NULL;
    novo->seta2 = NULL;
    novo->seta3 = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }else{
        fim->prox = novo;
        fim = novo;
    }
    tam++;
    system("clear");
    cout <<VERDE<<novo->get_lable()<<" Cadastrado"<<RESET<<"\n\n";
}


void ver(){
    vertice * aux = inicio;
    while(aux != NULL){
        cout <<aux->get_lable() << " - ";
        if(aux->seta1!=NULL)
            if(aux->get_nome_seta(1) == "Arvore")cout << VERDE"--> " << aux->seta1->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(1) == "Retorno")cout << AMARELO"--> " << aux->seta1->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(1) == "Avanco")cout << VERMELHO"--> " << aux->seta1->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(1) == "Cruzamento")cout << ROXO"--> " << aux->seta1->get_lable()<<RESET << " - ";
        if(aux->seta2!=NULL)
            if(aux->get_nome_seta(2) == "Arvore")cout << VERDE"--> " << aux->seta2->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(2) == "Retorno")cout << AMARELO"--> " << aux->seta2->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(2) == "Avanco")cout << VERMELHO"--> " << aux->seta2->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(2) == "Cruzamento")cout << ROXO"--> " << aux->seta2->get_lable()<<RESET << " - ";
        if(aux->seta3!=NULL)
            if(aux->get_nome_seta(3) == "Arvore")cout << VERDE"--> " << aux->seta3->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(3) == "Retorno")cout << AMARELO"--> " << aux->seta3->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(3) == "Avanco")cout << VERMELHO"--> " << aux->seta3->get_lable()<<RESET << " - ";
            else if(aux->get_nome_seta(3) == "Cruzamento")cout << ROXO"--> " << aux->seta3->get_lable()<<RESET << " - ";
           
        if(aux->seta1 == NULL)cout <<"\t\t\t df: " << aux->get_d()<<"/"<<aux->get_f();
        else if(aux->seta2 == NULL)cout <<"\t\t df: " << aux->get_d()<<"/"<<aux->get_f();
        else if(aux->seta3 == NULL)cout << "\t df: " << aux->get_d()<<"/"<<aux->get_f();
        else cout << "df: " << aux->get_d()<<"/"<<aux->get_f();
        cout << endl;
        aux = aux->prox;
    }
    cout << VERDE "\nVERDE -> ARVORE"<<RESET<<endl;
    cout << AMARELO "AMARELO -> RETORNO"<<RESET<<endl;
    cout << VERMELHO "VERMELHO -> AVANCO"<<RESET<<endl;
    cout << ROXO "ROXO -> CRUZAMENTO"<<RESET<<endl;
    cout<<"\nMark = "<<mark<<"\n\n";
    tam = 1;
    mark = 0;
}

void ver_setas(){
    vertice * aux = inicio;
    while(aux != NULL){
        aux->set_cor("Branco");
        cout <<aux->get_lable() << " - ";
        if(aux->seta1!=NULL){
            cout << VERDE"--> " << aux->seta1->get_lable()<<RESET << " - ";
            if(aux->seta2 != NULL){
                cout << VERDE"--> " << aux->seta2->get_lable()<<RESET << " - ";
                if(aux->seta3 != NULL)
                    cout << VERDE"--> " << aux->seta3->get_lable()<<RESET << " - ";
            }
        }
        cout << endl;
        aux = aux->prox;
    }
    cout << endl;
}

void deletar_tudo(){
    vertice * aux = inicio;
    while(aux != NULL){
        inicio = inicio->prox;
        free(aux);
        aux = inicio;
    }
    tam = 1;
    mark = 0;
}

void ligacao(int x, int y){
    vertice * aux = inicio;

    while(aux->get_lable() != x){
        aux = aux->prox;
    }
    if(aux->get_lable() == x){
        vertice * aux2 = inicio;
        while(aux2->get_lable() != y){
            aux2 = aux2->prox;
        }
        if(aux2->get_lable() == y){
            if(aux->seta1 == NULL){
                aux->seta1 = aux2;
            }else if(aux->seta2 == NULL){
                if(aux->seta1->get_lable() > aux2->get_lable()){
                    aux->seta2 = aux->seta1;
                    aux->seta1 = aux2;
                }else if(aux->seta1->get_lable() < aux2->get_lable()){
                    aux->seta2 = aux2;
                }
            }else{
                if(aux->seta1->get_lable() > aux2->get_lable()){
                    aux->seta3 = aux->seta2;
                    aux->seta2 = aux->seta1;
                    aux->seta1 = aux2;
                }else if(aux->seta2->get_lable() > aux2->get_lable()){
                    aux->seta3 = aux->seta2;
                    aux->seta2 = aux2;
                }else{
                    aux->seta3 = aux2;
                }
            }
        }
    }
}

void dfs_visit(vertice * aux){
    if(aux->get_cor() == "Branco"){
        aux->set_cor("Cinza");
        mark++;
        aux->set_d(mark);
        if(aux->seta1!=NULL){
            if(aux->seta1->get_cor() == "Branco"){
                aux->set_nome_seta("Arvore", 1);
                dfs_visit(aux->seta1);
            }
            else if(aux->seta1->get_cor() == "Cinza")aux->set_nome_seta("Retorno", 1);
            else if(aux->seta1->get_cor() == "Preto"){
                if(aux->get_d() < aux->seta1->get_f())
                    aux->set_nome_seta("Avanco", 1);
                else aux->set_nome_seta("Cruzamento", 1);
            }

            if(aux->seta2!=NULL){
                if(aux->seta2->get_cor() == "Branco"){
                    aux->set_nome_seta("Arvore", 2);
                    dfs_visit(aux->seta2);
                }
                else if(aux->seta2->get_cor() == "Cinza")aux->set_nome_seta("Retorno", 2);
                else if(aux->seta2->get_cor() == "Preto"){
                if(aux->get_d() < aux->seta2->get_f())
                    aux->set_nome_seta("Avanco", 2);
                else aux->set_nome_seta("Cruzamento", 2);
            }
                if(aux->seta3!=NULL){
                    if(aux->seta3->get_cor() == "Branco"){
                        aux->set_nome_seta("Arvore", 3);
                        dfs_visit(aux->seta3);
                    }
                    else if(aux->seta3->get_cor() == "Cinza")aux->set_nome_seta("Retorno", 3);
                    else if(aux->seta3->get_cor() == "Preto"){
                        if(aux->get_d() < aux->seta3->get_f())
                            aux->set_nome_seta("Avanco", 3);
                        else aux->set_nome_seta("Cruzamento", 3);
                    }
                }    
            }
        }
    }
    aux->set_cor("Preto");
    mark++;
    aux->set_f(mark);
}



int main(){
    int opc = 1;
    int x,y;
    while(opc != 0){
        cout << "[ 1 ] Cadastrar"<<endl;
        cout << "[ 2 ] Ligar Vertices"<<endl;
        cout << "[ 3 ] Dfs"<<endl;
        cout << "[ 4 ] Ver"<<endl;
        cout << "[ 5 ] Deletar Tudo"<<endl;
        cout << "[ 0 ] Sair"<<endl<<">> ";
        cin >> opc;
        switch (opc){
        case 1:
            cadastrar();
            break;
        case 2:
            system("clear");
            
            cout << "Ligar vertice x em y"<<endl;
            cout << "x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;
            system("clear");
            ligacao(x,y);
            cout<<VERMELHO<<"Vertices ligados "<<x<<" --> "<<y<<RESET<<endl;
            break;
        case 3:
            mark = 0;
            system("clear");
            dfs_visit(inicio);
            ver();
            break;
        case 4:
            system("clear");
            ver_setas();
            break;
        case 5:
            system("clear");
            deletar_tudo();
            break;
        default:
            break;
        }
    }
    deletar_tudo();
    return 0;
}