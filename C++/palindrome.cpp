bool isPalindrome(int x) {
    long long int temp = x;
    long long int rev=0;
    while(x>0)
    {
        rev = rev*10 + x%10;
        x = x/10;
    }
    if(rev==temp)
        return true;
    return false;
}