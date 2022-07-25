class FoodRatings {
public:
    struct cmp{
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const
        {
            if(a.first==b.first)
                return a.second< b.second;
            else
                return a.first> b.first;
        }
    };
    
    unordered_map<string, set<pair<int, string>, cmp>> cuisineToFood;  //(korean, (14, sushi))
    unordered_map<string, string> convert;  //food-> cuisine
    unordered_map<string, int> rating;  //food-> rating
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            cuisineToFood[cuisines[i]].insert({ratings[i], foods[i]});
            convert[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i]; 
        }
    }
    
    void changeRating(string food, int newRating) {
        int r = rating[food];   //old rating
        //update rating
        string cuisine = convert[food];
        cuisineToFood[cuisine].erase({r, food});
        cuisineToFood[cuisine].insert({newRating, food});
        
        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto mx = *(cuisineToFood[cuisine].begin());
        return mx.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */