To remove duplicate lines from a file in Python, you can follow these steps:

1. **Read the file** and store its lines.
2. **Remove duplicates** by using a set (since sets inherently do not allow duplicates).
3. **Write the unique lines back** to a new file (or overwrite the existing one).

Here's a Python script that performs these steps:

```python
def remove_duplicate_lines(input_filename, output_filename):
    # Open the input file in read mode
    with open(input_filename, 'r') as file:
        # Read all lines from the file
        lines = file.readlines()

    # Use a set to remove duplicates and preserve the order
    unique_lines = list(dict.fromkeys(lines))

    # Open the output file in write mode
    with open(output_filename, 'w') as file:
        # Write the unique lines back to the file
        file.writelines(unique_lines)

# Example usage
input_filename = 'input.txt'  # Replace with your input file path
output_filename = 'output.txt'  # Replace with your desired output file path
remove_duplicate_lines(input_filename, output_filename)
```

### **Explanation of Each Line of Code:**

1. **`def remove_duplicate_lines(input_filename, output_filename):`**
   - This function takes two arguments: `input_filename` (the path of the file from which duplicate lines need to be removed) and `output_filename` (the path of the file where the result will be written).

2. **`with open(input_filename, 'r') as file:`**
   - Opens the input file in **read mode**. The `with` statement ensures that the file is properly closed after reading.

3. **`lines = file.readlines()`**
   - Reads all the lines from the file and stores them in a list called `lines`. Each line is considered a separate element in the list, including the newline character `\n`.

4. **`unique_lines = list(dict.fromkeys(lines))`**
   - This line removes duplicates while preserving the original order of the lines:
     - `dict.fromkeys(lines)` creates a dictionary with each line as a key. Since dictionary keys must be unique, any duplicates are automatically removed.
     - `list()` is then used to convert the dictionary keys back into a list, preserving the original order of the lines.

5. **`with open(output_filename, 'w') as file:`**
   - Opens the output file in **write mode**. If the file already exists, it will be overwritten.

6. **`file.writelines(unique_lines)`**
   - Writes the list of unique lines back to the output file. Each line in the list is written as-is, including the newline characters.

### **Example:**

#### **Input File (`input.txt`):**
```
apple
banana
apple
cherry
banana
date
```

#### **Output File (`output.txt`):**
```
apple
banana
cherry
date
```

### **Explanation:**
- **Set and Dictionary**: We used `dict.fromkeys(lines)` to effectively remove duplicates while maintaining the original order of lines.
- **Time Complexity**:
  - **Reading the file**: O(n), where `n` is the number of characters in the file.
  - **Removing duplicates**: O(m), where `m` is the number of lines in the file (this is because `dict.fromkeys()` iterates through the lines once).
  - **Writing the result**: O(n), where `n` is the number of characters in the result file.

This solution works well for removing duplicate lines from a file while maintaining the order of the first occurrence of each line.
