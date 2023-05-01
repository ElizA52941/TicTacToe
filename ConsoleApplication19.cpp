#include <iostream>
using namespace std;

void wyswietl(char tab[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << '\n';
    }
}
bool czyWygrana(char tab[][3], char znak)
{
    bool wygrana;
    for (int i = 0; i < 3; i++)
    {
        if (tab[i][0]==tab[i][1] && tab[i][1]==tab[i][2] && tab[i][0]!='_')
        {
            wygrana = 1;
            cout << "Wygrywa znak "<<znak<<"! Gratulacje!\n";
            break;
        }
        else if (tab[0][i]==tab[1][i]&& tab[2][i]==tab[1][i] && tab[0][i] != '_')
        {
            wygrana = 1;
            cout << "Wygrywa znak " << znak << "! Gratulacje!!\n";
            break;
        }
        else if ((tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2]) && tab[1][1] != '_')
        {
            wygrana = 1;
            cout << "Wygrywa znak " << znak << "! Gratulacje!!!\n";
            break;
        }
        else if ((tab[0][2] == tab[1][1] && tab[0][2] == tab[2][0]) && tab[1][1] != '_')
        {
            wygrana = 1;
            cout << "Wygrywa znak " << znak << "! Gratulacje!!!!\n";
            break;
        }
        else
        {
            wygrana = 0;
        }

    }
    return wygrana;
}
int main()
{
    char tablica[3][3] = { '_','_','_','_','_','_','_','_','_' };
    wyswietl(tablica); 
    char gracz[2] = { '1','2' };
    
    cout << "Gracz nr 1: Grasz O czy X?";
    cin >> gracz[0];
   
    if (gracz[0] == 'x' || gracz[0] == 'X')
        gracz[1] = 'O';
    else gracz[1] = 'X';
    int x,y,i;
    int liczba = 0;
    bool czyBylaWygrana = 0;
    while (czyBylaWygrana==0)
    {
        if (liczba % 2 == 0)
        {
            i = 0;
        }
        else i = 1;
            cout << "Kolej gracza nr 1: Na jakiej pozycji chcesz wstawić symbol " << gracz[i] << "? Wiersz: ";
        cin >> x;
        cout << "Kolumna: ";
        cin >> y;
        while (tablica[x - 1][y - 1] != '_')
        {
            cout << "Niestety to miejsce jest już zajęte. Zaproponuj inne. Wiersz: ";
            cin >> x;
            cout << "Kolumna: ";
            cin >> y;
        }
        tablica[x - 1][y - 1] = gracz[i];
        liczba++;
        system("cls");
        wyswietl(tablica);
        czyBylaWygrana = czyWygrana(tablica, gracz[i]);
    }
    cout << "Koniec gry!";
}