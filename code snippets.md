> ## find max element

```cpp
int max_altitude = *max_element(v.begin(), v.end()); // Find maximum altitude
        return max_altitude;
```

## string to number

```cpp
int main() {
    std::string str = "12345";
    int num = std::stoi(str);
    std::cout << "The integer value is: " << num << std::endl;
    return 0;
}
```

## sorting

````cpp
int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};

    // Sort the vector
    std::sort(vec.begin(), vec.end());

    // Print the sorted vector
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
    ```
````
