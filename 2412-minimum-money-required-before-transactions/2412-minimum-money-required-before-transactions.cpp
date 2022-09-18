class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        // 3 cases arise
        
        
        // case 1: when all costs are greater than cashback
        // so if i don't consider this condn money>=costi
        // so what we want is only the addn of diff of cost and cashback for transactions to be successfully done
        // lets consider example -> [5,2],[4,3],[2,1]
        // addn of diff -> 3+1+1 = 5
        // but wait we are considering that 3 cashback is obtained
        // but if it is not obtained
        // so in worst case we take maximum of all cashbacks i.e 3 and add it to res
        // finally , ans=5+3  = 8 is required
        
        
        // case 2: when all costs are smaller than cashbacks
        // that means we always earn profit, nothing will be lost
        // but condn money>=costi creates problem  
        // so in worst case , take maximum of all costs and display that 
        // example [2,5],[3,4],[1,2] => for condn to be satisfied -> 3 should be taken
        
        // case 3: mixture of case1 and case2
        // here mixture of both operation should be done
        // take diff in res only if cost>=cashback since it will sub
        // for cost<cashback always adds to money so no need to consider
        // but condn this will create problem money>=costi
        // so take maximum of all min(cost,cashback)
        // add it to res
        // why common maximum since it is usable
        // for cost<cashback always adds profit to result 
        // for others we already considered that cashback is not obtained in worst case
        
        int maxi=0;
        long long res=0;
        for(int i=0;i<transactions.size();i++)
        {
            maxi=max(maxi,min(transactions[i][0],transactions[i][1]));
            if(transactions[i][0]>transactions[i][1])
                res+=(transactions[i][0]-transactions[i][1]);
        }
        return res+maxi;
    }
};