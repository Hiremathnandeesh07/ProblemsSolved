## removing extra spaces

```cpp
public:
    string reverseWords(string s) {
        string result;

         bool spaceFound = false;
int temp=0;
int j=0;
    for (char c : s) {
        if (c != ' ') {
            // If character is not a space, append it to the result string
            result += c;
            spaceFound = false;
        } else {
            // If character is a space, append it only if no space was found before
            if (!spaceFound) {
                result += c;
                spaceFound = true;
            }
        }
    }
```

### reversing string with removing extra spaces

````cpp
class Solution {
public:
    string reverseWords(string s) {
        string result;

         bool spaceFound = false;
int temp=0;
int j=0;
    for (char c : s) {
        if (c != ' ') {
            // If character is not a space, append it to the result string
            result += c;
            spaceFound = false;
        } else {
            // If character is a space, append it only if no space was found before
            if (!spaceFound) {
                result += c;
                spaceFound = true;
            }
        }
    }
    for( j=0;result[j]!='\0';j++){
        //here j reach end
    }
    j=j-1;
    for(int i=0;i<j;i++,j--){
        temp=result[i];
        result[i]=result[j];
        result[j]=temp;
    }
    return result;
    }
};```

````
