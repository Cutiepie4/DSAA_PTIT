vector<int> check(100000, 1);
    vector<string> snt;
    check[0] = check[1] = 0;
    for(int i=2; i*i<=100000; i++){
        if(check[i]){
            for(int j=i*i; j<=100000; j+=i){
                check[j]=0;
            }
        }
    }
    for(int i=2; i<check.size(); i++){
        if(check[i]) snt.push_back(to_string(i));
    }

// code c
const int oo = 1000000;
int check[100000];
int prime[100000], x=0;

void eratos(){
    check[0]=check[1]=0;
    for(int i=2; i<oo; i++) check[i]=1;
    for(int i=2; i<=sqrt(oo); i++){
        if(check[i]){
            for(int j=i*i; j<=oo; j+=i){
                check[j]=0;
            }
        }
    }
    for(int i=2; i<=oo; i++){
        if(check[i]) prime[x++]=i;
    }
}