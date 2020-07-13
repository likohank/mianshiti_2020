typedef multiset<int.greater<int>> intSet;
typedef multiset<int,greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data,intSet& leastNumbers,int k){
    leastNumbser.clear();

    if(k<1 || data.size()<k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for(;iter!=data.end(); ++iter)
    {
        if(leastNumbser.size()<k)
            leastNumbsers.insert(*iter);
        else
        {
            setIterator iterGreatest = leastNumbser.begin();
            if(*iter<*(leastNumbser.begin()))
            {
                leastNumbser.erase(iterGreatest);
                leastNumbser.insert(*iter);
            }
        }
    }
}

####################################

typedef multiset<int,greater<int>> intSet;
typedef multiset<int,greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data,intSet& leastNumbser,int k){

    leastNumbser.clear();

    if(k<1 || data.size()<k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for(;iter!=data.end();++iter){
        if(leastNumbser.size()<k){
            leastNumbers.insert(*iter);
        }
        else{
            setIterator iterGreast = leastNumbers.begin();
            if(*iter<*iterGreast){
               leastNumbser.erese(iterGreast);
               leastNumbser.insert(*iter);
            }
        }
    }
}
