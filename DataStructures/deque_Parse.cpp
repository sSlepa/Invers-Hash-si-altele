deque<int> parse(string &line){
    deque<int> Q;
    stringstream ss(line.substr(1, line.size() - 2));
    string token;

    while(getline(ss, token, ',')) 
        Q.push_back(stoi(token));

    return Q;
}
