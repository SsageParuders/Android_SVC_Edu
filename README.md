## Android_SVC_Edu

---
***Chinses README***

> 注释写的相对来说比较详细 可以参考注释进行理解<br>
> 这就是一个我学习svc调用的Demo 非常简单 易于理解

---

> This is a Demo for me to study Android SVC

### What's SVC

> When CPU find SVC instruction. It corms a interrupt.<br>
> Then will execute kernel logic first.<br>
> When we realize a function which SVC ,it is difficulte to use inline hook to hakc our function.<br>
> In a word, SVC is more secure than syscall which comes from libc

### SYSCALL

- SYSCALL is a define form [proot](https://github.com/proot-me/proot)

> WARN: The SYSCALL from proot is different from syscall from libc <br> 
> proot's SYSCALL use svc to get interrupt