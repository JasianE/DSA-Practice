vector<int> solution(vector<int> numbers) {
    vector<int> result; 
    
    // 1 2 1 3 4
    //
    for(int i{0}; i < (numbers.size() - 2); i++){
        int prev = numbers[i];
        int middle = numbers[i+1];
        int third = numbers[i+2];
        if(middle > third && middle > prev){
            result.push_back(1);
        } else if(middle < third && middle < prev){
            result.push_back(1);
        } else {
            result.push_back(0);
        }
    }
    
    return result;
}

string helloWorld(string name) {
    cout << "This prints to the console when you Run Tests" << endl;
    return "Hello, " + name;
}
