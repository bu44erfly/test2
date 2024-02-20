function<vector<int>(int,int) > dfs = [&](int x, int fa) -> vector<int> {
            vector<int> a = {cost[x]};
            for (int y: g[x]) {
                if (y != fa) {
                    auto res = dfs(y, x);
                    for(auto k:res) a.push_back(k); 
                }
            }
            //
            return a;
        };
