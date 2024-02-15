## 與此章相關的面試題紀錄

- 2016 MTK 4G 工具軟體工程師 ([來源](https://hackmd.io/@86E3gZKuToKwjVavw4Wdpw/BJoOqyo6?type=view))
```c
//1. ask: the value of v?
unsigned long v1 = 0x00001111;
unsigned long v2 = 0x00001202;
unsigned long v;
v = v1&(~v2);
v = v | v2;
```
source code: [interview_mtk_4g_2016.c](./interview_mtk_4g_2016.c)

這題是在測試**bitwise operation**的基本計算。具體解法，就是將原本為 hexadecimal 的數字轉換為 binary 形式的 bit，接著進行 binary 運算。先假定是在 32bit 的機器上運作。

首先，先將 `v1` 與 `v2` 的值轉換為 binary 形式：
```
(以下只轉換後四位，因前四位皆為 0，暫且忽略)
v1 = 0001 0001 0001 0001
v2 = 0001 0010 0000 0010
```
第一題，計算 `v1&(~v2)`：
```
v1 | 0001 0001 0001 0001
~v2| 1110 1101 1111 1101
-------------------------
  &| 0000 0001 0001 0001

v = 0000 0001 0001 0001
or 
0x00000111
```
第二題，計算 `v = v | v2`，此處的 v 假設需使用前一題的結果：
```
v  | 0000 0001 0001 0001
v2 | 0001 0010 0000 0010
------------------------
`|`| 0001 0011 0001 0011

v = 0001 0011 0001 0011
or
0x00001313
```
- 旺宏 - 韌體研發工程師（[來源](https://www.pttweb.cc/bbs/Tech_Job/M.1612848862.A.6D2)）  
  - [參考他人試做](https://hackmd.io/@qwe661234/rJUqIOzBo)

Question: coding，使用 bitwise operation 計算出兩個 integer 有幾個 bits 不一樣?

source code: [inter_mixc_fw_2021.c](inter_mixc_fw_2021.c)  
compile 後可使用以下指令執行：
```bash
mxic 556 788
```

記錄一些先備的知識與小技巧：
- exclusive-or 運算 `^`
- `n&1` 
  - 可以判斷 n 的最低位數是否為 1，因為例如一個 `int32_t` 的 1 他的位元會是 `0x00000001`，僅有最低位會是 1，所以 `n&1` 僅有在最低位元為 1 時會回傳 1。同理可推出下一條技巧。
  - 可以判斷 n 是否為奇數 (copilot 自己額外補充的！但一樣實用)
- `>>` right shift

於此題中，利用 `compare_int32()` 來實作比較並回傳兩 integer 不同 bit 的個數的功能。首先，利用 exclusive-or 運算，來使得兩 integer 不同的 bit 變為 1，相同的 bit 變為 0。得到此結果後，接著就可以計算總共有多少個 bit 為 1。而要做到這件事，此處程式的作法，是利用「計數最低位是否為 1，每次比較並計數一次後，bit right shift 一位」來達成目的。如此一來，即可依序比較每一 bit 是否為一，最後回傳計數結果 `count`。