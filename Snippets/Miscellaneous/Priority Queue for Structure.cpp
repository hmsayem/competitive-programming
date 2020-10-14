struct Person { 
  
    int age; 
    float height; 

}; 
  
struct CompareHeight { 
    bool operator()(Person const& p1, Person const& p2) 
    { 
        return p1.height < p2.height; 
    } 
}; 
  
int main() 
{ 
    priority_queue<Person, vector<Person>, CompareHeight> Q; 
} 
