    //Function to find the maximum profit and the number of jobs done.
    bool comparison(Job a ,Job b){
        return (a.profit>b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>result; //result[0]: no. of jobs  result[1]:profit
        
        sort(arr,arr+n,comparison); //sort jobs in descending order of profit
        int maxi=arr[0].dead; //find the max deadline possible
        for(int i=1;i<n;i++)
        maxi=max(maxi,arr[i].dead); //maxi will hold the max day a job done
        int slot[maxi+1];
        for(int i=0;i<n;i++)
        slot[i]=-1;   //initialise all with -1 since no job is scheduled
        int profit=0,job_count=0; //initially no job and no profit
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--) //will try to do every job at its deadline day
            {
                if(slot[j]==-1)
                {
                    slot[j]=i; //slot will carry job id to store job sequence for max profit
                    job_count++; 
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        result.push_back(job_count);
        result.push_back(profit);
        return result;
        
        
        
    } 
