class Solution {
public:
    bool present(char x,string str){
       for(int i=0;i<str.length();i++){
           if(str[i]==x){
               return true;
           }
       }
        return false;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum=0;
        for(int i=0;i<travel.size();i++){
            sum+=travel[i];
        }
        int count=0;
        for(int i=0;i<garbage.size();i++){
            count+=garbage[i].length();
        }
        int a=sum;
        for(int i=garbage.size()-1;i>=0;i--){
            if(present('G',garbage[i])){
                break;
            }
            else{
                if(i>0){
                    a-=travel[i-1];
                }
                
            }
        }
        cout<<a<<" ";
        int b=sum;
        for(int i=garbage.size()-1;i>=0;i--){
            if(present('P',garbage[i])){
                break;
            }
            else{
                if(i>0){
                    b-=travel[i-1];
                }
                
            }
        }
        cout<<b<<" ";
        int c=sum;
         for(int i=garbage.size()-1;i>=0;i--){
            if(present('M',garbage[i])){
                break;
            }
            else{
                if(i>0){
                    c-=travel[i-1];
                }
                
            }
        }
        cout<<c<<" ";
        return a+b+c+count;
        
    }
};