class Cashier {
public:
    int numberOfCustomerVisited=0;
    int m;
    int dis;
    unordered_map<int,int> ma;
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        m=n;
        dis=discount;
        for(int i=0;i<products.size();i++){
            ma[products[i]]=prices[i];
        }
        
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        numberOfCustomerVisited++;
        double totalBill=0;
        for(int i=0;i<product.size();i++){
            totalBill+=ma[product[i]]*amount[i];
        }
        if(numberOfCustomerVisited%m==0){
            
            totalBill=totalBill*((double)(100-dis)/(double)100);
            return totalBill;
        }
        else{
            return totalBill;
        }
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */