#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m; // reading n and m

    vector<long long> likes(n);
    for (int i = 0; i < n; i++) {
        cin >> likes[i];
    }

    // finding initial maximum likes and its index (0-based)
    long long maxLikes = likes[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (likes[i] > maxLikes) {
            maxLikes = likes[i];
            maxIndex = i;
        }
    }

    vector<pair<int, long long>> results;

    //the querries
    while (m--) {
        int post_no;
        long long like_increase;
        cin >> post_no >> like_increase;

        int idx = post_no - 1;  //adjusting for 0-based indexing
        likes[idx] += like_increase;

        //update max if needed
        if (likes[idx] > maxLikes) {
            maxLikes = likes[idx];
            maxIndex = idx;
        } else if (likes[idx] == maxLikes && idx < maxIndex) {
            //choose the post with the smaller index
            maxIndex = idx;
        }
        
        results.push_back({maxIndex + 1, maxLikes});
    }
    //the 1-based post index and the current maximum likes
    for (auto &res : results) {
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}