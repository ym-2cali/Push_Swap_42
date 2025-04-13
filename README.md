# 🧠 Push_Swap_42

Welcome to `push_swap` — a deceptively simple sorting challenge designed to sharpen algorithmic thinking, logic optimization, and efficient C programming.

## 🚀 About the Project

At its core, `push_swap` is about sorting a stack of integers with the least number of operations, using only a limited set of predefined instructions. The real twist? You can't cheat your way through with classic `sort()` functions — you have to design and implement your own algorithm, under tight constraints.

This project is part of the curriculum at **1337 School Khouribga**, and aims to develop both precision and creativity when writing optimized code.

---

## 💡 How It Works

You are given a sequence of integers as arguments. Your mission is to sort them in ascending order using two stacks (`a` and `b`) and only the following set of operations:

- `sa`, `sb`, `ss` — Swap
- `pa`, `pb` — Push
- `ra`, `rb`, `rr` — Rotate
- `rra`, `rrb`, `rrr` — Reverse Rotate

The fewer moves, the better your solution.

---

## 🧰 Skills Developed

- Algorithm design and analysis  
- Optimization under constraints  
- Stack manipulation and operations  
- Memory management and pointer safety in C  
- Defensive programming and error handling  
- Writing clean, modular, and maintainable code  

---

## 💡 Learning Highlights

Working on `push_swap` taught me much more than sorting logic. It demanded:

- Designing efficient solutions beyond brute-force approaches.  
- Understanding trade-offs between algorithm complexity and execution steps.  
- Mastering data manipulation through low-level C programming.  
- Thinking like both a machine and a human when writing algorithms.

---

## ⚡ Example

```bash
$ ./push_swap 2 1 3 6 5 8
sa ra pa pb ...
