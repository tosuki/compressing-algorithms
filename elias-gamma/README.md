# Elias Gamma Coding

Elias Gamma coding is one of the simplest universal coding algorithms used to compress **positive integers**, particularly when many of them are small. It is often used in data compression systems like **inverted indexes** in search engines due to its effectiveness with small numbers.

---

## Overview

Elias Gamma coding represents a number in two parts:
1. **Unary representation of the length** of the binary part (excluding the leading `1`)
2. **Binary representation** of the number, **without the leading `1`**

So, for a given positive integer `n`:
- Compute `N = floor(log2(n))` — the number of bits after the leading `1`
- Prefix with `N` zeros (unary encoding)
- Append the **binary representation of `n`** without its leading `1`

---

## Encoding Steps

To encode a number `n` using Elias Gamma:
1. Convert `n` to its binary form.
2. Count the number of **bits** in the binary representation (`L`).
3. Write `L - 1` zeros.
4. Append full binary representation of `n`.

### Example: Encoding 10
1. Binary of `10` is `1010`
2. Length `L = 4`, so write `L - 1 = 3` zeros → `000`
3. Append full binary: `1010`
4. Result: `0001010`

---

## Decoding Steps

To decode Elias Gamma:
1. Count leading zeros until the first `1` is encountered — call this count `N`
2. Read `N + 1` bits total (including the `1`)
3. That’s your original binary number

---

## Properties

- Works well when numbers are skewed toward small values
- Cannot encode zero or negative numbers (only positive integers)
- Simpler than Elias Delta or Omega but less efficient for larger values

---

## Use Cases

- Inverted indexes for search engines
- Storing integer gaps in compressed form
- Run-length encoding extensions
