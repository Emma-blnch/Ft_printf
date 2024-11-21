<h1 align="center"> 💻 <strong>Ft_printf</strong> </h1>

## 🏷️ **About the project**
> Because ft_putnbr() and ft_putstr() aren’t enough

This project is about recoding a simplified version of the printf function.

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
You can still see part of my code for the bonus, it can give you hints on how to do it. Just check `ft_check_flags_bonus.c`.

## 🧠 **New notions**
<p>If you have trouble understanding the subject fully and the new notions like variadic functions (`va_arg`, `va_list`, `va_start` and `va_end`), I highly recommand these:</p>
- https://www.youtube.com/watch?v=Hb2m7htiKWM
- https://42-cursus.gitbook.io/guide/rank-01/ft_printf

## ♻️ **Testing**
I strongly recommand you do your own main function to test your program. *You can check mine to see what it should look like*
Once you have your main test it with this command line:
> cc -Wall -Wextra -Werror *--all your .c functions:--* *.c main.c -o *executable_name*

If you want to make sure your program works, you can use third party testers like:
- https://github.com/xicodomingues/francinette
- https://github.com/Tripouille/printfTester
