#include<iostream>

using namespace std;
int main()
{
    int a[10],b[10],x[10],pr[10]={0};
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;
   cout<<"\nEnter the number of Processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"arrival time of process P"<<i+1<<" : ";
      cin>>a[i];

      cout<<"burst time of process P"<<i+1<<" : ";
      cin>>b[i];

      cout<<"priority of process P"<<i+1<<" : ";
      cin>>pr[i];
    }
    for(i=0;i<n;i++)
        x[i]=b[i];

    pr[9]=-1;
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && pr[i]>pr[smallest] && b[i]>0 )
                smallest=i;
        }
        time+=b[smallest]-1;
        b[smallest]=-1;
        count++;
        end=time+1;
        completion[smallest] = end;
        waiting[smallest] = end - a[smallest] - x[smallest];
        turnaround[smallest] = end - a[smallest];
    }
   
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<" | tat : "<<turnaround[i]<<" | wt : "<<waiting[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\nAverage waiting time ="<<avg/n<<endl;
    cout<<"Average Turnaround time ="<<tt/n<<endl;
}