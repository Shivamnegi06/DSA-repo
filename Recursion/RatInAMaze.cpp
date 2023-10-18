#include<iostream>
#include<bits/stdc++.h>
#include<vector>

bool moveValid(int x,int y,std::vector<std::vector<int>>& maze,std::vector<std::vector<bool>>& map){
    if((x<map.size()&&x>=0)&&(y<map[0].size()&&y>=0)){
    bool one =  (maze[x][y]==1);
    bool notOnMap  = (map[x][y]==0);
    if(one&&notOnMap){
        return 1;
    }
    }
    return 0;
    
}

void ratPath(std::vector<std::string>& str,std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& map,int x,int y,int d1,int d2){
    
    
    if(x>=d1&&y>=d2){

        
        x=0;y=0;
        
    }

    bool right = moveValid(x,y+1,maze,map);
    bool left = moveValid(x,y-1,maze,map);
    bool down = moveValid(x+1,y,maze,map);
    bool top = moveValid(x-1,y,maze,map);
    
    if(right){
        y++;
        map[x][y]=true;
        str.push_back("Right");
    } 
    else if(left){
        y--;
        map[x][y]=true;
        str.push_back("Left");
    }
    else if(down){
        x++;
        map[x][y]=true;
        str.push_back("Down");
    }
    else if(top){
        x--;
        map[x][y]=true;
        str.push_back("Top");
    }
    else{
        return str.push_back("no path");
    }
    
    ratPath(str,maze,map,x,y,d1,d2);
     

}


int main(){
  
    int x=0, y=0;
    int destination[2] = {2,3};
    int d1 = destination[0];
    int d2 = destination[1];
   
    int nRows = 3;
    int nCols = 4;
    std::vector<bool> row (nCols,false);
    std::vector<std::vector<bool>> map (nRows,row);
    std::vector<std::string> str;
    std::vector<std::vector<int>> maze = {{1,1,1,1},{1,0,0,1},{1,1,1,1}};

    for(int i =0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            std::cout<<map[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl<<std::endl;
      for(int i =0;i<maze.size();i++){
        for(int j=0;j<maze[0].size();j++){
            std::cout<<maze[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
    ratPath(str,maze,map,x,y,d1,d2);
   
    for(const std::string& s : str){
        std::cout<<s<< " ";
    }

    return 0;
}