class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
		int haylen = haystack.length();
		if(len==0){
			return 0;
		}
		int j = 0;
		for(int i=0;i<haylen;i++){
			if(haystack[i]==needle[j]){
				j++;
			}
            else{
				i = i-j;
				j = 0;
			}
			if(j==len){
				return i - j +1 ;
			}

		}
		return -1;
    }
};