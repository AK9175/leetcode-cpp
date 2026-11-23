// 1352. Product of the Last K Numbers  [Medium]

class ProductOfNumbers {
public:
    vector<long long> prefixproduct; // prefix product considering 0 as 1 for O(1)
    int ind = -1; //index where we have latest 0, update when encounter 0 
    ProductOfNumbers() {
        prefixproduct.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            ind = prefixproduct.size()-1;
            // prefixproduct.push_back(prefixproduct.back());
            prefixproduct.push_back(0);
        }
        else{
            if(prefixproduct.back() == 0) prefixproduct.push_back(num);
            else prefixproduct.push_back(prefixproduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int leftind = prefixproduct.size() - (k+2);
        if(ind > leftind) return 0;
        int currentProd = prefixproduct.back();
        int todivide = prefixproduct[leftind+1];
        if(todivide == 0) todivide = 1;
        return currentProd/todivide;
    }
};

/**\
 * 
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

 //[3,0,2,5,4,8]
 //[1,3,3,6,30,120,960] 

 //3,3,6,30,120,960
 //3,0,2,10,40,320

 //6*20=120
 //so 120/6 gives you 20
 //some how we need to know if a range (last k has a 0 or not)
 //we can have a variable which will always have the latest index of 0