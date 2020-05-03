Given a /*string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/


int Solution::isPalindrome(string str) {
    int i=0;
        transform(str.begin(), str.end(), str.begin(), ::toupper); 
    while(str[i]) {
        // cout<<str[i];
        i++;
    }
    // cout<<i<<" ";
    int len=i;
    i=0;
    int j=len-1;
    // cout<<str[j-1]<<"FFF";
    int flag=0;
    while(i<=j) {
        if((str[i]>='A' && str[i]<='Z') ||(str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9'));
        else {
            i++;
            continue;
        }
        if((str[j]>='A' && str[j]<='Z') ||(str[j]>='a' && str[j]<='z')|| (str[j]>='0' && str[j]<='9'));
        else {
            j--;
            continue;
        }
        if(str[i]==str[j]) {
            i++;
            j--;
            continue;
            
        }
        else {
            flag=1;
            break;
        }
        
    }
    if(flag)
        return 0;
    return 1;
}

