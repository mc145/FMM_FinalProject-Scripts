#include<iostream>
#include<vector>
#include<string> 

using namespace std; 


vector<string> riffleShuffle(vector<string> crds){
    int size1 = (rand() % (28 - 23 + 1)) + 23; 
    int size2 = 52 - size1; 


    vector<string> p1; 
    vector<string> p2; 

    for(int i = 0; i<size1; i++){
        p1.push_back(crds[i]); 
    }
    for(int i = size1; i<52; i++){
        p2.push_back(crds[i]); 
    }

    vector<string> fin; 

    int pointer1 = 0; 
    int pointer2 = 0; 

    while(pointer1 < p1.size() || pointer2 < p2.size()){
        if(pointer1 == p1.size() - 1){
            while(pointer2 < p2.size()){
                fin.push_back(p2[pointer2]); 
                pointer2++; 
            }
        }
        else if(pointer2 == p2.size() - 1){
            while(pointer1 < p1.size()){
                fin.push_back(p1[pointer1]); 
                pointer1++; 
            }
        }
        else{
           int num = (rand() % (3 - 1 + 1)) + 1; 
           int num2 = (rand() % (3 - 1 + 1)) + 1; 
            int fixP1 = pointer1; 
            int fixP2 = pointer2; 
            while(pointer1 < p1.size() && pointer1 < fixP1 + num){
                fin.push_back(p1[pointer1]); 
                pointer1++; 
            }
            while(pointer2 < p2.size() && pointer2 < fixP2 + num2){
                fin.push_back(p1[pointer2]); 
                pointer2++; 
            }


        }
    }

    return fin; 
}

vector<string> cutCards(int k, vector<string> crds){
    vector<string> fin; 
    for(int i = k+1; i<crds.size(); i++){
        fin.push_back(crds[i]); 
    }
    for(int i = 0; i<=k; i++){
        fin.push_back(crds[i]); 
    }

    return fin; 
}

int main(){
    vector<string> cards; 

    for(int i = 0; i<52; i++){
        if(i % 2 == 0) cards.push_back("R"); 
        else{
            cards.push_back("B"); 
        }
    }

    cout << "INITIAL: " << endl; 

    for(int i = 0; i<52; i++){
        cout << cards[i] << " "; 
    }
    cout << "\n"; 

    vector<string> cardsAfterShuffle = riffleShuffle(cards); 

    cout << "AFTER SHUFFLE: " << endl; 
    for(int i = 0; i<52; i++){
        cout << cardsAfterShuffle[i] << " "; 
    }    
    cout << '\n'; 

    cout << "AFTER CUT: " << endl; 

    int cutIndex = -1; 
    for(int i = 1; i<cardsAfterShuffle.size(); i++){
        if(cardsAfterShuffle[i] == cardsAfterShuffle[i-1]){
            cutIndex = i-1; 
            break; 
        }
    }
    
    vector<string> cardsAfterCut = cutCards(cutIndex, cardsAfterShuffle); 

    for(int i = 0; i<cardsAfterCut.size(); i++){
        cout << cardsAfterCut[i] << " "; 
    }

}
