    
    vector < pair <int, int > > v;
    sort(v.begin(), v.end());
    
    //Eliminating
    vector < pair <int, int > > w;

    int i = 0;
    while(i < v.size())
    {
        int j = i + 1;

        while(j < v.size() && v[j].ss < v[i].ss)
        {
            j++;
        }
        w.push_back(v[i]);
        i = j;
    }
    
    //Merging
    vector < pair <int, int > > z;

    int pt = w[0].ff;

    FOR(i, w.size())
    {
        if(i + 1 < w.size())
        {
            if(w[i].ss + 1 != w[i+1].ff){

                z.push_back({pt, w[i].ss});
                pt = w[i+1].ff;
            }
        }
        else
            z.push_back({pt, w[i].ss});
    }
