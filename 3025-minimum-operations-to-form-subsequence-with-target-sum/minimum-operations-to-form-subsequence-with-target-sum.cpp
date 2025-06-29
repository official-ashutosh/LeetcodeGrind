// class Solution {
// public:
//     int minOperations(vector<int>& nums, int target) {
//         multiset<int> s;

//         for(auto i : nums) s.insert(i);

//         int ct = 0, prev = 0;

//         for(auto i : s){
//             if(i == prev){
//                 ct++;
//             } else {
//                 ct = 1;
//                 prev = i;
//             }

//             if(ct == 4 && (i < INT_MAX/2)){
//                 s.erase(s.find(i));
//                 s.erase(s.find(i));
//                 s.insert(i*2);
//                 ct -= 2;
//             }
//         }

//         vector<int> v;
//         for(int i=0; i<32; i++){
//             if(target & (1<<i)){
//                 int k = (1<<i);
                
//                 if(s.find(k) != s.end()){
//                     s.erase(s.find(k));
//                 } else {

//                     int f1 = 0;
//                     int f2 = 0;

//                     if(v.size() > 0){
//                     auto it1 = s.lower_bound(v.back());

//                     if(it1 == s.end()) return -1;

//                     auto it2 = s.lower_bound(1<<i);

//                     if(it2 == s.end()) return -1;

//                     f1 = (*it1)/(v.back());
//                     f2 = (*it2)/(1<<i);

//                     // if(f1 >= f2){
//                     //     v.push_back(1<<i);
//                     //     continue;
//                     // }
//                     }
//                         if(i == 0){
//                             v.push_back(1);
//                             continue;
//                         }
//                     int fl = 0;

//                     multiset<int> ss;

//                         int ct = 2;
//                         int p = (1<<(i-1));

//                         while(true){
//                             while(s.find(p) != s.end() && ct > 0){
//                                 s.erase(s.find(p));
//                                 ss.insert(p);
//                                 ct--;
                            
//                             }

//                             if(p == 1 && ct != 0) break;

//                             if(ct == 0) break;

//                             p /= 2;
//                             ct *= 2;

//                         }
                    
//                     if(ct != 0) {
//                         v.push_back(1<<i);
//                         for(auto j : ss){
//                             s.insert(j);
//                         }
//                     } else {
//                         // s.insert(1<<i);
//                     }
//                 }

//             }
//         }



//         int ans2 = 0;

//         int ans = 0;


//         ct = 0, prev = 0;

//         for(auto i : s){
//             if(i == prev){
//                 ct++;
//             } else {
//                 ct = 1;
//                 prev = i;
//             }

//             if(ct == 3 && (i < INT_MAX/2)){
//                 s.erase(s.find(i));
//                 s.erase(s.find(i));
//                 s.insert(i*2);
//                 ct -= 2;
//             }
//         }

//         for(auto i : v) cout << i << " ";
        
        


//         reverse(v.begin(), v.end());
//         for(auto i : s){
//             cout << i << " ";
//         }
//         cout << endl;

//         for(auto i : v){
//             auto it = s.lower_bound(i);

//             if(it == s.end()) return -1;

//             int k = *it;

//             while(k > i){
//                 s.erase(s.find(k));

//                 k /= 2;
//                 s.insert(k);
//                 s.insert(k);
//                 ans++;
//             }
//         }


//         return min(ans, ans2);
//     }
// };


class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        multiset<int> s;

        for(auto i : nums) s.insert(i);

        int ct = 0, prev = 0;

        for(auto i : s){
            if(i == prev){
                ct++;
            } else {
                ct = 1;
                prev = i;
            }

            if(ct == 4 && (i < INT_MAX/2)){
                s.erase(s.find(i));
                s.erase(s.find(i));
                s.insert(i*2);
                ct -= 2;
            }
        }

        vector<int> v;

        int ans2 = 0;
        for(int i=0; i<32; i++){
            if(target & (1<<i)){
                int k = (1<<i);
                
                if(s.find(k) != s.end()){
                    s.erase(s.find(k));
                } else {

                    int f1 = 0;
                    int f2 = 0;

                    if(v.size() > 0){
                    auto it1 = s.lower_bound(v.back());

                    if(it1 == s.end()) return -1;

                    auto it2 = s.lower_bound(1<<i);

                    if(it2 == s.end()) return -1;

                    f1 = (*it1)/(v.back());
                    f2 = (*it2)/(1<<i);

                    if(f1 >= f2){
                        v.push_back(1<<i);
                        continue;
                    }
                    }
                        if(i == 0){
                            v.push_back(1);
                            continue;
                        }
                    int fl = 0;

                    multiset<int> ss;

                        int ct = 2;
                        int p = (1<<(i-1));

                        while(true){
                            while(s.find(p) != s.end() && ct > 0){
                                s.erase(s.find(p));
                                ss.insert(p);
                                ct--;
                            
                            }

                            if(p == 1 && ct != 0) break;

                            if(ct == 0) break;

                            p /= 2;
                            ct *= 2;

                        }
                    
                    if(ct != 0) {
                        v.push_back(1<<i);
                        for(auto j : ss){
                            s.insert(j);
                        }
                    } else {
                        // s.insert(1<<i);
                    }
                }

            }
        }

        for(auto i : v) cout << i << " ";

        int ans = 0;



        ct = 0, prev = 0;

        for(auto i : s){
            if(i == prev){
                ct++;
            } else {
                ct = 1;
                prev = i;
            }

            if(ct == 3 && (i < INT_MAX/2)){
                s.erase(s.find(i));
                s.erase(s.find(i));
                s.insert(i*2);
                ct -= 2;
            }
        }

        for(auto i : s){
            cout << i << " ";
        }
        cout << endl;
        multiset<int> s2 = s;

        for(auto i : v){
            multiset<int> ss;

                     ct = 2;

                    if(i > 1){
                    int p = i/2;

                    while(true){
                        while(s2.find(p) != s2.end() && ct > 0){
                            s2.erase(s2.find(p));
                            ss.insert(p);
                            ct--;
                        
                        }

                        if(p == 1 && ct != 0) break;

                        if(ct == 0) break;

                        p /= 2;
                        ct *= 2;

                    }
                    }
                    // }
                
                if(ct != 0) {
                    
                    for(auto j : ss){
                        s2.insert(j);
                    }

                    auto it = s2.lower_bound(i);

                    if(it == s2.end()) {
                        ans2 = INT_MAX;
                        break;
                    }

        // reverse(v.begin(), v.end());
                    int k = *it;

                    while(k > i){
                        s2.erase(s2.find(k));

                        k /= 2;
                        s2.insert(k);
                        s2.insert(k);
                        ans2++;
                    }

                    s2.erase(s2.find(i));

                    cout << "i : " << i << " " << ans2 << "*";
                } 
        }

        for(auto i : v){
            auto it = s.lower_bound(i);

            if(it == s.end()) return -1;

            int k = *it;

            while(k > i){
                s.erase(s.find(k));

                k /= 2;
                s.insert(k);
                s.insert(k);
                ans++;
            }
        }
        cout << ans2 << endl;

        return min(ans, ans2);
    }
};