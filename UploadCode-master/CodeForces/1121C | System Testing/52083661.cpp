#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
 
using namespace std;
 
struct _process
{
    int curr_task;
    bool used;
    int len;
    int step;
};
_process processes[101];
queue<pair<int,int> > task_queue;
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    int tests;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&tests);
        task_queue.push(make_pair(i,tests));
    }
    for (int i = 0; i < m; i++)
    {
        if (not task_queue.empty())
        {
            pair<int,int> t = task_queue.front();
            task_queue.pop();
            processes[i].curr_task = t.first;
            processes[i].used = false;
            processes[i].len = t.second;
            processes[i].step = 1;
        }
        else
        {
            processes[i].used == true;
            processes[i].step = 10000;
        }
    }
    bool task_running = true;
 
    int res = 0;
    int q = 0;
    int done = 0;
    int t = 0;
    while (task_running)
    {
        for (int i = 0; i < m; i++)
        {
            if (processes[i].step == q and not processes[i].used)
            {
                processes[i].used = true;
                res++;
            }
        }
 
        task_running = false;
        for (int i = 0; i < m; i++)
        {
            if (processes[i].len > processes[i].step)
            {
                processes[i].step++;
                task_running = true;
            }
            else if (processes[i].len == processes[i].step)
            {
                done++;
                if (not task_queue.empty())
                {
                    pair<int,int> t = task_queue.front();
                    task_queue.pop();
                    processes[i].curr_task = t.first;
                    processes[i].used = false;
                    processes[i].len = t.second;
                    processes[i].step = 1;
                    task_running = true;
                }
                else
                {
                    processes[i].step = 100000;
                }
            }
        }
 
        q = (200*done + n) / (2*n);
        t++;
    }
 
 
 
 
printf("%d",res);
return 0;
}