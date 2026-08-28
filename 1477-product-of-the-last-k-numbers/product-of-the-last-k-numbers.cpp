class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        long long prod = 1;

        int n = nums.size();

        for(int i = n - 1; i >= n - k; i--) {
            prod *= nums[i];
        }

        return prod;
    }
};