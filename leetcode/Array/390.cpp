
390. Elimination Game
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Find the last number that remains starting with a list of length n.
Example:
Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
思路一：用list模拟，nlgn
class Solution {
public:
    int lastRemaining(int n) {
        list<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        bool flag = 1;
        while(n!=1){
            // forward
            flag = 1;
            list<int>::iterator iter = nums.begin();
            for(;iter!=nums.end() && n>1;iter++){
                if(*iter!=0){
                    if(flag){
                        *iter = 0;
                        n--;
                    }
                    flag = !flag;
                }
            }
            // backward
            flag = 1;
            list<int>::reverse_iterator iter2 = nums.rbegin();
            for(;iter2!=nums.rend() && n>1;iter2++){
                if(*iter2!=0){
                    if(flag){
                        *iter2 = 0;
                        n--;
                    }
                    flag = !flag;
                }
            }
        }
            list<int>::iterator iter3 = nums.begin();
            for(;iter3!=nums.end();iter3++)
                if(*iter3!=0)
                    break;
            return *iter3;
    }
};



After first elimination, all the numbers left are even numbers. Divide by 2, we get a continuous new sequence from 1 to n / 2. For this sequence we start from right to left as the first elimination. Then the original result should be two times the mirroring result of lastRemaining(n / 2).
int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}
Here I gave a simple proof of the equation if it can help. Suppoese ML(1...n) = r; We can replace each element in array 1...n by newValue = (n + 1) - oldValue to get a new array n...1; Then we can easily find the result of MR(n...1) = r also; Consider the the location of r in array n...1, it should be the same with the location of the result of MR(1...n) since following the same elimination rule; Then the corresponding value of r in array 1...n should be (n + 1) - r, which gives the result of MR(1...n). This proves ML(1..n) + MR(1..n) = 1 + n

