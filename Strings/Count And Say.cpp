// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
// 
// 1 is read off as one 1 or 11.
// 11 is read off as two 1s or 21.
// 21 is read off as one 2, then one 1 or 1211.
// Given an integer n, generate the nth sequence.
// Note: The sequence of integers will be represented as a string.
// Example:
// if n = 2,
// the sequence is 11.



    string Solution::countAndSay(int n) {
        string str="1";
        n--;
        while(n--) {
            string ns;
            int i=0;
            while(str[i]) {
                int count=0;
                char x=str[i];
                while(x==str[i]) {
                    i++;
                    count++;
                }
                ns+=to_string(count)+x;
            }
            str=ns;
        }
        return str;
    }


