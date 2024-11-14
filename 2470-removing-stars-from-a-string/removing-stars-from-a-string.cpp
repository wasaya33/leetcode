
                            // using stack

// class Solution {
// public:
//     string removeStars(string s) {
//        stack<char> st;
//        for(int i = 0; i < s.size(); i++){
//         if(s[i] == '*'){
//             st.pop();
//         }
//         else{
//                 st.push(s[i]);
//             }
//        }        
//        string result = "";
//        while(!st.empty()){
//         result.push_back(st.top());
//         st.pop();
//        }
//        reverse(begin(result) , end(result));
//        return result;
//     }
// };

                //    using string
// class Solution {
// public:
//     string removeStars(string s) {
//         string result = "";
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] ==  '*'){
//                 result.pop_back();
//             }else{
//                 result.push_back(s[i]);
//             }
//         }
//         return result;
//     }
// };
                             // using another approach

class Solution {
     public:
             string removeStars(string s) {
                int n = s.size();
                vector<char> temp(n);

                int j  = 0;
                for(int i = 0; i < n; i++){
                    if(s[i] == '*'){
                        j--;
                    }else{
                        temp[j] = s[i];
                        j++;
                    }
                }
                string result = "";
                for(int k = 0; k <= j-1; k++){
                    result.push_back(temp[k]);
                }
                return result;
             }
};