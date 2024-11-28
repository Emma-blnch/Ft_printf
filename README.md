<h1 align="center"> 💻 <strong>Ft_printf</strong> </h1>

## 🏷️ **About the project**
> Because ft_putnbr() and ft_putstr() aren’t enough

This project is about recoding a simplified version of the printf function.

## 📥 **What I learned**
With this project, I learned how to have **clear names** for variables and functions.
I tried to name all my functions and variables so anyone could know their purpose *with one look*.

I also learned to **not repeat myself**. At first I had one more file because I separated the functions for `hexadecimal numbers` and for `pointers` but I realized it's the <ins>same logic</ins>! So it really taught me to be more **concise** and to check if I repeat myself.

## ⚙️ **Requirements**
The function must be written in C. It must compile with clang and the following flags :
- [x] -Wall
- [x] -Wextra
- [x] -Werror

## ➡️ **Difference with the original printf**
> Don't implement the buffer management of the original printf

We have to handle the following conversions: cspdiuxX% for our mandatory part.

## 📍 **Bonus**
What to do for the bonus part:
> - Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.
> - Manage all the following flags: ’# +’ (Yes, one of them is a space)

I started to do the bonus when my madatory part worked perfectly which is a **BIG** mistake. As stated in the subject :
> If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.

Doing the bonus meant re-doing all my functions so I gave up.
And since I understood the subject perfectly, I felt like I didn't need to do the bonus.

## 🧠 **New notions**
If you have trouble understanding the subject fully and the new notions like variadic functions (`va_arg`, `va_list`, `va_start` `va_end`), I highly recommand these:

- https://42-cursus.gitbook.io/guide/rank-01/ft_printf
- https://www.youtube.com/watch?v=Hb2m7htiKWM

It really helped me understand the subject better and the new notions.

## ♻️ **Testing**
I strongly recommand you do your own main function to test your program. *You can check mine to see what it should look like.*

Once you have your main, test it with this command line:
> cc -Wall -Wextra -Werror *--all your .c functions:--* *.c main.c -o *executable_name*

If you want to make sure your program works, you can use third party testers like:
- https://github.com/xicodomingues/francinette
- https://github.com/Tripouille/printfTester
