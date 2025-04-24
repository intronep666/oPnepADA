#include<bits/stdc++.h>
using namespace std;

struct Item{
    int profit,weight;
};

bool compare(Item a, Item b ){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return r1>r2;
}

void knapsack(vector<Item>Items,int capacity){
    //sort kar do profit/weight ratio ke accoding decreasing order me 
    sort(Items.begin(),Items.end(),compare);

    double totalprofit = 0.0;
    int currentweight =0;
   for(int i =0;i<Items.size();i++){
      if(currentweight + Items[i].weight <= capacity ){
        //pura item le lo
        totalprofit = totalprofit + Items[i].profit;
        currentweight = currentweight + Items[i].weight;
        cout << "Profit: " << Items[i].profit << ", Weight: " << Items[i].weight << " (Full)\n";
      }
      else{
        //fractional part le lo agar pura nahi le sakte to
        int remainweight = capacity - currentweight;
        double fraction_profit = Items[i].profit * ((double)remainweight / Items[i].weight);
        totalprofit = totalprofit + fraction_profit;
        cout << "Profit: " << fraction_profit << ", Weight: " << remainweight << " (Fraction)\n";
        break;//knapsack full ho gya
      }
   }
   cout << "Total Profit: " << totalprofit << endl;
}

int main(){
    vector<Item> Items = {{25,18},{24,15},{15,10}};

    knapsack(Items,20);
}









