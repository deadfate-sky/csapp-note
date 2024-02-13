# problem
## Practice Problem 2.10  

|step|*x|*y
|---|---|---|
|initially|a|b|
|step 1|a|a^b|
|step 2|a^(a^b)=(a^a)^b=b|a^b|
|step 3|b|b^(a^b)=(b^b)^a=a|

- 比較複雜之處從 step 2 開始。首先，根據 p.88 的 *Web Aside DATA:BOOL*
    > That is, a ^ a = 0 for any value a, where we use 0 here to represent a bit vector of all zeros. We can see this holds for single bits, since 0 ^ 0 = 1 ^ 1 = 0, and it extends to bit vectors as well. This property holds even when we rearrange terms and combine them in a different order, and so (a ^ b) ^ a = b. This property leads to some interesting results and clever tricks, as we will explore in Problem 2.10.  

    我們可以得知一些 exclusive-or 可推論出來的重要性質：
    1. a ^ a = 0, 自己跟自己 exclusive-or 會等於 0
    2. exclusive-or 符合結合律 (associative property) 與交換律 (commutative property)。  

  基於這些性質，我們可以得到 `a^(a^b)=(a^a)^b`，接著根據性質 1，`a^a=0`。再來運用前述未提到的性質，`0^n=n`，0 exclusive-or 非自己的任何數，會等於自己，n 為非零的正整數，所以 `0^b=b`。step 3 解法同理。
- 如此就能利用 bitwise operation 的 exclusive-or 來做到 inplace swap。

## Practice Problem 2.11  
- 在奇數長度的 array `{1,2,3,4,5}` 執行 `reverse_array()` 時，會在最後一次 loop 時， `first` 與 `last` 會指向 array 中同一個位置 (此例中是 3 )，這是如果執行 swap `inplace_swap(&a[first], &a[last]);` 時，會導致 `inplace_swap(int *x, int *y)` 中執行 `*x^*y` 時變為 0，而指派給 `*y` 時，由於 `*x` 與 `*y` 指向同一個 address，因此兩個 pointer 所指向之數值會一起變為 0。因此就導致奇數長度時，最中間的位址的數值會被變為 0。
- 所以在 `reverse_array()` 中，當 `first` 與 `last` 指向同一個位置時，不應該再執行 swap。此處僅簡單將 `first <= last` 改為 `first < last` ，當兩者為同個位置時，跳出迴圈。

## Practice Problem 2.12
- bitwise operatiton 一個常見的用途是作為 mask。例如 
  - `x & 0xFF` 會讓 `x = 0x89ABCDEF` 變為 `0x000000EF`
  - `x & ~0` 會讓所有 bit-level 是 1 的保持 1，其餘變為 0。
- 題目: `x = 0x87654321`, with `w = 32`
  - `[0x00000021]`? `x & 0xFF`
  - `[0x789ABC21]`? 除了 least significant byte 之外，其餘為 complemented，補數（取反）? `x ^ ~0xFF`
    - 這邊用到「0^n=n，0 exclusive-or 非自己的任何數」，與「bit-level 的 exclsive-or 1 會是 1 變為 0，0 變為 1」 這兩個性質。
  - `[0x876543FF]`? least significant byte 設為 1，其餘保持不變? `x|0xFF`

## Practice Problem 2.13
- 僅用 bis 與 bic 來完成 bitwise operations | and ^
  - bis: `x | m`，將 x 的 m bit 設為 1
  - bic: `x ^ m`，將 x 的 m bit 設為 0
- `bool_or()`
  - 將有 1 的 bit 設為 1，其他照舊，就會等於 `x | m`。**嗎？**
- `bool_xor()`
  - `x ^y =(x &~y)|(~x &y)`

## makefile 說明
- Makefile 參考寫法: https://hackmd.io/@sysprog/SySTMXPvl
- (generate from copilot )在這個 Makefile 中：
  - CC 和 CFLAGS 是變數，分別代表編譯器（在這裡是 gcc）和編譯器選項（在這裡是 -Wall -g，表示開啟所有警告並產生除錯資訊）。
- all 是預設目標，它依賴於 reverse 目標。當你只輸入 make 而不帶任何參數時，make 會嘗試建立 all 目標，這將導致 reverse 目標被建立。
- reverse 目標依賴於 inplace-swap.o 和 reverse.o。當這兩個檔案都存在時，make 會執行下面的命令來鏈接這兩個物件檔案，產生 reverse 可執行檔。
- inplace-swap.o 和 reverse.o 目標分別依賴於 inplace-swap.c、inplace-swap.h 和 reverse.c、inplace-swap.h。當這些檔案存在並且比對應的 .o 檔案新時，make 會執行下面的命令來編譯這些源碼檔案，產生 .o 物件檔案。
- clean 是一個特殊的目標，它不依賴於任何檔案。當你輸入 make clean 時，make 會執行下面的命令來刪除所有的 .o 檔案和 reverse 可執行檔。