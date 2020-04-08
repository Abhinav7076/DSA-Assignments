#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;

vector<int> arr;
ofstream fout("dijkstra.txt");
int findMinVertex(int* distance,bool* visited,int n){
 int i;
 int minVertex=-1;
 for(i=0;i<n;i++){
    if((!visited[i]) && ( minVertex == -1 || distance[i] < distance[minVertex])){
        minVertex=i;
    }
 }
 return minVertex;
}

void dijkstra(int** edges,int n){
 int i,j,dist;
int* distance =new int[n];
 bool* visited =new bool[n];

 for(i=0;i<n;i++){
    distance[i] =INT_MAX;
    visited[i] =false;
 }
 distance[4] = 0;
 for(i=0;i<n-1;i++){
    int minVertex = findMinVertex(distance,visited,n);
    visited[minVertex] == true;
    for(j=0;j<n;j++){
        if(edges[minVertex][j] !=0 && !visited[j]  ){
            dist = distance[minVertex] + edges[minVertex][j];
            if(dist < distance[j]){
                distance[j] = dist;
            }
        }
    }
 }
 for(i=1;i<n;i++){
        if(distance[i] == INT_MAX)
        fout << i <<" -1" <<"\n";
 else
    fout << i <<" " << distance[i] <<"\n";
 }
delete [] visited;
delete [] distance;
}

int main(){
 int n=0,num,e=0,i,j,f,s,weight,x,y,k;
ifstream fin("input1.graph");
ifstream fin1("input1.graph");
                while(fin1>>x>>y) {
            arr.push_back(x);
            arr.push_back(y);
            e++;
    	}
            num=arr.size();
        for(i=0; i<num; i++)
     {
        for(j=i+1; j<num; j++)
        {
            if(arr[i] == arr[j])
            {
                for(k=j; k<num; k++)
                {
                    arr[k] = arr[k + 1];
                }
                num--;
                j--;
            }
        }
    }
    n=num;
cout<<n<<e;
 int **edges =new int*[n];
 for(i=0;i<n;i++){
    edges[i]=new int[n];
    for( j=0;j<n;j++){
        edges[i][j]=0;
    }
 }
 for(i=0;i<e;i++){
    fin1 >> x >> y;
    edges[x][y]= 1;
 }
 // dijkstra algorithm
dijkstra(edges,n);

 for(i=0;i<n;i++){
    delete [] edges[i];
 }
}
