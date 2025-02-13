![Sorting - Part 1 _ Selection Sort, Bubble Sort, Insertion Sort _ Strivers A2Z DSA Course 7-29 screenshot (1)](https://github.com/user-attachments/assets/80dff8b3-e665-4177-9e0c-4fcc80692e88)


![Sorting - Part 1 _ Selection Sort, Bubble Sort, Insertion Sort _ Strivers A2Z DSA Course 7-29 screenshot](https://github.com/user-attachments/assets/b4401fb8-88f9-43de-886b-6f52f685090c)


### Selection Sort Explanation  

#### 🔹 **How Selection Sort Works**  
Selection sort repeatedly finds the **smallest element** in the unsorted part of the array and swaps it with the first element of that part. This process continues until the entire array is sorted.

#### 📌 **Step-by-Step Walkthrough (Example: [13, 46, 24, 52, 20, 9])**
- **Pass 1**: Find the smallest element and swap it with the first element.
- **Pass 2**: Find the next smallest element and swap it with the second element.
- **Pass 3**: Continue this process until the array is sorted.

| Pass  | Action Taken                        | Updated Array            |
|-------|-------------------------------------|---------------------------|
| 1️⃣   | Swap **9** with **13**              | [**9**, 46, 24, 52, 20, 13] |
| 2️⃣   | Swap **13** with **46**             | [9, **13**, 24, 52, 20, 46] |
| 3️⃣   | Swap **20** with **24**             | [9, 13, **20**, 52, 24, 46] |
| 4️⃣   | Swap **24** with **52**             | [9, 13, 20, **24**, 52, 46] |
| 5️⃣   | Swap **46** with **52**             | [9, 13, 20, 24, **46**, 52] |

💡 **Final Sorted Array:** `[9, 13, 20, 24, 46, 52]`

---

### ⏳ **Time Complexity Analysis**
- **Best, Average, and Worst Case**: **O(n²)**
- **Reason:** Two nested loops run in all cases:
  - Outer loop runs **n - 1** times.
  - Inner loop runs up to **n - i - 1** times.
  - Total comparisons = **n(n - 1) / 2 ≈ O(n²)**.

✅ **Good for:** Small arrays.  
❌ **Bad for:** Large datasets due to quadratic time complexity.

---

### 📦 **Space Complexity**
- **O(1)** (constant space) because:
  - Sorting happens **in-place** without extra memory usage.
  - Only a few variables (`mini`, `temp`) are used.

---

### ✅ **Advantages**
1. **Simple to understand & implement** 👨‍💻.
2. **Works well for small datasets** 📊.
3. **Requires no extra space** (in-place sorting) 💾.

---

### ❌ **Disadvantages**
1. **Inefficient for large datasets** ❌:
   - Quadratic time complexity (**O(n²)**) makes it slow.
2. **Not a stable sort** ⚠️:
   - **Stability** means equal elements maintain their **original order**.
   - Since selection sort swaps elements **non-adjacently**, relative order may change.
   - Example: If `arr = [(3, A), (3, B), 1, 2]`, sorting may result in `[(1), (2), (3, B), (3, A)]` (order of `(3, A)` and `(3, B)` is altered).

---

### 📌 **Key Takeaways**
✔️ Selection Sort is **easy to implement** but **inefficient** for large datasets.  
✔️ It performs **in-place sorting** with **O(1) space complexity**.  
✔️ It is **not stable**, meaning it may not preserve the order of duplicate elements.  
✔️ It is **useful only for small arrays** or when **memory is very limited**.


```cpp

// selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}
int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  selection_sort(arr, n);
  return 0;
}

```
