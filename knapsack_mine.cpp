#include <bits/stdc++.h>
using namespace std;

#define rafsan ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

int main(){
    rafsan;
    int n;
    //cout<<setprecision(2)<<fixed<<"Enter the number of Items: "; 
    cin>>n;
    double ItemWeight[n],ItemProfit[n],ProfitPerWeight[n];
    for (int i = 0; i < n; i++)
    {
        //cout<<"Enter Weight of Item "<<i+1<<": "; 
        cin>>ItemWeight[i];
        //cout<<"Enter Profit of Item "<<i+1<<": "; 
        cin>>ItemProfit[i];
        ProfitPerWeight[i] = ItemProfit[i]/ItemWeight[i];
    }
    double weight,SumProfit{0.00};
    //cout<<"Enter limit of the knapsack: "; 
    cin>> weight;
    while (weight > 0)
    {
        int count{0},i{1};
        double temp = ProfitPerWeight[0];
        while (i<=n)
        {
            if (temp > ProfitPerWeight[i]) ++i;
            else {
                temp = ProfitPerWeight[i];    
                ++i;
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            if (temp == ProfitPerWeight[j])
            {
                ProfitPerWeight[j] = -1;
                if (weight >= ItemWeight[j])
                {
                    weight = weight - ItemWeight[j];
                    SumProfit += ItemProfit[j];
                }
                else{
                    SumProfit += (ItemProfit[j]/ItemWeight[j])* weight;
                    weight = 0;
                }
                break;
            }
        }
    }
    cout<<fixed<<setprecision(2)<<"Profit: "<<SumProfit<<endl;
    return 0;
}