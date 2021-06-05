class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int,int> rem_list;
        
        
        
        long long int remainder = numerator;
        long long int quotient;
        string s;
        
        if((numerator < 0  &&  denominator >0)||(numerator > 0  &&  denominator <0)){
            s+='-';
            
        }
        cout<<remainder<<endl;
        
        
        quotient = abs((remainder)/(long long int)denominator);
        s += to_string(quotient);
        
        remainder = numerator%(long long int)denominator;
        if(remainder == 0)
            return s;
        s+='.';
        vector<int> v;
        
        while(rem_list.find(remainder)==rem_list.end() && remainder != 0){
            rem_list[remainder] = 1;
            v.push_back(remainder);
            remainder *= 10;
            quotient =  abs(remainder/denominator);
            s+=to_string(quotient);
           
            remainder = remainder%denominator;
        }

        if(remainder == 0)
            return s;
        
        cout<<remainder<<endl;
        
        for(auto it: s){
            cout<<it<<";";
        }
        cout<<endl;
        for(auto vi: v){
            cout<<vi<<";";
        }
        
        cout<<endl;
        auto it = s.end();
        
        cout<<remainder<<endl;
        for(int i = v.size()-1;i>=0;i--){
            if(v[i]!=remainder)
                it--;
            else{
                break;
            }
        }
        
        
        cout<<*it<<endl;
        
        s.insert(--it,'(');
        s+=')';
        
        return s;
    }
};
