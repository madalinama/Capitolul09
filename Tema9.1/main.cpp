#include <iostream>
#include <stdlib.h>
#include <vector>
#include <Participant.h>
#include "Roman.h"
#include "Francez.h"
#include "German.h"


using namespace std;

void Meniu ()
{
    system("CLS");
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<<"1.Adaugare participant"<<endl;
    cout<<"2.Afisare sumar"<<endl;
    cout<<"0.Iesire"<<endl;
}

Participant* CreazaParticipant()
{

     system("CLS");
     cout<<"Alegeti nationalitatea:"<<endl;
     cout<<"1.Roman"<<endl;
     cout<<"2.Francez"<<endl;
     cout<<"3.German"<<endl;
     cout<<"4.Alta"<<endl;

     int optiune;
     cin>>optiune;

     switch(optiune)
     {
         case 1: {Participant* roman=new(Roman);
                  return roman;
                  break;}
         case 2: {Participant* francez=new(Francez);
                  return francez;
                  break;}
         case 3:{Participant* german=new(German);
                  return german;
                  break;}
         case 4:{Participant* participant=new(Participant);
                  return participant;
                  break;}
     }
}

int main()
{
    vector <Participant*> pntParticipanti;
    int opt=1;
    while (opt!=0)
    {
        Meniu();
        cin >>opt;
        if (opt==1)
               pntParticipanti.push_back(CreazaParticipant());
        else if(opt==2)
        {
            system("CLS");
            int f=0,r=0,g=0,a=0;

           for (int i=0; i<pntParticipanti.size(); ++i)
               {
                 if(pntParticipanti[i]->Vorbeste()==Limba::franceza)
                    f=f+1;
                 if(pntParticipanti[i]->Vorbeste()==Limba::germana)
                    g=g+1;
                 if(pntParticipanti[i]->Vorbeste()==Limba::romana)
                    r=r+1;
                 if(pntParticipanti[i]->Vorbeste()==Limba::engleza)
                    a=a+1;
               }

        if ((r||f||g||a)!=0)
            cout<<"Participanti inscrisi pana acum:"<<endl;

        cout<<r<<" Romani"<<endl;
        cout<<f<<" Francezi"<<endl;
        cout<<g<<" Germani"<<endl;
        cout<<a<<" Altii"<<endl;

        system("PAUSE");
        }

    }
    pntParticipanti.clear();

    return 0;
}

