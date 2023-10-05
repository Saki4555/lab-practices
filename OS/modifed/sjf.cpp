#include <bits/stdc++.h>
using namespace std;

int main()
{
    int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
    int sumt = 0, sumw = 0;
    
    cout<<"enter the no of processes : ";
    cin>>n;
    for (i = 0; i < n; i++)
    {
       
        cout<<"the arrival time for process p"<<i+1<<" : ";
        cin>>at[i];
        cout<<"the burst time for process p"<<i+1<<" : ";
        cin>>burst_time[i];
        sum_burst_time += burst_time[i];
    }

    cout<<endl;
    
    burst_time[9] = 9999;
    for (time = 0; time < sum_burst_time;)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
                smallest = i;
        }
        cout<<"P"<<smallest + 1<<" | tat : "<<time + burst_time[smallest] - at[smallest]<<" | wt : "<<time - at[smallest]<<endl;

        sumt += time + burst_time[smallest] - at[smallest];
        sumw += time - at[smallest];
        time += burst_time[smallest];
        burst_time[smallest] = 0;
    }

    cout<<(sumw * 1.0 / n)<<endl;
    cout<<(sumt * 1.0 / n)<<endl;
    return 0;
}
