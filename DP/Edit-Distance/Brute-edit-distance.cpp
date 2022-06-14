int editDistance(string s1, string s2) {
	// Write your code here
    if(s1.size() == 0 || s2.size() == 0)
        return max(s1.size(), s2.size());

    if(s1[0] == s2[0])
      return editDistance(s1.substr(1), s2.substr(1));
        
    int x,y,z;
        
    x = editDistance(s1.substr(1), s2);
    y = editDistance(s1, s2.substr(1));
    z = editDistance(s1.substr(1), s2.substr(1));
    
    return min(z, min(x, y)) + 1;
}
