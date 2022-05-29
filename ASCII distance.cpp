/*
GG Test2, 第一行的整數為字串個數，
每一個字串會有一個距離字串，找出所有字串中，誰的距離字串與他人不同，並輸出該字串。
ex. 距離字串算法如下
  (ABCD)->(1,1,1)
  (DCBE)->(-1,-1,3)
  
---------------------
sample1 input: 
4   ->　 # of series
ABCD
BCDE
EFGH
DCBE

sample1 output:
DCBE

---------------------
sample2 input: 
5   ->　 # of series
ABC
BED
CFE
DGF
FGH

sample2 output:
FGH
--------------------
*/


#include <bits/stdc++.h>

using namespace std;

string findOdd(vector<string> series) {
    int i, j;
    int dist[series[0].size()+10], dist1[series[0].size()+10];

    for(i=0;i<series[0].size()-1;i++)
    {
        dist1[i] = series[0][i+1]-series[0][i];
    }

    int count =0 ;
    for(i=1;i<series.size();i++)
    {
        for(j=0;j<series[0].size()-1;i++)
        {
            dist[j] = series[i][j+1] - series[i][j];
            if(dist[j] != dist1[j])
            {
                if(i == 1)
                {
                    count = 1;
                }
                else
                {
                    if(count == 1)
                    {
                        return series[0];
                    }
                    else
                    {
                        return series[i];
                    }
                }
            }
        }
    }
    return "False";
}

void main(void)
{
  int n, i;
  vector<string> series;
  string result;
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    scanf("%s", series[i]);
  }
    
  result = findOdd(series);
  printf("%s\n", result);
}
