#include <iostream>
using namespace std;

// Why was this so much more complicated than all the others  :(

 int counting (char search, char check[], int size){
     int tick = 0;
     for(int i = 0; i < size; i++)
        if(search == check[i]) {
                tick++; 
        }
     return tick;
 }


int main() {
    
    
    char entry = 0;
    int counter = 0;
    int ticker = 0;
    char search;
    char list[15];
    char unique[15];
    int numbs[15];


    cout << "Please enter letters for your 15 entry array: \n";
    for (int i = 0; i < 15; i++) {
        cin >> entry;
        list[i] = entry;
    }

    cout << "Please provide the search entry for your array: \n";
        cin >> search;

    counter = counting(search, list, 15);

    for (int i = 0; i < 15; i++) {
        numbs[i] = counting(list[i], list, 15);
        
    }
   



    if(counter > 0){
        cout << "The letter " << search << " appears " << counter << " times\n";
        
        for (int i = 0; i < 15; i++) {

            if((numbs[i] == counter)&&(!(list[i] == search))){

                for (int u = 0; u < i; u++){

                    if(unique[u] == list[i]){

                        ticker++;
                    }
                }
                
                if(!( ticker > 0)){
                    unique[i] = list[i];
                    cout << "The letter " << list[i] << " appears " << numbs[i] << " times\n";
                }
            }
            ticker = 0;
        }

    }
    else {
        cout << "The letter " << search << " does not appear\n";
    }

    
    return 0;
}
