
// Tee ohjelma, joka kysyy oppilaiden koearvosanoja (kokonaisluvut 4-10 käytössä) ja 
// laskee syötettyjen arvosanojen keskiarvon. Ohjelman tulee ottaa vastaan arvosanoja, 
// kunnes arvosanojen syöttö lopetetaan negatiivisella kokonaisluvulla. 
// Lopuksi ohjelma tulostaa arvosanojen lukumäärän sekä lasketun keskiarvon.
// Vihje:
// Voit laatia ohjelman joko while- tai do...while-lauseen avulla. 
// Arvosanojen ja keskiarvon tallentamiseen kannattaa käyttää liukulukutyyppisiä muuttujia.
// Example output:
// Ohjelma laskee koearvosanojen keskiarvon.
// Lukujen syöttämisen lopetus negatiivisella luvulla.
// Anna arvosana (4-10)6
// Anna arvosana (4-10)8
// Anna arvosana (4-10)9
// Anna arvosana (4-10)-1
// Ohjelmaan syötetty 3 arvosanaa.
// Arvosanojen keskiarvo:7.66667

#include <iostream>
using namespace std;

int main(){
    int num;
    float average = 0, sum=0, counter= 0;
    while (num > 0){
        cout << "Give num";
        cin >> num;
        if (num > 0){
            counter++;
            sum += num;
        }      
    }
    average = sum/counter;
    cout << "Average is " << average << endl;
}
