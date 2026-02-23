void ciur(){
    for(int i = 2 ; i * i <= 500000 ; ++i)
        if(!a[i])
            for(int j = i * i ; j <= 500000 ; j += i)
                a[j] = 1;
}
