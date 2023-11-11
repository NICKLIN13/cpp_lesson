# L03 HW3

- 2023-05-16
- 21:05-23:10
- 1.5hr


1. 介紹 `std::find`, `std::sort`, `std::equal` 中會用到的 `begin()`, `end()` (iterator)。
2. 介紹 `sort` 中的 comparator。
3. char <=> int (`ch - 'A'` or `digit - '0'`)。

# 檢討 HW

1. [Two Sum - LeetCode](https://leetcode.com/problems/two-sum/)
    1. NICK 的解法
        1. 雙層 for loop 暴力解
2. [Contains Duplicate - LeetCode](https://leetcode.com/problems/contains-duplicate/)
    1. NICK：先用 map 紀錄完全部，再進 map 掃過一次。O(2n)，最慢。
        ```cpp
        bool containsDuplicate(vector<int>& nums) {
            // 把東西丟進map裡面，讓他幫忙計數
            map<int, int> mp;
            for(int i = 0; i <= nums.size()-1; i++) {
                mp[nums[i]] = mp[nums[i]] + 1;
            }
            // 掃過map上的每一個欄位，看有沒有大於1的
            for (auto it : mp) {
                if (it.second > 1) {
                    return true;
                }
            }
            return false;
        }
        ```

    2. 改進版：介紹怎麼用 find。O(n)，略快一點點。
        ```cpp
        bool containsDuplicate(vector<int>& nums) {
            //把東西丟進map裡面，讓他幫忙計數
            map<int, int> mp;
            for(auto num: nums) {
                if (mp.find(num) == mp.end()) {
                    mp[num] = 1;
                } else {
                    return true;
                }
            }
            return false;
        }
        ```

    3. One liner：直接用 set 去掉重複。O(n)? 沒有快多少。
        ```cpp
        bool containsDuplicate(vector<int>& nums) {
            return nums.size() > set<int>(nums.begin(),nums.end()).size();
        }
        ```

    4. 排序後找重複。差不多最快了。O(n)。memory 94%。
        ```cpp
        bool containsDuplicate(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == nums[i-1]) return true;
            }
            return false;
        }
        ```

3. [Valid Anagram - LeetCode](https://leetcode.com/problems/valid-anagram/)
    1. NICK：都 sort 後確認相等。
        ```cpp
        bool isAnagram(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s==t;
        }
        ```

    2. 改良：先檢查長度相等，再用 map 數頻率，最後確保兩個 map equal。
        ```cpp
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false; // guarding

            map<char, int> mp_s, mp_t;
            for (int i = 0; i < s.size(); i++) {
                mp_s[s[i]]++;
                mp_t[t[i]]++;
            }

            return equal(mp_s.begin(), mp_s.end(),
                        mp_t.begin());
        }
        ```

    3. 參考高速答案：用只用一個原生 array 取代兩個 map，且用正負數來確保 equal。
        ```cpp
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false; // guarding

            int const N = 26;
            int hash[N] = {0};

            for (int i = 0; i < s.size(); i++) {
                hash[s[i] - 'a']++;
                hash[t[i] - 'a']--;
            }
            
            for (int i = 0; i < N; i++) {
                if (hash[i] != 0) return false;
            }

            return true;
        }
        ```


# HW for this week
1. [Two Sum IV - Input is a BST - LeetCode](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
2. [3Sum - LeetCode](https://leetcode.com/problems/3sum/)
