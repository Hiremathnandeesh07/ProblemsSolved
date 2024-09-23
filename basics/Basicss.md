Sure! Let's break it down with a simple example.

### Pure Function

A pure function is like a vending machine that always gives you the same snack when you press a button, as long as you press the same button every time.

### Example

Imagine a simple function in Python that adds two numbers:

```c
def add(a, b):
    return a + b

```

Every time you give this function the same two numbers, it will always give you the same result. For example:

```c
add(2, 3)  # This will always return 5

```

No matter how many times you call `add(2, 3)`, it will always return 5. This function doesn't change anything outside of itself; it just returns a result.

### Impure Function

An impure function is like a vending machine that might give you different snacks each time you press the same button because it's affected by other things happening around it.

### Example

Imagine a function that adds a number to a total that is stored outside of the function:

```c
total = 0

def add_to_total(a):
    global total
    total += a
    return total
```

Every time you call `add_to_total`, it changes the value of `total`, which is outside the function. For example:

```c

add_to_total(2)  # If total was 0, now it is 2
add_to_total(3)  # Now total is 5 (2 + 3)

```

Here, `add_to_total(3)` might return different results depending on the current value of `total`. It also changes the value of `total`, which is an external state.

### Summary

- **Pure function**: Always gives the same output for the same input and doesn't change anything outside of itself.
- **Impure function**: Might give different outputs for the same input and/or changes something outside of itself.