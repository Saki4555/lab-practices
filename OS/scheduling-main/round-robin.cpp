#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    double avg_wt, avg_tat;

    cout << "Number of processes : ";
    cin >> n;
    y = n;

    for (i = 0; i < n; i++)
    {

        cout << "arrival time for process P" << i + 1<<" : ";
        cin >> at[i];

        cout << "burst time for process P" << i + 1<<" : ";
        cin >> bt[i];

        temp[i] = bt[i];
    }

    cout << "time quantum : ";
    cin >> quant;

    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--;
            cout << "P" << i + 1 << " | tat : " << sum - at[i] << " | wt : " << sum - at[i] - bt[i] << endl;
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    cout << "Average waiting time : " << avg_wt << endl;
    cout << "Average turn-around time : " << avg_tat << endl;

    return 0;
}