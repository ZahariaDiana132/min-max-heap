//MIN-MAX HEAP ( cu reheapup si reheapdown facut pt maxheap)
//ZAHARIA DIANA CRISTIANA GRUPA 132
//SURSE: MATERIALUL DE LA CURS 7-8
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> h; //construim heap sub forma de vector de numere intregi
int mini,pm;
void reheapup(int p) //functie pentru repararea heap-ului care urca elementul pe pozitia corecta
{
    while(p)
    {
        int tata=(p-1)/2;
        if(h[tata]<h[p])
        {
            swap(h[tata],h[p]);
            p=tata;
        }
        else{
            break;
        }
    }
}

void reheapdown(int p)//functie pentru coborarea radacinii catre pozitia corecta in heap
{
    if(p*2+1 >= (int)h.size())
        return;
    int st = h[p*2+1]; int dr = h[p*2+2];
    if( ((p*2+2)==(int)h.size()) || st>dr )
    {
        if(st > h[p])
        {
            swap(h[p], h[p*2+1]);
            reheapdown(p*2+1);
            return;
        }
        else{
            return;
        }
    }
    else
    {
        if(dr>h[p])
        {
            swap(h[p],h[p*2+2]);
            reheapdown(p*2+2);
            return;
        }
        else{
            return;
        }
    }
}

void insertion(int x) //functie inserare
{
    h.push_back(x);
    reheapup(h.size()-1);
}

void build(int n, int v[]) //functie construire heap
{
    for(int i=0; i<n; i++)
        insertion(v[i]);
}

void afisare() //functie afisare heap
{
    cout<<endl;
    for(int i=0;i<(int)h.size();i++)
        cout<<h[i]<<' ';
    cout<<endl;
}

void sterge(int i) //functie stergere element pozitia i
{
    h[i] = h[h.size()-1];
    h.pop_back();
    reheapdown(i);
    reheapup(i);
}
void fmini(int &mini, int &pm) //functie gasire minim
{
    if((int)h.size()==0)
        mini=-1;
    else
    {
        mini= h[h.size()-1];
        for(int i=h.size()-2;i>=(int)h.size()/2;i--)
        {
            if(h[i]<mini)
            {
                mini=h[i];
                pm=i;
            }
        }

    }
}

void dmini(int &mini,int &pm) //functie stergere minim
{
      if((int)h.size()==0)
        mini=-1;
    else
    {
        mini= h[h.size()-1];
        for(int i=h.size()-2;i>=(int)h.size()/2;i--)
        {
            if(h[i]<mini)
            {
                mini=h[i];
                pm=i;
            }
        }

    }
    //cout<<"minim= "<<mini<<endl<<"pozitia este= "<<pm<<endl;
        sterge(pm);
        return;

}

int fmax() // fct gasire maxim (care e in radacina)
{
    if(h.size() == 0)
        return -1;
    else return h[0];
}

void dmax() //fct stergere maxim (care e radacina)
{
    if(h.size()==0)
        return;
    h[0] = h[h.size()-1];
    h.pop_back();
    reheapdown(0);
}

int main()
{
 int decizie=1;

 while(decizie)
 {
    cout<<"Alegeti numarul corespunzator comandei pe care vreti sa o executati:"<<endl;
    cout<<"1 pentru insert"<<endl;
    cout<<"2 pentru delete mini"<<endl;
    cout<<"3 pentru delete max"<<endl;
    cout<<"4 pentru find and show mini"<<endl;
    cout<<"5 pentru find and show max"<<endl;
    cout<<"6 pentru build and show"<<endl;
    cout<<"7 afisare care verifica stergerea"<<endl;
    cout<<"intrdu comanda aici: ";
    cin>>decizie; cout<<endl;
        switch(decizie)
            {
            case 1:
                {
                    int x;
                    cout<<"x="<<endl;
                    cin>>x;
                    insertion(x);
                    break;
                }
            case 2:
                {
                    dmini(mini,pm);
                    break;
                }
            case 3:
                {
                    dmax();
                    break;
                }
            case 4:
                {
                    cout<<"minim= ";
                    fmini(mini,pm);
                    cout<<mini<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"maxim= "<<fmax()<<endl;
                    break;
                }
            case 6:
                {
                    int n;
                    cout<<"n= ";
                    cin>>n;
                    int v[n];
                    cout<<"Cele "<< n<<" numere sunt: ";
                    for(int i=0;i<n;i++)
                        cin>>v[i];
                    build(n,v);
                    afisare();
                    break;
                }
            case 7:
                {
                    afisare();
                    break;
                }
            default:
                {
                    decizie=0;
                    break;
                }
            }
    }
    return 0;
}
